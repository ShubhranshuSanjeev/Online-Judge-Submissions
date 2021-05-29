#include <cstdio>
#include <algorithm>
#include <functional>
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
vec2d(int) parent, MAX_WT;
vec1d(int) node_depth;
vector<pair<int, pair<int,int>>> edges;
vec1d(int) set_rep, set_rank;

int find_set(int u){
    if(u == set_rep[u]) return u;
    return u = find_set(set_rep[u]);
}

int union_set(int u, int v){
    int pu = find_set(u);
    int pv = find_set(v);

    if(pu == pv) return 0;
    if(set_rank[pu] < set_rank[pv]){
        swap(pu, pv);
    }

    set_rep[pv] = pu;
    set_rank[pu]++; 
    return 1;
}

void solve(int u, int v){
    if(node_depth[u] < node_depth[v]){
        swap(u, v);
    }

    int log, ans = INT32_MAX;
    for(log = 0; (1 << log) < node_depth[u]; log++);
    log--;

    for(int i = log; i >= 0; --i){
        if(node_depth[u]-node_depth[v] >= (1 << i)){
            ans = min(ans, MAX_WT[i][u]);
            u = parent[i][u];
        }
    }

    if(u == v){
        printf("%d\n", ans);
        return;
    }

    for(int i = log; i >= 0; i--){
        if(parent[i][u] != -1 && parent[i][v] != -1 && parent[i][u] != parent[i][v]){
            ans = min(ans, min(MAX_WT[i][u], MAX_WT[i][v]));
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    // printf("%d %d %d %d\n", u, v, MAX_WT[0][u], MAX_WT[0][v]);
    ans = min(ans, min(MAX_WT[0][u], MAX_WT[0][v]));
    printf("%d\n", ans);
}

void dfs(int u, int p = -1, int h = 0, int w = INT32_MAX){
    parent[0][u] = p;
    MAX_WT[0][u] = w;
    node_depth[u] = h;

    FOR(i, 0, adj[u].size()){
        if(adj[u][i] != p){
            dfs(adj[u][i], u, h+1, cost[u][i]);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int N, M, S;
    while(scanf("%d %d %d", &N, &M, &S) == 3){
        adj.clear();
        cost.clear();
        edges.clear();
        parent.clear();
        MAX_WT.clear();
        node_depth.clear();
        set_rep.clear();
        set_rank.clear();

        set_rep.resize(N+1);
        set_rank.resize(N+1);
        node_depth.resize(N+1);
        adj.assign(N+1, vec1d(int)());
        cost.assign(N+1, vec1d(int)());
        MAX_WT.assign(LOGN, vec1d(int)(N+1));
        parent.assign(LOGN, vec1d(int)(N+1, -1));
        
        FOR(i, 0, N+1){
            set_rep[i] = i;
            set_rank[i] = 1;
        }

        FOR(i, 0, M){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edges.emplace_back(w, make_pair(u, v));
            
        }
        sort(edges.begin(), edges.end(), greater<pair<int, pair<int,int>>>());

        for(auto edge: edges){
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;
            if(union_set(u, v)){
                // printf("%d %d %d\n", w, u, v);
                adj[u].emplace_back(v);
                cost[u].emplace_back(w);

                adj[v].emplace_back(u);
                cost[v].emplace_back(w);
            }
        }

        dfs(1);

        for(int i = 1; (1 << i) < N; i++){
            for(int j = 1; j <= N; j++){
                parent[i][j] = parent[i-1][parent[i-1][j]];
                MAX_WT[i][j] = min(MAX_WT[i-1][j], MAX_WT[i-1][parent[i-1][j]]);
            }
        } 


        FOR(i, 0, S){
            int u, v;
            scanf("%d %d", &u, &v);
            solve(u, v);
        }
    }
    return 0;
}