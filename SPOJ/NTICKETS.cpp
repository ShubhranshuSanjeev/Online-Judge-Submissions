#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdint>

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

const int MAX = 200007;
const int MAX2 = MAX << 2;
const int LOGN = 18;

vec2d(int) adj, cost;
vec2d(int) parent, MAX_COST;
vec1d(int) node_depth;

void solve(int u, int v){

    if(node_depth[u] < node_depth[v]){
        swap(u, v);
    }

    int log, ans = INT32_MIN;
    for(log = 0; (1<<log) <= node_depth[u]; log++);
    log--;

    for(int i = log; i >= 0; i--){
        if(node_depth[u]-node_depth[v] >= (1 << i)){
            ans = max(ans, MAX_COST[i][u]);
            u = parent[i][u];
        }
    }

    if(u == v){
        printf("%d\n", ans);
        return;
    }

    for(int i = log; i >= 0; i--){
        if(parent[i][u] != -1 && parent[i][u] != parent[i][v]){
            ans = max(ans, max(MAX_COST[i][u], MAX_COST[i][v]));
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    ans = max(ans, max(MAX_COST[0][u], MAX_COST[0][v]));
    printf("%d\n", ans);
}

void dfs(int u, int p = 0, int w = 0, int h = 0){
    parent[0][u] = p;
    MAX_COST[0][u] = w;
    node_depth[u] = h;

    FOR(i, 0, adj[u].size()){
        if(adj[u][i] != p){
            dfs(adj[u][i], u, cost[u][i], h+1);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    while(true){
        int N, Q;
        scanf("%d", &N);

        if(N == 0){
            break;
        }

        adj.clear();
        cost.clear();
        parent.clear();
        MAX_COST.clear();
        node_depth.clear();

        node_depth.resize(N+1);
        adj.resize(N+1, vec1d(int)());
        cost.resize(N+1, vec1d(int)());
        MAX_COST.resize(LOGN, vec1d(int)(N+1));
        parent.resize(LOGN, vec1d(int)(N+1, -1));

        FOR(i, 1, N){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);

            cost[u].emplace_back(w);
            cost[v].emplace_back(w);
        }

        dfs(1);
        for(int i = 1; (1 << i) <= N; i++){
            for(int j = 1; j <= N; j++){
                parent[i][j] = parent[i-1][parent[i-1][j]];
                MAX_COST[i][j] = max(MAX_COST[i-1][j], MAX_COST[i-1][parent[i-1][j]]);
            }
        }

        scanf("%d", &Q);
        FOR(i, 0, Q){
            int u, v;
            scanf("%d %d", &u, &v);
            solve(u, v);
        }
    }
    return 0;
}