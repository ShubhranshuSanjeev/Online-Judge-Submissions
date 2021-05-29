#include<cstdio>
#include<algorithm>
#include<iostream>

#define MAX 100007
#define MAX2 (100007<<2)

using namespace std;

int arr[MAX];
struct Node{
    int maxNum, maxNum2;
    void createLeaf(int val){
        maxNum=val;
        maxNum2=-1;
    }
    void merge(Node &a, Node &b){
        if(a.maxNum > b.maxNum){
            maxNum = a.maxNum;
            maxNum2 = max(b.maxNum, max(a.maxNum2, b.maxNum2));
        }
        else{
            maxNum = b.maxNum;
            maxNum2 = max(a.maxNum, max(b.maxNum2, a.maxNum2));
        }
    }
};

Node tree[MAX2];

void buildTree(int l, int h, int idx){
    if(l > h) return;
    if(l == h){
        tree[idx].createLeaf(arr[l]);
        return;
    }
    int mid = (l+h)>>1;
    buildTree(l, mid, idx<<1);
    buildTree(mid+1, h, idx<<1|1);
    tree[idx].merge(tree[idx<<1], tree[idx<<1|1]);
}

void update(int l, int h, int idx, int ql, int qh, int x){
    if(l > h || l > qh || h < ql) return;
    if(l >= ql && h <= qh){
        tree[idx].maxNum = x;
        return;
    }
    int mid = (l+h)>>1;
    update(l, mid, idx<<1, ql, qh, x);
    update(mid+1, h, idx<<1|1, ql, qh, x);
    tree[idx].merge(tree[idx<<1], tree[idx<<1|1]);
}

Node query(int l, int h, int ql, int qh, int idx){
    if(l > h || l > qh || h < ql) return ((Node){-1,-1});
    if(l >= ql && h <= qh){
        return tree[idx];
    }
    int mid = (l+h)>>1;
    Node res,left,right;
    left = query(l, mid, ql, qh, idx<<1);
    right = query(mid+1, h, ql, qh, idx<<1|1);
    res.merge(left,right);
    return res;
}

int main(){
    int n,q,a,b,i;
    char c;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    buildTree(0, n-1, 1);
    scanf("%d", &q);
    Node ans;
    for(i = 0; i < q; i++){
        scanf(" %c", &c);
        scanf("%d %d", &a, &b);
        if(c == 'Q'){
            ans = query(0, n-1, a-1, b-1, 1);
            printf("%d\n", (ans.maxNum2+ans.maxNum));
        }
        else if(c == 'U'){
            update(0, n-1, 1, a-1, a-1, b);
        }
    }
    return 0;
}
