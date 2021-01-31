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

int N, M, timer, cnt;
vec1d(int) adj[MAX], tin, low, component_size;
vec1d(bool) visited;
vec2d(bool) is_bridge;

void dfs(int u, int p){
	visited[u] = true;
	tin[u] = low[u] = timer++;
	for(int v : adj[u]){
		if(v == p) continue;
		if(visited[v]){
			low[u] = min(low[u], tin[v]);
		}
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > tin[u]){
				is_bridge[u][v] = true;
				is_bridge[v][u] = true;
			}
		}
	}
}

void dfs2(int u, int p){
	visited[u] = true;
	cnt++;
	for(int v : adj[u]){
		if(v == p || is_bridge[u][v] || visited[v]) continue;
		dfs2(v, u);
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
    cin >> N >> M;

    timer = 0;
    is_bridge.assign(N+1, vec1d(bool) (N+1, false));
    visited.assign(N+1, false);
    tin.assign(N+1, -1);
    low.assign(N+1, -1);

    for(int i = 0; i < M; i++){
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    for(int i = 0; i < N; i++){
    	if(!visited[i]){
    		dfs(i, i);
    	}
    }

	cnt = 0;
	ll win_poss = 0;
	visited.assign(N+1, false);
	for(int i = 0; i < N; i++){
		if(!visited[i]){
			cnt = 0;
			dfs2(i, i);
			win_poss += (ll)cnt * (cnt-1)/2;
		}
	}

    ll total_poss = (ll)N * (N-1) / 2;
	double ans = 1.0 - (1.0*win_poss/total_poss);
    printf("%.5f\n", ans);

    return 0;
}
