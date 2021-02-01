#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
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

int critical_points_cnt, timer;
vec1d(int) tin, low, visited, is_critical_point;
vec2d(int) adj;

void dfs(int u, int p = -1){
    visited[u] = 1;
    low[u] = tin[u] = ++timer;

    int children_cnt = 0;
    for(int v : adj[u]){
        if(v == p) continue;
        if(visited[v]){
            low[u] = min(low[u], tin[v]);
        }
        else {
            dfs(v, u);
            low[u] = min(low[v], low[u]);
            if( !is_critical_point[u] && low[v] >= tin[u] && p != -1 ){
                is_critical_point[u] = 1;
                critical_points_cnt++;
            }
            children_cnt++;
        }
    }

    if(p == -1 && children_cnt > 1){
        critical_points_cnt++;
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

    int N;
    while(true){
        cin >> N;
        if(N == 0)
            break;

        timer = critical_points_cnt = 0;
        adj.clear();
        adj.resize(N+1);
        visited.assign(N+1, 0);
        is_critical_point.assign(N+1, 0);
        tin.assign(N+1, -1);
        low.assign(N+1, -1);

        int u, v;
        while(true){
            cin >> u;
            if(u == 0)
                break;

            string to;
            getline(cin, to);
            stringstream ss(to);
            while(ss >> v){
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }
        }

        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        cout << critical_points_cnt << "\n";
    }

    return 0;
}