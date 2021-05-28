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
int parent[MAX], set_rank[MAX];
vector<tuple<ll, int, int>> edges;

int find_set(int u){
    if(parent[u] == u) return u;
    return parent[u] = find_set(parent[u]);
}

bool union_set(int u, int v){
    int pu = find_set(u);
    int pv = find_set(v);

    if(pu == pv) return false;
    if(set_rank[pu] < set_rank[pv]) swap(pu, pv);

    parent[pv] = pu;
    set_rank[pu] += set_rank[pv];
    return true;
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
    FOR(i, 1, N+1){
        parent[i] = i;
        set_rank[i] = 1;
    }

    FOR(i, 0, M){
        int u, v, c;
        cin >> u >> v >> c;
        edges.emplace_back((ll)c, u, v);
    }

    ll min_cost = 0;
    sort(edges.begin(), edges.end());
    for(auto edge: edges){
        int u = get<1>(edge),
            v = get<2>(edge);
        ll c = get<0>(edge);
        if(union_set(u, v)){
            min_cost += c;
        }
    }

    int c_count = 0;
    FOR(i, 1, N+1){
        if(parent[i] == i) ++c_count;
        if(c_count == 2) break;
    }

    if(c_count == 2) cout << "IMPOSSIBLE\n";
    else cout << min_cost << "\n";

    return 0;
}