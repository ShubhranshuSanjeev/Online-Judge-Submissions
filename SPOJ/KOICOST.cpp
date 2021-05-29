#include <cstdio>
#include <iostream>
#include <algorithm>

#define N 100111
#define mod 1000000000
#define f first
#define s second

using namespace std;

typedef pair<int, pair<int,int>> edge;
typedef long long ll;

int parent[N], size[N];
int pairs, total;
edge edges[N];

void init(int n){
    for(int i = 1; i <= n; i++)
        parent[i] = i, size[i] = 1;
    pairs = 0;
    total = 0;
}

int find_set(int u){
    return (u == parent[u] ? u : parent[u] = find_set(parent[u]));
}

void union_set(int u, int v, int c){
    u = find_set(u);
    v = find_set(v);

    if(u != v) {
        pairs = (pairs + (1LL * size[v] * size[u]) % mod) % mod;
        if(size[u] >= size[v]){
            parent[v] = u;
            size[u] += size[v];
        } else {
            parent[u] = v;
            size[v] += size[u];
        }
    }
    total = (total + (1LL * pairs * c) % mod) % mod;
}

int main(){
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].f = w;
        edges[i].s.f = u, edges[i].s.s = v;
    }

    sort(edges, edges+m);
    reverse(edges, edges+m);
    init(n);

    for (int i = 0; i < m; i++) {
        w = edges[i].f;
        u = edges[i].s.f, v = edges[i].s.s;
        union_set(u,v,w);
    }
    printf("%d\n", total%mod);
    return 0;
}
