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

const int MAX = 2507;

int N, M;
vector<tuple<int,int,int>> edges;
vector<ll> dist;
vector<int> prev_node;

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
        int u,v,c;
        cin >> u >> v >> c;
        edges.emplace_back(u, v, c);
    }

    dist.assign(N+1, 5e+12);
    prev_node.assign(N+1, -1);
    dist[1] = 0ll;

    int check = -1;
    FOR(i, 0, N){
        check = -1;
        for(auto edge: edges){
            int u = get<0>(edge),
                v = get<1>(edge),
                c = get<2>(edge);
            if(dist[u] < INT64_MAX){
                if(dist[v] > dist[u]+(ll)c){
                    dist[v] = dist[u]+(ll)c;
                    prev_node[v] = u;
                    check = v;
                }
            }
        }
    }

    if(check == -1) cout << "NO\n";
    else {
        int st = check;
        FOR(i, 0, N){
            st = prev_node[st];
        }

        vector<int> cycle;
        for(int cur = st;;cur = prev_node[cur]){
            cycle.push_back(cur);
            if(cur == st && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES\n";
        for(int node: cycle){
            cout << node << " ";
        }
        cout << "\n";
    }


    return 0;
}