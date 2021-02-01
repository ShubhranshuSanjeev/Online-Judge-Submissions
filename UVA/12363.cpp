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

const int MAX = 10007;
int timer;
vec2d(int) adj;
vec1d(int) visited, low, tin, tree_rank, parent;
vec1d(pii) bridges;

void find_bridges(int u, int p){
    visited[u] = 1;
    low[u] = tin[u] = timer++;

    for(int v : adj[u]){
        if(v == p) continue;
        if(visited[v]){
            low[u] = min(low[u], tin[v]);
        }
        else {
            find_bridges(v, u);
            low[u] = min(low[u], low[v]);
            if(tin[u] < low[v]){
                bridges.emplace_back(u, v);
            }
        }
    }
}

int find_parent(int u){
    if( parent[u] == u ) return u;
    return parent[u] = find_parent(parent[u]);
}

void union_set(int u, int v){
    int pu = find_parent(u);
    int pv = find_parent(v);

    if(pu == pv) return;

    if(tree_rank[pu] < tree_rank[pv]){
        swap(pu, pv);
    }

    parent[pv] = pu;
    tree_rank[pu] += tree_rank[pv];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    int R, C, Q;
    while(true){
        cin >> R >> C >> Q;
        if(R == 0 && C == 0 && Q == 0)
            break;

        timer = 0;
        bridges.clear();
        parent.resize(R+1);
        adj.assign(R+1, vec1d(int)());
        tree_rank.assign(R+1, 0);
        visited.assign(R+1, 0);
        tin.assign(R+1, -1);
        low.assign(R+1, -1);

        for(int i = 0; i <= R; i++){
            parent[i] = i;
        }

        int u, v;
        for(int i = 0; i < C; i++){
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for(int i = 1; i <= R; i++){
            if(!visited[i]){
                find_bridges(i, i);
            }
        }

        for(const pii bridge: bridges){
            union_set(bridge.first, bridge.second);
        }

        for(int i = 0; i < Q; i++){
            cin >> u >> v;
            cout << ( find_parent(u) == find_parent(v) ? "Y" : "N" ) << "\n";
        }
        cout << "-\n";
    }

    return 0;
}