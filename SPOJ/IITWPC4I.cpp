#include <cstdio>
#include <algorithm>
#define N 100111
#define M 200111
#define f first
#define s second
using namespace std;

typedef pair<int,pair<int,int>> edge;
typedef long long ll;


int parent[N], size[N], milkman[N], hasMilkman[N];
int n, m;
edge edges[M];

void init(){
    for(int i = 1; i <= n; i++) parent[i] = i, size[i] = 1, hasMilkman[i] = milkman[i];
}

int find_set(int u){
    return ( u == parent[u] ? u : parent[u] = find_set(parent[u]) );
}

int union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);

    if(u == v || (hasMilkman[u] && hasMilkman[v])) return 0;

    if(size[u] >= size[v]){
        parent[v] = u;
        size[u] += size[v];
        hasMilkman[u] = hasMilkman[u] || hasMilkman[v];
    } else {
        parent[u] = v;
        size[v] += size[u];
        hasMilkman[v] = hasMilkman[u] || hasMilkman[v];
    }
    return 1;
}

void inp(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &milkman[i]);
    for(int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].s.f, &edges[i].s.s, &edges[i].f);
}

int main(){
    int t, u, v, c;
    scanf("%d", &t);
    while(t--){
        inp();
        init();
        sort(edges, edges+m);

        ll total = 0;
        for(int i = 0; i < m; i++){
            u = edges[i].s.f, v = edges[i].s.s;
            c = edges[i].f;

            if(union_set(u,v)) total += c;
        }
        int flag = 1;
        for(int i = 1; i <= n; i++){
            int p = find_set(i);
            if(p == i && !hasMilkman[p]){
                printf("impossible\n");
                flag = 0;
                break;
            }
        }
        if(flag) printf("%lld\n", total);
    }
