#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1
#define MAX 100007
using namespace std;

int N, all_leaf = 0, leaf_count = 0;
vector<int> adj[MAX];
int sz[MAX], height[MAX];
int visited[MAX];

void dfs(int u, int prev = -1){
    sz[u] = 1;
    bool flag = true;
    for(int v : adj[u]){
        if(v != prev){
            dfs(v, u);
            sz[u] += sz[v];
            if(sz[v] != 1) flag = false;
        }
    }
    if(flag && sz[u] > 2) all_leaf++;
    if(sz[u] == 1) leaf_count++;
}

int main(){
    int u,v;
    scanf("%d", &N);
    FOR(i, 0, N-1){
        scanf("%d %d", &u, &v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    printf("%d", (leaf_count-all_leaf));
}