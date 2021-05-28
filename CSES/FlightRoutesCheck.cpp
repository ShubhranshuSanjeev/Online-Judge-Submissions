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

int N, M, c_idx;
vector<int> adj[MAX], adj_r[MAX], order;
int visited[MAX], component[MAX];

void dfs(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u){
    visited[u] = 1;
    component[u] = c_idx;
    for(int v: adj_r[u]){
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

    cin >> N >> M;
    FOR(i, 0, M){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj_r[v].push_back(u);
    }

    memset(visited, 0, sizeof(visited));
    FOR(i, 1, N+1){
        if(!visited[i]){
            dfs(i);
        }
    }

    c_idx = 0;
    memset(visited, 0, sizeof(visited));
    memset(component, -1, sizeof(component));
    FORS(i, order.size()-1, -1, -1){
        int next = order[i];
        if(!visited[next]){
            dfs2(next);
            ++c_idx;
        }
    }

    if(c_idx == 1) cout << "YES\n";
    else {
        cout << "NO\n";
        int a = -1, b = -1;
        FOR(i, 1, N+1){
            if(component[i] == 0 && a == -1) a = i;
            if(component[i] == 1 && b == -1) b = i;
            if(a != -1 && b != -1) break;
        }
        cout << b << " " << a << "\n";
    }


    return 0;
}