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
vector<int> adj[MAX];
int visited[MAX], color[MAX];
bool is_bipartite;

void dfs(int u, bool c = false){
    visited[u] = 1;
    color[u] = c;
    for(int v: adj[u]){
        if(visited[v]){
            if(color[v] == c){
                is_bipartite = false;
                break;
            }
        } else {
            dfs(v, !c);
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
    FOR(i, 0, M) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    is_bipartite = true;
    memset(visited, 0, sizeof(visited));
    FOR(i, 1, N+1){
        if(!visited[i]){
            dfs(i);
        }
    }
    if(!is_bipartite){
        cout << "IMPOSSIBLE\n";
    } else {
        FOR(i, 1, N+1) cout << (color[i]+1) << " ";
        cout << "\n";
    }
    return 0;
}