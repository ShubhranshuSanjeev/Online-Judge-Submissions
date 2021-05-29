#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 1000007
#define MAX2 (MAX<<2)

using namespace std;

struct Node{
    long long int sum;
    void createLeaf(){
        sum=0;
    }
    void merge(Node &a, Node &b){
        sum = a.sum+b.sum;
    }
};

Node nodes[MAX2];
long long int lazy[MAX2];
class Segtree{
public:
    long long int N;
    Segtree(int n){
        N = n;
        buildTree(0, n-1, 1);
    }
    void buildTree(long long int l, long long int h, long long int idx){
        if(l == h){
            nodes[idx].createLeaf();
            lazy[idx] = 0;
            return;
        }
        long long int mid = (l+h)>>1;
        buildTree(l, mid, idx<<1);
        buildTree(mid+1, h, idx<<1|1);
        nodes[idx].merge(nodes[idx<<1], nodes[idx<<1|1]);
        lazy[idx] = 0;
    }

    void propagate(long long int idx, long long int l, long long int h){
        if(lazy[idx]){
            nodes[idx].sum += (h-l+1)*lazy[idx];
            if(l!=h){
                lazy[idx<<1] += lazy[idx];
                lazy[idx<<1|1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(long long int l, long long int h, long long int ql, long long int qh, long long int idx, long long int val){
        propagate(idx, l, h);

        if(l > qh || h < ql || l > h) return;
        if(l>=ql && h<=qh){
            nodes[idx].sum += (h-l+1)*val;
            if(l!=h){
                lazy[idx<<1] += val;
                lazy[idx<<1|1] += val;
            }
            return;
        }
        long long int mid = (l+h)/2;
        update(l, mid, ql, qh, idx<<1, val);
        update(mid+1, h, ql, qh, idx<<1|1, val);
        nodes[idx].merge(nodes[idx<<1], nodes[idx<<1|1]);
    }

    Node query(long long int l, long long int h, long long int ql, long long int qh, long long int idx){
        propagate(idx, l, h);
        if(l > qh || h < ql || l > h) return ((Node){0});
        if(l >= ql && h <= qh) return nodes[idx];

        long long int mid = (l+h)/2;
        Node result, left, right;
        left = query(l, mid, ql, qh, idx<<1);
        right = query(mid+1, h, ql, qh, idx<<1|1);

        result.merge(left,right);
        return result;
    }
};

int main(){
    long long int t,n,c,w,x,y,z;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &n, &c);
        Segtree tree(n);
        for(int i = 0; i < c; i++){
            scanf("%lld", &w);
            if(!w){
                scanf("%lld %lld %lld", &x, &y, &z);
                tree.update(0, n-1, x-1, y-1, 1, z);
            }
            else{
                scanf("%lld %lld", &x, &y);
                Node ans;
                ans = tree.query(0, n-1, x-1, y-1, 1);
                printf("%lld\n", ans.sum);
            }
        }
    }
    return 0;
}
