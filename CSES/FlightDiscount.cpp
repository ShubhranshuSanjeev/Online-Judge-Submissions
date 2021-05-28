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

struct Vertex_State{
    int v;
    ll cost;
    bool discount;

    Vertex_State(int a, ll b, bool c){
        v = a;
        cost = b;
        discount = c;
    }

    const bool operator<(const Vertex_State& other) const {
        if (discount == other.discount) {
            return cost > other.cost;
        }
        return discount > other.discount;
    }
};

int N, M;
vector<pair<int, ll>> adj[MAX];
priority_queue<Vertex_State> pq;
vector<vector<ll>> cost;

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
        int u, v; ll c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
    }

    cost.assign(N+1, vector<ll>(2, INT64_MAX));

    pq.emplace(1, 0, false);
    cost[1][false] = cost[1][true] = 0;

    while(!pq.empty()){
        Vertex_State curr_state = pq.top();
        pq.pop();

        if(curr_state.v == N && curr_state.discount){
            cout << curr_state.cost << "\n";
            break;
        }

        for(auto next: adj[curr_state.v]){
            int v = next.first;
            ll nc = next.second;

            if(cost[v][curr_state.discount] > curr_state.cost+nc){
                cost[v][curr_state.discount] = curr_state.cost+nc;
                pq.emplace(v, cost[v][curr_state.discount], curr_state.discount);
            }
            if(!curr_state.discount){
                if(cost[v][true] > curr_state.cost+(nc/2)){
                    cost[v][true] = curr_state.cost+(nc/2);
                    pq.emplace(v, cost[v][true], true);
                }
            }
        }
    }

    return 0;
}