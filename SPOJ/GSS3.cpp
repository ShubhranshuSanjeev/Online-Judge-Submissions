#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 50007
#define MAX2 MAX<<3

using namespace std;
int arr[MAX];
struct node{
    int sum,bestSum,leftBestSum,rightBestSum;
    void merge(node &a, node &b){
        sum = a.sum + b.sum;
        bestSum = max(max(a.bestSum, b.bestSum), a.rightBestSum+b.leftBestSum);
        leftBestSum = max(a.leftBestSum, a.sum+b.leftBestSum);
        rightBestSum = max(b.rightBestSum, a.rightBestSum+b.sum);
    }
    void createLeaf(int v){
        sum=bestSum=leftBestSum=rightBestSum=v;
    }
};
node tree[MAX2];
void constructTree(int low, int high, int idx){
    if(low == high){
        tree[idx].createLeaf(arr[low]);
        return;
    }
    int mid = low + (high-low)/2;
    constructTree(low, mid, 2*idx+1);
    constructTree(mid+1, high, 2*idx+2);
    tree[idx].merge(tree[2*idx+1], tree[2*idx+2]);
}

void query(node &result, int l, int h, int ql, int qh, int idx){
    if(l==ql && h==qh){
        result=tree[idx];
        return;
    }
    int mid = l + (h-l)/2;
    if(mid >= qh) query(result, l, mid, ql, qh, 2*idx+1);
    else if(mid < ql) query(result, mid+1, h, ql, qh, 2*idx+2);
    else{
        node left;
        node right;
        query(left, l, mid, ql, mid, 2*idx+1);
        query(right, mid+1, h, mid+1, qh, 2*idx+2);
        result.merge(left, right);
    }
}

void update(int l, int h, int idx, int i, int v){
    if(l == h){
        tree[idx].bestSum=tree[idx].sum=tree[idx].leftBestSum=tree[idx].rightBestSum=v;
        return;
    }
    int mid = l + (h-l)/2;
    if(i <= mid) update(l, mid, 2*idx+1, i, v);
    else update(mid+1, h, 2*idx+2, i, v);
    tree[idx].merge(tree[2*idx+1], tree[2*idx+2]);
}

int main(){
    int n,m,i,a,b,c;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    constructTree(0, n-1, 0);
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0) update(0, n-1, 0, b-1, c);
        else if(a == 1){
            node res;
            query(res, 0, n-1, b-1, c-1, 0);
            cout << res.bestSum << "\n";
        }
    }
    return 0;
}
