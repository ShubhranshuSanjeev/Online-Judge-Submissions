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
int N, M, K;
vector<pair<int, ll>> adj[MAX];
priority_queue<ll> k_shortest_dist[MAX];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
vector<ll> dist;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N >> M >> K;
    FOR(i, 0, M){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, (ll)c);
    }

    pq.emplace(0ll, 1);
    k_shortest_dist[1].push(0);
    while(!pq.empty()){
        auto curr = pq.top();
        int u = curr.second; ll c = curr.first;
        pq.pop();

        if(k_shortest_dist[u].size() == K && c > k_shortest_dist[u].top()) continue;

        for(auto next: adj[u]){
            int v = next.first;
            ll nc = next.second;

            if(k_shortest_dist[v].size() < K){
                k_shortest_dist[v].push(c+nc);
                pq.emplace(c+nc, v);
                continue;
            }

            if(k_shortest_dist[v].top() > (c+nc)){
                k_shortest_dist[v].pop();
                k_shortest_dist[v].push(c+nc);
                pq.emplace(c+nc, v);
            }
        }
    }

    vector<ll> ans;
    FOR(i, 0, K){
        ans.push_back(k_shortest_dist[N].top());
        k_shortest_dist[N].pop();
    }
    reverse(ans.begin(), ans.end());
    for(ll value: ans){
        cout << value << " ";
    }
    cout << "\n";
    return 0;
}