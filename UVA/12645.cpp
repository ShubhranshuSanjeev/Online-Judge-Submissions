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
vec1d(int) visited, finished_nodes, connected;

void dfs1(int u = 0){
    visited[u] = 1;
    connected[u] = 1;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
}

void dfs2(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs2(v);
        }
    }
    finished_nodes.emplace_back(u);
}

void dfs3(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs3(v);
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

    int N,M;

    while(scanf("%d %d", &N, &M) == 2){
        adj.assign(N+1, vec1d(int)());
        radj.assign(N+1, vec1d(int)());

        visited.assign(N+1, 0);
        connected.assign(N+1, 0);
        finished_nodes.clear();

        FOR(i, 0, M){
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].emplace_back(v);
            radj[v].emplace_back(u);
        }
        dfs1();

        visited.assign(N+1, 0);
        FOR(i, 0, N+1){
            if(!visited[i]){
                dfs2(i);
            }
        }

        visited.assign(N+1, 0);
        int ans = 0;
        FOR(i, 0, N+1){
            int u = finished_nodes[N-i];
            if(!visited[u]){
                dfs3(u);
                if(!connected[u]){
                    ans++;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}