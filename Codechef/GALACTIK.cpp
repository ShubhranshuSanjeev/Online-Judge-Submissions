#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define N 100007

using namespace std;

int parent[N], ranks[N], costs[N], minInComponent[N], components;
vector<pair<int,int>> edges;

void init(int n){
    for(int i = 1; i <= n; i++) parent[i] = i, ranks[i] = i, minInComponent[i] = costs[i];
    components = n;
}

int findSet(int u){
    if(parent[u] == u) return u;
    return (parent[u] = findSet(parent[u]));
}

void unionSet(int u, int v){
    u = findSet(u);
    v = findSet(v);

    if(u == v) return;
    if(ranks[v] > ranks[u]){
        int temp = u;
        u = v;
        v = temp;
    }
    parent[v] = u;
    ranks[u] += ranks[u] == ranks[v] ? 1 : 0;
    minInComponent[u] = min(minInComponent[u], minInComponent[v]);
    --components;
}

int main(){
    int n,m,a,b,c,u,v,i;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        edges.push_back(make_pair(a, b));
    }
    for(i = 1; i <= n; i++) {
        scanf("%d", &c);
        costs[i] = c < 0 ? INT32_MAX : c;
    }
    init(n);

    for(i = 0; i < m; i++) {
        u = edges[i].first, v = edges[i].second;
        unionSet(u,v);
    }

    if(components == 1) printf("0\n");
    else {
        long long int total = 0, lowestCost = INT64_MAX;
        for(i = 1; i <= n; i++){
            int p = findSet(i);
            if(minInComponent[p] == INT32_MAX){
                printf("-1\n");
                return 0;
            }
            if(p == i) total += minInComponent[p];
            if(p == i && lowestCost > minInComponent[p]) lowestCost = minInComponent[p];
        }
        long long int ans = total + lowestCost*(components-1) - lowestCost;
        printf("%lld\n", ans);
    }
    return 0;
}
