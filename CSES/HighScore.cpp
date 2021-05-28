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

const int MAX = 25003;

int N, M;
vector<int> adj_r[MAX], visited;
vector<tuple<int,int,int>> edges;
unordered_set<int> cycle_nodes;
vector<ll> dist;
bool has_cycle;

void dfs(int u){
    if(has_cycle || u == 1) return;
    if(cycle_nodes.find(u) != cycle_nodes.end()){
        has_cycle = true;
        return;
    }

    visited[u] = 1;
    for(int v: adj_r[u]){
        if(!visited[v]){
            dfs(v);
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

    cin >> N >> M;
    FOR(i, 0, M){
        int u, v, c;
        cin >> u >> v >> c;
        edges.emplace_back(u, v, -c);
        adj_r[v].push_back(u);
    }

    dist.assign(N+1, INT64_MAX);
    visited.assign(N+1, 0);
    dist[1] = 0ll;

    FOR(i, 0, N){
        for(auto edge: edges){
            int u = get<0>(edge),
                v = get<1>(edge),
                c = get<2>(edge);
            if(dist[u] < INT64_MAX){
                if(dist[v] > dist[u] + (ll)c){
                    dist[v] = dist[u] + (ll)c;
                    if(i == N-1) cycle_nodes.insert(v);
                }
            }
        }
    }
    has_cycle = false;
    dfs(N);
    if(has_cycle){
        cout << "-1\n";
    } else {
        cout << -dist[N] << "\n";
    }

    return 0;
}