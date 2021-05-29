#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, u, v, i;
	scanf("%d", &n);
	
	vector<vector<int>> graph(n);
	int visited[n]; memset(visited, 0, sizeof(visited));
	
	for(i = 0; i < n-1; i++){
		scanf("%d %d", &u, &v);
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}
	
	int lastnode = -1;
	queue<int>q; q.push(0);
	visited[0] = 1;
	while(!q.empty()){
		u = q.front(); q.pop();
		lastnode = u;
		for(i = 0; i < graph[u].size(); i++){
			v = graph[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v] = 1;
			}
		}
	}
	
	int temp = lastnode;
	memset(visited, 0, sizeof(visited));
	q.push(lastnode); visited[lastnode] = 1;
	while(!q.empty()){
		u = q.front(); q.pop();
		lastnode = u;
		for(i = 0; i < graph[u].size(); i++){
			v = graph[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v] = visited[u] + 1;
			}
		}
	}
	
	printf("%d\n", visited[lastnode]-1);
	return 0;
