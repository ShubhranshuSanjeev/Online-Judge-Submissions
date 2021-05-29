#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main(){
	int t,n,pi,u,v;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);

		vector<int> adj[n];
		queue<int> q;
		int population[n];
		set<pair<int,int>> popHeap;

		for (int i = 0; i < n; i++){
			scanf("%d", &population[i]);
			popHeap.insert(make_pair(population[i], i));
		}
		for(int i = 1; i < n; i++){
			scanf("%d %d", &u, &v);
			u--;v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < adj[i].size(); j++){
				popHeap.erase(make_pair(population[adj[i][j]], adj[i][j]));
				q.push(adj[i][j]);
			}
			popHeap.erase(make_pair(population[i], i)); q.push(i);
			printf("%d ", ((*(--popHeap.end())).second+1));
			while(!q.empty()){
				popHeap.insert(make_pair(population[q.front()], q.front()));
				q.pop();
			}
		}
		printf("\n");
	}
	return 0;
}

