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
int arr[MAX], seg_tree[MAX2];

void build_tree(int l, int h, int idx){
    if(l > h) return;
    if(l == h){
        seg_tree[idx] = arr[l];
        return;
    }

    int mid = (l + h) >> 1,
        lc = idx << 1,
        rc = lc | 1;

    build_tree(l, mid, lc);
    build_tree(mid+1, h, rc);

    seg_tree[idx] = seg_tree[lc] + seg_tree[rc];
}

void update_tree(int idx, int l, int h, int ql, int qh){
    if(l > qh || h < ql) return;
    if(l >= ql && h <= qh && l == h){
        seg_tree[idx] += l-ql+1;
        return;
    }

    int mid = (l + h) >> 1,
        lc = idx << 1,
        rc = lc | 1;

    update_tree(lc, l, mid, ql, qh);
    update_tree(rc, mid+1, h, ql, qh);

    seg_tree[idx] = seg_tree[lc] + seg_tree[rc];
}

int query_tree(int idx, int l, int h, int ql, int qh){
    if(l > qh || h < ql) return 0;
    if(l >= ql && h <= qh) return seg_tree[idx];

    int mid = (l + h) >> 1,
        lc = idx << 1,
        rc = lc | 1;

    return (
        query_tree(lc, l, mid, ql, qh)+
        query_tree(rc, mid+1, h, ql, qh)
    );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N >> Q;
    FOR(i, 0, N) cin >> arr[i];
    build_tree(0, N-1, 1);

    FOR(i, 0, Q){
        int t, a, b;
        cin >> t >> a >> b;
        --a; --b;
        if(t == 1){
            update_tree(1, 0, N-1, a, b);
        }
        else {
            cout << query_tree(1, 0, N-1, a, b) << "\n";
        }
    }
    return 0;
}