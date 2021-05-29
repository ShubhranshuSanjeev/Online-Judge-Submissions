#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define N 100111

using namespace std;

struct edge{
    int a, b, c;
    edge(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int parent[N];
long long int ranks[N], S, T;
double c_mst;
vector<edge*> edges;



bool compareCost(edge* e, edge* f){
    return e->c < f->c;
}

void init(int n){
    for(int i = 1; i <= n; i++) parent[i] = i, ranks[i] = 1;
    c_mst = 0;
    S = T = 0;
}

int find_set(int u){
    return (parent[u] == u ? u : parent[u] = find_set(parent[u]));
}

void union_set(int u, int v, int c){
    u = find_set(u);
    v = find_set(v);

    if(ranks[v] > ranks[u]){
        int temp = u;
        u = v;
        v = temp;
    }

    S += ranks[u]*ranks[v]*c;
    T += ranks[u]*ranks[v];
    c_mst += c;

    parent[v] = u;
    ranks[u] += ranks[v];
}

int main(){
    int n,u,v,c,i;
    scanf("%d", &n);
    for(i = 1; i < n; i++){
        scanf("%d %d %d", &u, &v, &c);
        edges.push_back(new edge(u,v,c));
    }
    init(n);
    sort(edges.begin(), edges.end(), compareCost);
    for(i = 0; i < edges.size(); i++){
        u = edges[i]->a; v = edges[i]->b; c = edges[i]->c;
        union_set(u,v,c);
    }

    printf("%.11f\n", (c_mst - (double)S/T));
}

