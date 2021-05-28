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

int N, M;
vector<int> adj[MAX];
vector<int> euler_path;
int in_degree[MAX], out_degree[MAX];

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
        adj[u].emplace_back(v);
        ++out_degree[u];++in_degree[v];
    }

    int cnt = 0, s = 0, e = 0;
    FOR(i, 1, N+1){
        if(in_degree[i] == out_degree[i]) ++cnt;
        else if(in_degree[i] == out_degree[i]+1) e = i;
        else if(in_degree[i]+1 == out_degree[i]) s = i;
    }

    if(cnt != (N-2) || s != 1 || e != N) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    stack<int> st; st.push(1);
    while(!st.empty()){
        int u = st.top();
        if(adj[u].empty()) {
            st.pop();
            euler_path.push_back(u);
            continue;
        }
        int next = adj[u].back();
        adj[u].pop_back();
        st.push(next);
    }

    if(euler_path.size() != M+1) cout << "IMPOSSIBLE\n";
    else {
        reverse(euler_path.begin(), euler_path.end());
        for(int node: euler_path){
            cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}