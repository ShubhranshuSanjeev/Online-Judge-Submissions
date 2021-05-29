#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define MAX 50007
#define MAX2 (MAX<<3)

using namespace std;

int Arr[MAX];
struct Node{
    int sum,bestLeftSum,bestRightSum,bestSum;
    void merge(Node& A, Node& B){
        sum = A.sum + B.sum;
        bestLeftSum = max(A.bestLeftSum, A.sum+B.bestLeftSum);
        bestRightSum = max(B.bestRightSum, B.sum+A.bestRightSum);
        bestSum = max(max(A.bestSum, B.bestSum), A.bestRightSum+B.bestLeftSum);
    }
    void createLeaf(int v){
        sum=bestLeftSum=bestRightSum=bestSum=v;
    }
};
Node tree[MAX2];
void constructTree(int low, int high, int idx){
    if(low == high){
        tree[idx].createLeaf(Arr[low]);
        return;
    }

    int mid = low + (high-low)/2;
    constructTree(low, mid, 2*idx);
    constructTree(mid+1, high, 2*idx+1);
    tree[idx].merge(tree[2*idx], tree[2*idx+1]);
}

void query(Node& result, int low, int high, int qlow, int qhigh, int idx){
    if(low == qlow && high == qhigh){
        result = tree[idx];
        return;
    }
    if(low > qhigh || high < qlow){
        result.createLeaf(0);
        return;
    }
    int mid = low + (high-low)/2;
    if(mid >= qhigh) query(result, low, mid, qlow, qhigh, 2*idx);
    else if(mid < qlow) query(result, mid+1, high, qlow, qhigh, 2*idx+1);
    else{
        Node left;
        Node right;
        query(left, low, mid, qlow, mid, 2*idx);
        query(right, mid+1, high, mid+1, qhigh, 2*idx+1);
        result.merge(left,right);
    }
}

int main(){
    int t,n,m,a,b,c,d;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &Arr[i]);
        constructTree(0, n-1, 1);
        scanf("%d", &m);
        Node ans_1;
        Node ans_2;
        Node ans_3;
        Node ans_4;
        Node ans_5;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d %d", &a, &b, &c, &d);
            a--;
            b--;
            c--;
            d--;
            int ans;
            if(c > b){
                query(ans_1, 0, n-1, b+1, c-1, 1);
                query(ans_2, 0, n-1, a, b, 1);
                query(ans_3, 0, n-1, c, d, 1);
                ans=ans_1.sum+ans_2.bestRightSum+ans_3.bestLeftSum;
            }
            else{
                query(ans_1, 0, n-1, c, b, 1);
                query(ans_2, 0, n-1, a, c-1, 1);
                query(ans_3, 0, n-1, c, d, 1);
                query(ans_4, 0, n-1, a, b, 1);
                query(ans_5, 0, n-1, b+1, d, 1);
                ans = max(ans_1.bestSum, max(ans_2.bestRightSum+ans_3.bestLeftSum, ans_4.bestRightSum+ans_5.bestLeftSum));
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
