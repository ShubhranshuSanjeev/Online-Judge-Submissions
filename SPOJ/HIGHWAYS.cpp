#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define N 100007
using namespace std;

vector<int> adj[N], costs[N];
int visited[N];

int main(){
	int t,n,m,s,e,u,v,c;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &n,&m,&s,&e);
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			costs[i].clear();
			visited[i] = -1;
		}

		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &c);
			adj[u].push_back(v);
			costs[u].push_back(c);
			adj[v].push_back(u);
			costs[v].push_back(c);
		}

		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
		q.push(make_pair(0, s));
		visited[s] = 0;

		while(!q.empty()){
			u = q.top().second;
			c = q.top().first;
			// cout << "CITY: " << u << " " << c << "\n";
			q.pop();

			if(u == e) break;
			for(int i = 0; i < adj[u].size(); i++){
				v = adj[u][i];
				int nc = c + costs[u][i];
				// cout << "NEXT: " << v << " " << c << " " << costs[u][i] << " ->";
				if(visited[v] == -1 || nc < visited[v]){
					q.push(make_pair(nc, v));
					visited[v] = nc;
					// cout << " ADDED";
				}
				// cout << "\n";
			}
		}

		if(visited[e] == -1) printf("NONE\n");
		else printf("%d\n", visited[e]);
	}
	return 0;
