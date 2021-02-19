#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdint.h>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
using namespace std;

const int MAX = 100007;
const int MAX2 = MAX << 2;
const int LOGN = 17;

vec1d(int) adj[MAX], cost[MAX];
int node_depth[MAX], parent[LOGN][MAX];
int MAX_WT[LOGN][MAX], MIN_WT[LOGN][MAX];

void solve(int u, int v){
	int log, tmp;
    int max_ans = INT32_MIN;
    int min_ans = INT32_MAX;
	if(node_depth[u] < node_depth[v]){
		swap(u, v);
    }
 
	for(log = 0; (1 << log) <= node_depth[u]; log++);
	log--;
 
	for(int i = log; i >= 0; i--){
		if(node_depth[u]-node_depth[v] >= 1<<i){
            max_ans = max(max_ans, MAX_WT[i][u]);
            min_ans = min(min_ans, MIN_WT[i][u]);
			u = parent[i][u];
        }
    }
 
	if(u == v) {
        printf("%d %d\n", min_ans, max_ans);
        return;   
    }
 
	for(int i = log; i >= 0; i--){
		if(parent[i][u] != -1 && parent[i][u] != parent[i][v]){
			max_ans = max(max_ans, max(MAX_WT[i][u], MAX_WT[i][v]));
            min_ans = min(min_ans, min(MIN_WT[i][u], MIN_WT[i][v]));
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    max_ans = max(max_ans, max(MAX_WT[0][u], MAX_WT[0][v]));
    min_ans = min(min_ans, min(MIN_WT[0][u], MIN_WT[0][v]));
    printf("%d %d\n", min_ans, max_ans);
}

void dfs(int u, int p = 0, int wt = 0, int h = 0){
    parent[0][u] = p;
    node_depth[u] = h;
    MAX_WT[0][u] = MIN_WT[0][u] = wt;

    FOR(i, 0, adj[u].size()){
        int v = adj[u][i];
        if(v != p){
            dfs(v, u, cost[u][i], h+1);
        }   
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int N, K;
    scanf("%d", &N);
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < LOGN; j++) {
            parent[j][i] = -1;
        }
    }
    FOR(i, 1, N){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v);
        cost[u].emplace_back(w);

        adj[v].emplace_back(u);
        cost[v].emplace_back(w);
    }

    dfs(1);
    for(int i = 1; (1 << i) < N; i++){
        for(int j = 1; j <= N; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
            MAX_WT[i][j] = max(MAX_WT[i-1][j], MAX_WT[i-1][parent[i-1][j]]);
            MIN_WT[i][j] = min(MIN_WT[i-1][j], MIN_WT[i-1][parent[i-1][j]]);
        }
    }

    scanf("%d", &K);
    FOR(i, 0, K){
        int u, v;
        scanf("%d %d", &u, &v);
        if( u == v ){
            printf("0 0\n");
        }
        else{
            solve(u, v);
        }
    }
    return 0;
}