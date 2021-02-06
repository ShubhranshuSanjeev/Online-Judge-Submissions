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
ll c, ans;
vec1d(ll) components;
vec2d(int) adj, radj;
vec1d(int) fun, visited;
vec1d(int) finished_nodes, rep, visited_c;

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
    c = c + fun[u];
    rep[u] = components.size();
    for(int v: radj[u]){
        if(!visited[v]){
            dfs2(v);
        }
    }
}

void dfs3(int u, ll total_fun, int e){
    total_fun += visited_c[rep[u]] ? 0 : components[rep[u]];
    visited[u] = 1;
    int flag = 0;
    if(!visited_c[rep[u]]){
        visited_c[rep[u]] = 1;
        flag = 1;
    }

    if(rep[u] == rep[e]){
        ans = max(total_fun, ans);
        visited[u] = 0;
        if(flag){
            visited_c[rep[u]] = 0;
        }
        flag = 0;
        return;
    }

    for(int v: adj[u]){
        if(!visited[v]){
            dfs3(v, total_fun, e);
        }
    }

    visited[u] = 0;
    if(flag){
        visited_c[rep[u]] = 0;
        flag = 0;
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

    int N, M, S, E;
    cin >> N >> M >> S >> E;

    adj.assign(N+1, vec1d(int)());
    radj.assign(N+1, vec1d(int)());
    visited.assign(N+1, 0);
    rep.assign(N+1, -1);

    fun.emplace_back(0);
    FOR(i, 0, N){
        int f; cin >> f;
        fun.emplace_back(f);
    }

    FOR(i, 0, M){
        int u,v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        radj[v].emplace_back(u);
    }

    FOR(i, 1, N+1){
        if(!visited[i]){
            dfs1(i);
        }
    }

    visited.assign(N+1, 0);
    FOR(i, 0, N){
        int u = finished_nodes[N-i-1];
        if(!visited[u]){
            c = 0;
            dfs2(u);
            components.emplace_back(c);
        }
    }

    ans = 0;
    visited.assign(N+1, 0);
    visited_c.assign(N+1, 0);
    dfs3(S, 0, E);
    cout << ans << "\n";
    return 0;
}