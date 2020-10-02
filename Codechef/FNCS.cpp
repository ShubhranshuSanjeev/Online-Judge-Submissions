#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007
#define MAX2 (MAX << 2)

using namespace std;

int N, Q;
vector<pii> F;
ll A[MAX], B[MAX], seg_tree[MAX2], lazy[MAX2];
int *occ;

void propagate(int l, int h, int idx){
    if(lazy[idx] != 0){
        seg_tree[idx] += (h-l+1) * lazy[idx];
        if(l != h){
            lazy[idx << 1] += lazy[idx];
            lazy[idx << 1|1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void build_tree(int l, int h, int idx){
    if(l > h) return;
    if(l == h) {
        seg_tree[idx] = B[l];
        lazy[idx] = 0;
        return;
    }

    divide(l, h, idx);
    build_tree(l, mid, lc);
    build_tree(mid+1, h, rc);
    seg_tree[idx] = seg_tree[lc] + seg_tree[rc];
    lazy[idx] = 0;
}

ll query(int l, int h, int idx, int ql, int qh){
    propagate(l, h, idx);
    if(l > h || l > qh || h < ql) return 0;
    if(l >= ql && h <= qh) return seg_tree[idx];
    divide(l, h, idx);
    return (query(l, mid, lc, ql, qh) + query(mid+1, h, rc, ql, qh));
}

void update(int l, int h, int idx, int ql, int qh, int val){
    propagate(l, h, idx);
    if(l > h) return;
    if(l >= ql && h <= qh) {
        lazy[idx] = val;
        propagate(l, h, idx);
        return;
    }

    divide(l, h, idx);
    update(l, mid, lc, ql, qh, val);
    update(mid+1, h, rc, ql, qh, val);
    seg_tree[idx] = seg_tree[lc] + seg_tree[rc];
}

int main(){
    int li, ri, type, a, b;
    scanf("%d", &N);
    int K = (int) sqrt(N);
    int S[K+2], blocks[K+2][N+2];

    FOR(i, 0, N){
        scanf("%d", &A[i]);
        if(i > 0) A[i] += A[i-1];
    }
    int it_s = 0;
    FOR(i, 0, N){
        scanf("%d %d", &li, &ri);
        li--; ri--;
        F.push_back(make_pair(li, ri));
        B[i] = A[ri] - A[li-1];
        if(((i+1) % K) == 0) S[it_s++] = B[i];
    }

    int it = 0;
    FOR(i, 0, N){
        if(((i+1) % K) == 0) ++it;
        blocks[it][F[i].first] = 1;
        blocks[it][F[i].second+1] = -1;
    }

    FOR(i, 0, K){
        FOR(j, 1, N){
            blocks[i][j] += blocks[i][j-1];
        }
    }

    scanf("%d", &Q);
    while(Q--){
        scanf("%d %d %d", &type, &a, &b);
        --a; --b;
        if(type&1) {
            
        }
        else {
            int ans;
            if(((a+1) % K) == 1) ans = S[a/K];
            else ans = query(0, N-1, 1, a, (a/K + K - 1));

            int i = a/K + K;
            while(i+K <= b){
                ans += S[i/K];
                i += K;
            }

            if(i <= b) ans += query(0, N-1, 1, i, b);
            printf("%d\n", ans);
        }
    }




    return 0;
}