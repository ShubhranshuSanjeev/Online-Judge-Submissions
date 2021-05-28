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
int cycle_start, cycle_end;
vector<int> adj[MAX];
int parent[MAX], visited[MAX];

bool dfs(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(visited[v] == 0){
            parent[v] = u;
            if(dfs(v)) return true;
        } else if (visited[v] == 1){
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    visited[u] = 2;
    return false;
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
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    cycle_start = -1;

    FOR(i, 1, N+1){
        if(!visited[i] && dfs(i)){
            break;
        }
    }

    if(cycle_start == -1) cout << "IMPOSSIBLE\n";
    else {
        vector<int> nodes;
        nodes.push_back(cycle_start);
        int curr_node = cycle_end;
        while(curr_node != cycle_start){
            nodes.push_back(curr_node);
            curr_node = parent[curr_node];
        }
        nodes.push_back(cycle_start);

        reverse(nodes.begin(), nodes.end());
        cout << nodes.size() << "\n";
        for(int node: nodes){
            cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}