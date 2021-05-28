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

const int MAX = 500007;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<ll>> graph(N, vector<ll>(N, INT64_MAX));
    FOR(i, 0, M){
        int u,v; ll c; cin >> u >> v >> c;
        --u; --v;
        c = min(graph[u][v], c);
        graph[u][v] = c;
        graph[v][u] = c;
    }

    vector<vector<ll>> dist(N, vector<ll>(N));
    FOR(i, 0, N){
        FOR(j, 0, N){
            if(i == j) graph[i][j] = 0;
            dist[i][j] = graph[i][j];
        }
    }

    FOR(k, 0, N){
        FOR(i, 0, N){
            FOR(j, 0, N){
                if(dist[i][j] > (dist[i][k]+dist[k][j]) && dist[i][k] != INT64_MAX && dist[k][j] != INT64_MAX){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    FOR(i, 0, Q){
        int u,v; cin >> u >> v;
        --u; --v;
        ll ans = dist[u][v];
        if(ans == INT64_MAX) cout << "-1\n";
        else cout << ans << "\n";
    }

    return 0;
}