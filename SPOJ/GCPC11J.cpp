#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t,n,u,v,i;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<vector<int>> graph(n);
		int previous[n]; 
		for(i = 0; i < n-1; i++){
			scanf("%d %d", &u, &v);
			previous[i] = -1;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		previous[n-1]=-1;
		
		queue<int>q; q.push(0);
		int visited[n],lastNode = -1; memset(visited, 0, sizeof(visited));
		visited[0]=1;
		while(!q.empty()){
			u = q.front(); q.pop();
			lastNode = u;
			for(i = 0; i < graph[u].size(); i++){
				v = graph[u][i];
				if(!visited[v]){
					q.push(v);
					visited[v]=1; 
				}
			}
		}
		q.push(lastNode);
		memset(visited, 0, sizeof(visited));
		previous[lastNode]=1; visited[lastNode]=1;
		int temp = lastNode;
		while(!q.empty()){
			u=q.front();q.pop();
			lastNode=u;
			for(i = 0; i < graph[u].size(); i++){
				v = graph[u][i];
				if(!visited[v]){
					q.push(v);
					visited[v]=1;
					previous[v]=u;
				}
			}
		}
		vector<int>path;
		int x = lastNode;
		while(x != temp){
			path.push_back(x);
			x = previous[x];
		}
		path.push_back(x);
		printf("%d\n", (path.size()/2));
	}
	return 0;
