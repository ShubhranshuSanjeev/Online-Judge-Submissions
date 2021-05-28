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

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for(int i = int(st); i != int(ed); i += step)
#define FOREACH(it, ds) for(auto it = ds.begin(); it != ds.end(); ++it)

using namespace std;

const int MAX = 100007;

int N, M;
vector<int> adj[MAX], adj_r[MAX];
vector<int> scc[MAX], components, order;
ll coins[MAX], parent[MAX], visited[MAX];
ll max_coins_collected, component_coins[MAX], dp[MAX];

void dfs(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u, int root){
    visited[u] = 1;
    parent[u] = root;
    component_coins[root] += coins[u];

    for(int v : adj_r[u]){
        if(!visited[v]){
            dfs2(v, root);
        }
    }
}

void dfs3(int u){
    visited[u] = 1;
    dp[u] += component_coins[u];

    ll max_coins = 0;
    for(int v: scc[u]){
        if(!visited[v]){
            dfs3(v);
        }
        max_coins = max(max_coins, dp[v]);
    }
    dp[u] += max_coins;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N >> M;
    FOR(i, 0, N) cin >> coins[i];
    FOR(i, 0, M) {
        int u,v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj_r[v].push_back(u);
    }

    memset(visited, 0, sizeof(visited));
    FOR(i, 0, N){
        if(!visited[i]){
            dfs(i);
        }
    }

    memset(visited, 0, sizeof(visited));
    FORS(i, order.size()-1, -1, -1){
        int u = order[i];
        if(!visited[u]){
            dfs2(u, u);
            components.push_back(u);
        }
    }

    FOR(u, 0, N){
        for(int v: adj[u]){
            int u_pa = parent[u],
                v_pa = parent[v];

            if(u_pa != v_pa){
                scc[u_pa].push_back(v_pa);
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    FOREACH(component, components){
        if(!visited[*component]){
            dfs3(*component);
            max_coins_collected = max(dp[*component], max_coins_collected);
        }
    }

    cout << max_coins_collected << "\n";
    return 0;
}