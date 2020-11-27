#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 107
using namespace std;

int T, N, M;
vector<int> adj[MAX];
vector<pii> edges;
int deg[MAX], parent[MAX];

int find_set(int u){
    if(u == parent[u]) return parent[u];
    return (parent[u] = find_set(parent[u]));
}

void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);

    parent[v] = u;
    deg[u]++; deg[v]++;
}

int main(){
    int u, v;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);

        edges.clear();
        FOR(i, 0, N){
            adj[i].clear();
            deg[i] = 0;
            parent[i] = i;
        }

        FOR(i, 0, M){
            scanf("%d %d", &u, &v);
            --u; --v;
            edges.push_back(make_pair(u, v));
        }

        int edges_ignored = 0;
        FOR(i, 0, M){
            u = edges[i].first, v = edges[i].second;
            if(deg[u] || deg[v]){
                edges_ignored++;
                continue;
            }
            union_set(u, v);
        }
        bool ans = true;
        FOR(i, 0, N){
            if(find_set(i) == i && deg[i] != 1) {
                ans = false;
                break;
            }
        }

        if(ans && (edges_ignored > 0)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}