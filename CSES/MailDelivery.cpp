#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
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

const int MAX = 100003;

int N, M, edge_count;
vector<pii> adj[MAX];
vector<int> euler_path;
int edge_used[2*MAX];

/* void dfs(int u){
    for(const pii &next: adj[u]){
        int v = next.first,
            e_idx = next.second;
        if(!edge_used[e_idx]){
            edge_used[e_idx] = 1;
            --edge_count;
            dfs(v);
        }
    }
    euler_path.push_back(u);
} */

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
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
        edge_used[i] = 0;
    }

    if(adj[1].size() == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    FOR(i, 1, N+1){
        if(adj[i].size() & 1){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    edge_count = M;
    stack<int> st; st.push(1);
    while(!st.empty()){
        int u = st.top(),
            f = 0;
        while(!adj[u].empty()){
            auto next = adj[u].back(); adj[u].pop_back();
            if(!edge_used[next.second]){
                st.push(next.first);
                edge_used[next.second] = f = 1;
                --edge_count;
                break;
            }
        }
        if(!f) {
            st.pop();
            euler_path.push_back(u);
        }
    }

    // dfs(1);

    bool not_eulerian = edge_count != 0;
    if(not_eulerian) cout << "IMPOSSIBLE\n";
    else {
        for(int node: euler_path){
            cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}