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

int timer;
vec2d(int) adj, added;
vec1d(int) visited, tin, low;
vec1d(pii) streets;

void dfs(int u, int p){
    visited[u] = 1;
    tin[u] = low[u] = timer++;
    for(int v : adj[u]){
        if(v == p) continue;
        if(visited[v]){
            low[u] = min(low[u], tin[v]);
            if(!added[u][v]){
                streets.emplace_back(u, v);
                added[u][v] = 1;
                added[v][u] = 1;
            }
        }
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                streets.emplace_back(u, v);
                streets.emplace_back(v, u);
            }
            else {
                streets.emplace_back(u, v);
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

    int N, M, T = 0;
    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0) break;

        adj.clear();
        streets.clear();
        visited.assign(N+1, 0);
        tin.assign(N+1, -1);
        low.assign(N+1, -1);
        added.assign(N+1, vec1d(int) (N+1, 0));
        adj.resize(N+1);

        int u, v;
        for(int i = 0; i < M; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0;
        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                dfs(i, i);
            }
        }

        cout << ++T << "\n\n";
        for(const pii street: streets){
            cout << street.first << " " << street.second << "\n";
        }
        cout << "#\n";
    }

    return 0;
}