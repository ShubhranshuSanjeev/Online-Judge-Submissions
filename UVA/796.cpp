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

int N, timer;
vec1d(int) visited, tin, low;
vec2d(int) adj;
vec1d(pii) bridges;

void dfs(int u, int p){
    visited[u] = 1;
    tin[u] = low[u] = timer++;
    for(int v : adj[u]){
        if(v == p) continue;
        if(visited[v]){
            low[u] = min(low[u], tin[v]);
        }
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                int f = min(u, v);
                int s = max(u, v);
                bridges.emplace_back(f, s);
            }
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

    while(scanf("%d", &N) == 1){
        bridges.clear();
        adj.clear();
        visited.assign(N+1, 0);
        tin.assign(N+1, -1);
        low.assign(N+1, -1);
        adj.resize(N+1);

        int u, m, v;
        for(int i = 0; i < N; i++){
            scanf("%d (%d)", &u, &m);
            for(int j = 0; j < m; j++){
                scanf("%d", &v);
                adj[u].push_back(v);
            }
        }

        for(int i = 0; i < N; i++){
            if(!visited[i]){
                dfs(i, i);
            }
        }

        printf("%d critical links\n", (int)bridges.size());
        sort(bridges.begin(), bridges.end());
        for(const pii bridge : bridges){
            printf("%d - %d\n", bridge.first, bridge.second);
        }
        printf("\n");
    }
    return 0;
}