#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#define MAX 100007

using namespace std;

int visited[MAX], t, n, e;
vector<vector<int>> graph(MAX);

void dfs(int u){
	visited[u] = 1;
	for(int i = 0; i < graph[u].size(); i++){
		if(!visited[graph[u][i]]){
			dfs(graph[u][i]);
		}
	}
}

int main() {
	int u,v,i;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%d", &e);
		for(i = 0; i < n; i++){ graph[i].clear(); visited[i] = 0;}
		for(i = 0; i < e; i++){
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int cnt = 0; 
		for(i = 0; i < n; i++){
			if(!visited[i]){
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
