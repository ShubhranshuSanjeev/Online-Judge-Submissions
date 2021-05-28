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
queue<int> q;
int in_degree[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    scanf("%d %d", &N, &M);
    FOR(i, 0, M){
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj_r[v].push_back(u);
        ++in_degree[v];
    }

    FOR(i, 1, N+1){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo_order;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        topo_order.push_back(u);
        for(int v: adj[u]){
            --in_degree[v];
            if(in_degree[v] == 0) q.push(v);
        }
    }

    bool has_cycle = false;
    FOR(i, 1, N+1){
        if(in_degree[i] != 0){
            has_cycle = true;
            printf("IMPOSSIBLE\n");
            break;
        }
    }

    if(!has_cycle){
        for(int node: topo_order){
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}