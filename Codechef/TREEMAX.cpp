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

const int MAX = 100007;
const int MAX2 = MAX<<2;
int timer;
vec1d(int) adj[MAX], A;
vec1d(int) tin, tout, inv_tin, inv_tout,visited;
int tree[MAX2];

void build_tree(int l, int h, int idx){
    if(l == h){
        // cout << idx << " " << l << " " << tin[l] << " " << A[tin[l]] << "\n";
        tree[idx] = A[tin[l]];
        return;
    }
    // cout << idx << " " << l << " " << h << "\n";
    divide(l, h, idx);
    build_tree(l, mid, lc);
    build_tree(mid+1, h, rc);
    tree[idx] = max(tree[lc], tree[rc]);
}

void update_tree(int l, int h, int idx, int pos, int val){
    if(l > pos || h < pos) return;
    if(l == h && l == pos){
        tree[idx] = val;
        return;
    }
    // cout << l << " " << h << " " << idx << " " << pos << " " << val << "\n";
    divide(l, h, idx);
    update_tree(l, mid, lc, pos, val);
    update_tree(mid+1, h, rc, pos, val);
    tree[idx] = max(tree[lc], tree[rc]);
}

int query_tree(int l, int h, int idx, int ql, int qh){
    if(l > h || l > qh || h < ql) return 0;
    if(l >= ql && h <= qh) return tree[idx];
    divide(l, h, idx);
    // cout << l << " " << h << " " << idx << " " << ql << " " << qh << "\n";
    if(mid >= qh) {
        return query_tree(l, mid, lc, ql, qh);
    }
    else if (mid < ql) {
        return query_tree(mid+1, h, rc, ql, qh);
    }
    else {
        return max(query_tree(l, mid, lc, ql, qh), query_tree(mid+1, h, rc, ql, qh));
    }
}

void dfs(int u){
    visited[u] = 1;
    tin[timer] = u;
    inv_tin[u] = timer++;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    tout[timer] = u;
    inv_tout[u] = timer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T, N, Q;
    cin >> T;

    while(T--){
        cin >> N >> Q;

        timer = 0;
        A.clear();
        tin.assign(N+1, -1);
        tout.assign(N+1, -1);
        inv_tin.assign(N+1, -1);
        inv_tout.assign(N+1, -1);
        visited.assign(N+1, 0);
        memset(tree, 0, sizeof(tree));
        FOR(i, 0, N){
            adj[i].clear();
        }

        FOR(i, 0, N){
            int a; cin >> a;
            A.push_back(a);
        }

        FOR(i, 1, N){
            int u, v;
            cin >> u >> v;
            --u;--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
        build_tree(0, timer-1, 1);
        // for(int i = 0; i < timer<<1; i++){
        //     cout << i << " " << tree[i] << "\n";
        // }
        FOR(i, 0, Q){
            int type; cin >> type;
            --type;
            if(type){
                int u;
                cin >> u;
                --u;
                int ans = query_tree(0, timer-1, 1, inv_tin[u], inv_tout[u]-1);
                cout << ans << "\n";
            }
            else {
                int u, x;
                cin >> u >> x;
                --u;
                // cout << "UPDATE: " << u << " " << x << " " << inv_tin[u] << "\n";
                update_tree(0, timer-1, 1, inv_tin[u], x);
            }
        }
    }

    return 0;
}