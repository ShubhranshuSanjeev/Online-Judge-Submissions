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

int N, M, cycle_start, cycle_end;
vector<int> adj[MAX];
int visited[MAX], parent[MAX];

bool dfs(int u, int prev){
    visited[u] = true;
    for(int v: adj[u]){
        if(v == prev) continue;
        if(visited[v]){
            cycle_start = v;
            cycle_end = u;
            return true;
        }
        parent[v] = u;
        if(dfs(v, u)) return true;
    }
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
        adj[v].push_back(u);
    }

    cycle_start = cycle_end = -1;
    FOR(i, 1, N+1){
        if(!visited[i] && dfs(i, i))
            break;
    }

    if(cycle_start == -1) cout << "IMPOSSIBLE\n";
    else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for(int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        cout << cycle.size() << "\n";
        for(int u: cycle) cout << u << " ";
        cout << "\n";
    }
    return 0;
}