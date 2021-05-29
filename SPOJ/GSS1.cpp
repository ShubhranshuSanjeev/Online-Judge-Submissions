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
    int n,m,ql,qh;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &Arr[i]);
    constructTree(0, n-1, 1);
    scanf("%d", &m);
    Node ans;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &ql, &qh);
        query(ans, 0, n-1, ql-1, qh-1, 1);
        cout << ans.bestSum << "\n";
    }
    return 0;
}
