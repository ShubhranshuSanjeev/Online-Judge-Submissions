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

const int MAX = 200007;

int N, Q;
int to[MAX], chain[MAX], chain_rank[MAX];
int cycle[MAX], visited[MAX], indegree[MAX];
bool is_cycle, chain_idx;

void dfs(int u, int d=0){
    if(visited[u]){

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

    cin >> N >> Q;
    FOR(i, 1, N+1){
        cin >> to[i];
        ++indegree[to[i]];
    }

    vector<int> st_nodes;
    FOR(i, 1, N+1){
        if(!indegree[i]) st_nodes.push_back(i);
    }

    for(int node: st_nodes){
        dfs(node);
    }

    return 0;
}