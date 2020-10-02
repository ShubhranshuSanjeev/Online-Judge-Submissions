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

int T, N, M, components;
vector<int> adj[MAX];
int min_max[MAX][2], visited[MAX];
int dept_head[MAX], emp_count[MAX];
ll e_score, o_score;

void dfs(int u){
    visited[u] = 1;
    min_max[components][0] = min(min_max[components][0], u);
    min_max[components][1] = max(min_max[components][1], u);
    emp_count[components]++;
    for(int v : adj[u]){
        if(!visited[v]) dfs(v);
    }
}

void dfs2(int u, int h, int c, int prev = -1){
    if(emp_count[c]&1) o_score += (ll)h;
    else e_score += (ll)h;
    for(int v : adj[u]){
        if(v != prev) dfs2(v, h+1, c, u);
    }
}

int main(){
    int u, v;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);

        components = e_score = o_score = 0;
        FOR(i, 0, N){
            adj[i].clear();
            visited[i] = 0;
        }
        FOR(i, 0, M){
            scanf("%d %d", &u, &v);
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        FOR(i, 0, N){
            if(!visited[i]){
                emp_count[components] = 0;
                min_max[components][0] = INT32_MAX;
                min_max[components][1] = -1;
                dfs(i);
                dept_head[components] = emp_count[components]&1 ? min_max[components][1] : min_max[components][0];
                components++;
            }
        }
        FOR(i, 0, components){
            dfs2(dept_head[i], 1, i);
        }
        printf("%lld %lld\n", e_score, o_score);

    }
}