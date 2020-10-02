#include <cstdio>
//#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int
#define FOR(st, ed) for(ll i = st; i < ed; i++)
#define FOR2(st, ed) for(ll j = st; j < ed; j++)
#define pii pair<int,int>
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 200007
using namespace std;

int N, M;
int A[MAX], lb_i[MAX], ub_i[MAX];
ll inv_count = 0;

struct Node{
    int *arr, *lb, *rb;
    int len;

    void init(int l){
        len = l;
        arr = new int[l+2];
        lb = new int[l+2];
        rb = new int[l+2];
    }

    void merge(Node a, Node b) const{
        int i = 0, j = 0, k = 0;
        while(i < a.len && j < b.len){
            if(a.arr[i] <= b.arr[j]) arr[k++] = a.arr[i++];
            else {
                arr[k++] = b.arr[j++];
                inv_count += a.len-i;
            }
        }
        while(i < a.len) arr[k++] = a.arr[i++];
        while(j < b.len) arr[k++] = b.arr[j++];
    }

    void cascade(Node a, int isLeft, int idx){
        int i = 0, j = 0;
        while(i < len){
            while(a.arr[j] < arr[i] && j < a.len) j++;
            if(isLeft) lb[i] = j;
            else rb[i] = j;
            i++;
        }
        if(isLeft) lb[i] = a.len;
        else rb[i] = a.len;
    }
};

class SegmentTree{
private:
    vector<Node> tree;
    int size;

    void build(int l, int h, int idx){
        if(l > h) return;
        if(l == h){
            tree[idx].init(1);
            tree[idx].arr[0] = A[l];
            return;
        }

        divide(l, h, idx);
        build(l, mid, lc);
        build(mid+1, h, rc);

        tree[idx].init(h-l+1);
        tree[idx].merge(tree[lc], tree[rc]);

        tree[idx].cascade(tree[lc], 1, idx);
        tree[idx].cascade(tree[rc], 0, idx);
    }

    int query(int l, int h, int idx, int ql, int qh, int lb_t, int ub_t, int type){
        if(l > h || l > qh || h < ql) return 0;
        if(l >= ql && h <= qh) {
            int a = tree[idx].len - ub_t;
            return type ? (a-lb_t) : (lb_t-a);
        }

        divide(l, h, idx);
        return (
                query(l, mid, lc, ql, qh, tree[idx].lb[lb_t], tree[idx].lb[ub_t], type)
                +  query(mid+1, h, rc, ql, qh, tree[idx].rb[lb_t], tree[idx].rb[ub_t], type)
                );
    }

public:
    SegmentTree(int size){
        this->size = size;
        tree.resize(size << 2);
        build(0, size-1, 1);
    }

    int query(int ql, int qh, int lb_t, int ub_t, int type){
        return query(0, size-1, 1, ql, qh, lb_t, ub_t, type);
    }

    int get_lb(int k){
        return lower_bound(tree[1].arr, tree[1].arr+tree[1].len, k) - tree[1].arr;
    }

    int get_ub(int k){
        return upper_bound(tree[1].arr, tree[1].arr+tree[1].len, k) - tree[1].arr;
    }
};

int main(){
    int a, b;
    scanf("%d %d", &N, &M);
    FOR(0, N){
        scanf("%d", &A[i]);
    }

    SegmentTree seg_t(N);
    FOR(0, N){
        lb_i[i] = seg_t.get_lb(A[i]);
        ub_i[i] = seg_t.get_ub(A[i]);
    }

    while(M--){
        scanf("%d %d", &a, &b);
        a--; b--;
        if(a == b || A[a] == A[b]){
            printf("%lld\n", inv_count);
            continue;
        }

        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }

        ll x = seg_t.query(a+1, b-1, lb_i[a], ub_i[a], 1);
        ll y = seg_t.query(a+1, b-1, lb_i[b], ub_i[b], 0);
        ll ans = inv_count + x + y;
        ans += A[a] < A[b] ? 1 : -1;
        printf("%lld\n", ans);
    }
    return 0;
}