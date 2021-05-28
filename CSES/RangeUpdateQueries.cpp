#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <bitset>
#include <unordered_set>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define ivec1d(x, n, v) vec1d(x)(n, v)
#define ivec2d(x, n, m, v) vec2d(x)(n, ivec1d(x, m, v))
#define ivec3d(x, n, m, k, v) vec3d(x)(n, ivec2d(x, m, k, v))
#define ivec4d(x, n, m, k, l, v) vec4d(x)(n, ivec3d(x, m, k, l, v))

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
using namespace std;

const int MAX = 200007;
const int MAX2 = MAX << 2;
int N, Q;
ll arr[MAX], lazy_tree[MAX2], seg_tree[MAX2];

void propagate(int l, int h, int idx){
    if(lazy_tree[idx] != 0){
        seg_tree[idx] += lazy_tree[idx];
        if(l != h){
            lazy_tree[idx<<1] += lazy_tree[idx];
            lazy_tree[idx<<1|1] += lazy_tree[idx];
        }

        lazy_tree[idx] = 0;
    }
}

void update_tree(int idx, int l, int h, int ql, int qh, int v){
    propagate(l, h, idx);

    if(l > qh || h < ql) return;
    if(l >= ql && h <= qh){
        seg_tree[idx] += v;
        if(l != h) {
            lazy_tree[idx << 1] += v;
            lazy_tree[idx << 1 | 1] += v;
        }
        return;
    }

    int mid = (l + h) >> 1,
        lc = idx << 1,
        rc = lc | 1;
    
    update_tree(lc, l, mid, ql, qh, v);
    update_tree(rc, mid+1, h, ql, qh, v);

    seg_tree[idx] += seg_tree[lc] + seg_tree[rc];
}

ll query_tree(int idx, int l, int h, int p){
    propagate(l, h, idx);
    if(l == h && h == p) return seg_tree[idx];

    int mid = (l + h) >> 1,
        lc = idx << 1,
        rc = lc | 1;

    if (mid >= p) return query_tree(lc, l, mid, p);
    return query_tree(rc, mid+1, h, p);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    memset(seg_tree, 0, sizeof(seg_tree));
    memset(lazy_tree, 0, sizeof(lazy_tree));

    cin >> N >> Q;
    FOR(i, 0, N) cin >> arr[i];
    FOR(i, 0, Q) {
        int q_type, l, h, u;  
        
        cin >> q_type;
        --q_type;

        if(q_type){
           cin >> u; --u;
           cout << (arr[u] + query_tree(1, 0, N, u)) << "\n";
        }
        else {
            cin >> l >> h >> u;
            --l; --h;
            update_tree(1, 0, N, l, h, u);
        }
    }
    return 0;
}