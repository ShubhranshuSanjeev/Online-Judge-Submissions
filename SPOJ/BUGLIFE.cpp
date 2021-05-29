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

const int MAX = 2007;

int N, M, component_cnt;
vector<int> adj[MAX], adj_r[MAX];
vector<int> trav_order;
int component[MAX], visited[MAX];

void dfs(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    trav_order.push_back(u);
}

void dfs2(int u){
    visited[u] = 1;
    component[u] = component_cnt;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs2(v);
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

    int T; cin >> T;
    FOR(t, 1, T+1){
        cin >> N >> M;

        component_cnt = 0;
        memset(component, -1, sizeof(component));
        memset(visited, 0, sizeof(visited));
        trav_order.clear();
        FOR(i, 0, 2*N+1) {
            adj[i].clear();
            adj_r[i].clear();
        }

        FOR(i, 0, M){
            int u, v; cin >> u >> v;
            int not_u = 2*N-u+1;
            int not_v = 2*N-v+1;

            adj[u].push_back(not_v);
            adj[not_v].push_back(u);

            adj[v].push_back(not_u);
            adj[not_u].push_back(v);
        }

        FOR(i, 1, 2*N+1){
            if(!visited[i]){
                dfs(i);
            }
        }

        memset(visited, 0, sizeof(visited));
        FORS(i, trav_order.size()-1, -1, -1){
            int next = trav_order[i];
            if(!visited[next]){
                dfs2(next);
                ++component_cnt;
            }
        }

        cout << "Scenario #" << t << ":\n";
        bool suspicious = false;
        FOR(i, 1, N+1){
            if(component[i] == component[2*N-i+1]){
                cout << "Suspicious bugs found!\n";
                suspicious = true;
                break;
            }
        }

        if(!suspicious) cout << "No suspicious bugs found!\n";
    }
    return 0;
}