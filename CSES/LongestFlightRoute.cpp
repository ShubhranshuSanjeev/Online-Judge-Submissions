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
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int city_count[MAX], prev_noode[MAX];

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
    }

    memset(city_count, -1, sizeof(city_count));
    city_count[1] = 0;
    pq.emplace(0, 1);
    while(!pq.empty()){
        auto curr = pq.top();
        int u = curr.second,
            c = curr.first;
        pq.pop();
        if(city_count[u] > c) continue;

        for(int v: adj[u]){
            if(city_count[v] == -1 || city_count[v] < (c+1)){
                city_count[v] = c+1;
                pq.emplace(c+1, v);
                prev_noode[v] = u;
            }
        }
    }

    if(city_count[N] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    int curr_node = N;
    while(curr_node != 0){
        path.push_back(curr_node);
        curr_node = prev_noode[curr_node];
    }

    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for(int node: path){
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}