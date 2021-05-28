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

const int MAX = 200007;

int N, M, component_cnt;
vector<int> adj[MAX], adj_r[MAX];
vector<int> visited, component;
vector<int> topping_used, trav_order;

void dfs(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    trav_order.push_back(u);
}

void dfs2(int u){
    visited[u] = 1;
    component[u] = component_cnt;

    for(int v: adj_r[u]){
        if(!visited[v]){
            dfs2(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d\n", &N, &M);

    FOR(i, 0, N){
        char c1, c2; int x, y;
        scanf("%c %d %c %d\n", &c1, &x, &c2, &y);

        if(c1 == '-') x = 2*M-x+1;
        if(c2 == '-') y = 2*M-y+1;
        int not_x = 2*M-x+1;
        int not_y = 2*M-y+1;

        adj[not_x].push_back(y);
        adj[not_y].push_back(x);

        adj_r[y].push_back(not_x);
        adj_r[x].push_back(not_y);
    }

    visited.assign(2*M+1, 0);
    FOR(i, 1, 2*M+1){
        if(visited[i]) continue;
        dfs(i);
    }

    visited.assign(2*M+1, 0);
    component.resize(2*M+1);
    FORS(i, trav_order.size()-1, -1, -1){
        int next = trav_order[i];
        if(visited[next]) continue;

        dfs2(next);
        ++component_cnt;
    }

    topping_used.resize(M+1, 0);
    FOR(i, 1, M+1){
        if( component[i] == component[2*M-i+1] ) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        topping_used[i] = component[i] > component[2*M-i+1];
    }

    FOR(i, 1, M+1){
        printf("%c ", topping_used[i] ? '+' : '-');
    }
    printf("\n");

    return 0;
}