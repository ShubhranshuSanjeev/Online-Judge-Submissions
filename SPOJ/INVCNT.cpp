#include<cstdio>
#include<iostream>
#include<cstring>

#define MAX 10000007
#define MAX2 (10000007<<2)

using namespace std;
int arr[MAX];
long long int tree[MAX2];

long long int query(int l, int h, int ql, int qh, int idx){
    if(l > h || l > qh || h < ql) return 0;
    if(l >= ql && h <= qh) return tree[idx];
    int mid = (l+h)>>1;
    long long int left = query(l, mid, ql, qh, idx<<1);
    long long int right = query(mid+1, h, ql, qh, idx<<1|1);
    return (left+right);
}

void update(int l, int h, int i, int idx){
    if(l > h || l > i || h < i) return;
    if(l == i && h == i ){
        tree[idx] = 1;
        return;
    }
    int mid = (l+h)>>1;
    update(l, mid, i, idx<<1);
    update(mid+1, h, i, idx<<1|1);
    tree[idx] = tree[idx<<1] + tree[idx<<1|1];
}

int main(){
    int t,n,i,a;
    scanf("%d", &t);
    while(t--){
        memset(tree, 0, MAX2);
        scanf("%d", &n);
        int temp[n];
        int maxEle = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &temp[i]);
            if(maxEle < temp[i]) maxEle = temp[i];
        }
        long long int ans = 0;
        for(i = 0; i < n; i++){
            ans += query(0, maxEle, temp[i]+1, maxEle, 1);
            update(0, maxEle, temp[i], 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
