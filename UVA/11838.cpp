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
vec2d(int) adj, radj;
vec1d(int) visited, finished_nodes;
int scc_cnt;

void dfs1(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    finished_nodes.emplace_back(u);
}

void dfs2(int u){
    visited[u] = 1;
    for(int v : radj[u]){
        if(!visited[v]){
            dfs2(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int N, M;
    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0)
            break;

        adj.assign(N+1, vec1d(int)());
        radj.assign(N+1, vec1d(int)());
        visited.assign(N+1, 0);
        finished_nodes.clear();

        int u, v, type;
        FOR(i, 0, M){
            cin >> u >> v >> type;
            adj[u].emplace_back(v);
            radj[v].emplace_back(u);

            if(type == 2){
                adj[v].emplace_back(u);
                radj[u].emplace_back(v);
            }
        }

        FOR(i, 1, N+1){
            if(!visited[i]){
                dfs1(i);
            }
        }

        scc_cnt = 0;
        visited.assign(N+1, 0);
        FOR(i, 0, N){
            u = finished_nodes[N-i-1];
            if(!visited[u]){
                scc_cnt++;
                dfs2(u);
            }
        }

        cout << (scc_cnt == 1) << "\n";
    }

    return 0;
}