#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define N 1007

using namespace std;

vector<pair<int,pair<int,int>>> edges;
int parent[N], ranks[N];

void init(int n){
	edges.clear();
	for(int i = 1; i <= n; i++) parent[i] = i, ranks[i] = 0;
}

int findset(int u){
	if(parent[u] == u) return u;
	return (parent[u] = findset(parent[u]));
}

int unionset(int u, int v){
	u = findset(u);
	v = findset(v);
	// cout << "SET: " << u << " " << v << "\n";
	if(u != v){
		if(ranks[u] > ranks[v]) parent[v] = u;
		else if(ranks[v] > ranks[u]) parent[u] = v;
		else parent[v] = u, ++ranks[u];

		return 1;
	}
	return 0;
}

int main(){
	int t,p,n,m,a,b,c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &p,&n,&m);//scanf("%d", &n);scanf("%d", &m);
		init(n);
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &c);
			edges.push_back(make_pair(c, make_pair(a,b)));
		}
		sort(edges.begin(), edges.end());

		long long int ans = 0;
		for(int i = 0; i < edges.size(); i++){
			c = edges[i].first;
			a = edges[i].second.first;
			b = edges[i].second.second;
			// cout << "EDGE: " << a << " " << b << " " << c << "\n";

			if(unionset(a,b)){
				// cout << "ADDED: " << a << " " << b << " " << c << "\n";
				ans+=c;
			}
		}
		printf("%lld\n", ans*p);
	}
	return 0;
}
