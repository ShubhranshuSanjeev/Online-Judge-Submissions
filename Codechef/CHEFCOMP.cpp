#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 200007

using namespace std;

int t, n;
int P[SIZE], A[SIZE], B[SIZE];
int parent[SIZE], visited[SIZE], day[SIZE], answer[SIZE];
vector<int> track_day, tree[SIZE], d_tree[SIZE];
vector<long long int> path;

int find_set(int u){
    return parent[u] = (parent[u] == u ? u : find_set(parent[u]));
}

void union_set(int u, int v){
    v = find_set(v);
    parent[v] = u;
    d_tree[u].push_back(v);
}

void dfs(int u){
    path.push_back(path.empty() ? A[u] : path.back()+A[u]);
    track_day.push_back(day[u]);
    int x = lower_bound(path.begin(), path.end(), B[u]) - path.begin();
    answer[u] = x == path.size() ? -1 : track_day[x];
    for(int i : d_tree[u])
        dfs(i);
    path.pop_back();
    track_day.pop_back();
}

int main(){
    int u, v, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < n; i++) parent[i] = i;

        for(i = 0; i < n-1; i++){
            scanf("%d %d", &u, &v);
            u--; v--;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        for(i = 0; i < n; i++) scanf("%d", &P[i]);
        for(i = 0; i < n; i++) scanf("%d", &A[i]);
        for(i = 0; i < n; i++) scanf("%d", &B[i]);

        for(i = n-1; i >= 0; i--) {
            u = --P[i];
            day[P[i]] = i+1;
            for(int j : tree[u]){
                if(visited[j]){
                    union_set(u, j);
                }
            }
            visited[u] = 1;
        }
        dfs(P[0]);

        for(i = 0; i < n; i++) {
            printf("%d ", answer[i]);
            visited[i] = 0;
            d_tree[i].clear(); tree[i].clear();
        }
        printf("\n");


        /*
         * Brute Force Solution
            vector<int> visited(n+1);
            vector<int> ans(n+1, -1);
            int up;
            for(i = 1; i <= n; i++){
                queue<int> q;
                q.push(P[i]);
                visited.assign(n+1, 0);
                up = A[P[i]];
                while(!q.empty()){
                    u = q.front();
                    q.pop();
                    B[u] -= min(up, B[u]);
                    if(!B[u]) ans[u] = i;
                    for(j = 0; j < adj[u].size(); j++){
                        v = adj[u][j];
                        if(visited[v] || broken[v]) continue;
                        visited[v] = 1;
                        q.push(v);
                    }
                }
                broken[P[i]] = 1;
            }
            printf("%d", ans[1]);
            for(i = 2; i <= n; i++) printf(" %d", ans[i]);
            printf("\n");
        */
    }

    return 0;
}
