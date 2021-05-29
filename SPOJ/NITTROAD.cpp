#include <iostream>
#include <cstdio>
#include <vector>
#define N 20007

using namespace std;

typedef pair<int, pair<int,int>> edge;
typedef pair<char, int> query;
typedef long long ll;

int parent[N], ranks[N], components;
ll connectedPairs, disconnectedPairs;
edge edges[N];
query queries[N];

void init(int n){
    for(int i = 1; i <= n; i++) parent[i] = i, ranks[i] = 1;
    components = n;
    disconnectedPairs = n*(n-1)/2;
    connectedPairs = 0;
}

int find_set(int u) {
    return (u == parent[u] ? u : parent[u] = find_set(parent[u]));
}

void union_set(int u, int v, int e){
    u = find_set(u);
    v = find_set(v);

    if(u == v) return;

    if(ranks[v] > ranks[u]){
        int temp = u;
        u = v;
        v = temp;
    }

    if(e) connectedPairs += ranks[u]*ranks[v];
    else disconnectedPairs -= ranks[u]*ranks[v];
    parent[v] = u;
    ranks[u] += ranks[v];
}

int main(){
    int t, n, q, x, y, e;
    char type;
    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        for (int i = 0; i < n-1; i++) {
            scanf("%d %d", &edges[i].second.first, &edges[i].second.second);
            edges[i].first = 1;
        }

        scanf("%d", &q);
        for (int i = 0; i < q; i++){
            scanf(" %c", &type);
            queries[i].first = type;
            if(type == 'Q') {
                queries[i].second = 0;
            }
            else {
                scanf("%d", &x);
                edges[--x].first = 0;
                queries[i].second = x;
            }
        }

        init(n);
        for (int i = 0; i < n-1; i++){
            e = edges[i].first;
            x = edges[i].second.first; y = edges[i].second.second;
            if(e) {
                union_set(x, y, 1);
            }
        }

        disconnectedPairs -= connectedPairs;
        vector<ll> res;
        for(int i = q-1; i >= 0; i--){
            type = queries[i].first;
            e = queries[i].second;

            if(type == 'Q')
                res.push_back(disconnectedPairs);
            else{
                x = edges[e].second.first; y = edges[e].second.second;
                union_set(x, y, 0);
            }
        }

        for(int i = res.size()-1; i >= 0; i--)
            printf("%lld\n", res[i]);
        printf("\n");
    }
    return 0;
