#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007
using namespace std;

int N;
vector<pii> coord;
vector<int> visited;

void dfs(int u){
    visited[u] = 1;
    FOR(i, 0, N){
        if(i == u || visited[i]) continue;
        if(coord[i].first == coord[u].first || coord[i].second == coord[u].second) dfs(i);
    }
}

int main(){
    int x, y;
    scanf("%d", &N);
    visited.resize(N, 0);
    FOR(i, 0, N){
        scanf("%d %d", &x, &y);
        coord.emplace_back(x, y);
    }
    int components = 0;
    FOR(i, 0, N){
        if(!visited[i]) {
            dfs(i);
            components++;
        }
    }
    printf("%d\n", (components-1));
    return 0;
}