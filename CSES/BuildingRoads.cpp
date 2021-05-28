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
int N,M;
vector<int> adj[MAX];
int visited[MAX];

void dfs(int u){
    visited[u] = 1;
    for(int v: adj[u])
        if(!visited[v])
            dfs(v);
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
    int components = 0;
    vector<int> cities;
    FOR(i, 1, N+1){
        if(!visited[i]){
            dfs(i);
            cities.push_back(i);
            ++components;
        }
    }
    cout << (components-1) << "\n";
    FOR(i, 0, components-1){
        cout << cities[i] << " " << cities[i+1] << "\n";
    }
    return 0;
}