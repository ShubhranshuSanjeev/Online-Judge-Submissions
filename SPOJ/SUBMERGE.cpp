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

vec2d(int) adj;
vec1d(int) low, tin, visited, checked;
int timer, articulation_points_cnt;

void find_articulation_points(int u, int p = -1){
    visited[u] = 1;
    low[u] = tin[u] = timer++;

    int children_cnt = 0;
    for(int v : adj[u]){
        if(v == p)
            continue;
        if(visited[v]){
            low[u] = min(low[u], tin[v]);
        }
        else {
            find_articulation_points(v, u);
            low[u] = min(low[u], low[v]);
            if(p != -1 && low[v] >= tin[u] && !checked[u]){
                checked[u] = 1;
                articulation_points_cnt++;
            }
            children_cnt++;
        }
    }

    if(p == -1 && children_cnt > 1){
        articulation_points_cnt++;
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
        low.assign(N+1, -1);
        tin.assign(N+1, -1);
        visited.assign(N+1, 0);
        checked.assign(N+1, 0);
        timer = articulation_points_cnt = 0;

        FOR(i, 0, M){
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        find_articulation_points(1);

        cout << articulation_points_cnt << "\n";
    }
    return 0;
}