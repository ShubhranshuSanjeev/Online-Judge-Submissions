#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	int f,s,g,u,d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	int visited[f+7];
	memset(visited, -1, (f+1)*sizeof(visited[0]));
	queue<int> q; q.push(s);
	visited[s] = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		int a = x+u;
		int b = x-d;
		if(a <= f && visited[a] == -1){
			visited[a] = visited[x] + 1;
			q.push(a);
		}
		if(b > 0 && visited[b] == -1){
			visited[b] = visited[x] + 1;
			q.push(b);
		}
	}
	if(visited[g] == -1) printf("use the stairs\n");
	else printf("%d\n", visited[g]);
	return 0;
