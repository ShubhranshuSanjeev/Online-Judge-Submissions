#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 10111

using namespace std;
typedef pair<int, pair<int,int>> edge;
typedef long long ll;

int parent[N], size[N];
vector<edge> edges;

void init(int n){
    for(int i = 1; i <= n; i++) parent[i] = i, size[i] = 1;
    edges.clear();
}

int find_set(int u){
    return (u == parent[u] ? u : parent[u] = find_set(parent[u]));
}

int union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);

    if(u == v) return 0;
    if(size[v] > size[u]){
        parent[u] = v;
        size[v] += size[u];
    } else {
        parent[v] = u;
        size[u] += size[v];
    }
    return 1;
}

int main(){
    int t, n, p, u, v, c;
    char name[13];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        init(n);
        for(int i = 1; i <= n; i++){
            scanf(" %s", name);
            scanf("%d", &p);
            u = i;
            for(int j = 0; j < p; j++){
                scanf("%d %d", &v, &c);
                edges.push_back(make_pair(c, make_pair(u,v)));
            }
        }
        sort(edges.begin(), edges.end());
        ll total = 0;
        for(auto & edge : edges){
            u = edge.second.first; v = edge.second.second;
            c = edge.first;

            if(union_set(u,v)) total += c;
        }

        printf("%lld\n", total);
    }
    return 0;
