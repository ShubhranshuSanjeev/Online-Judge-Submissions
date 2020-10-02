#include <cstdio>
#include <unordered_map>
#include <queue>
#include <vector>
#define MAX_NODES 500007
using namespace std;

int N, M;
vector<pair<int,int>> adj[MAX_NODES];
vector<int> visited, state;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>() > q;

int main(){
    int i, j, u, v, t;
    scanf("%d %d", &N, &M);

    visited.resize(N+7, 0);
    state.resize(N+7, -1);
    for(i = 0; i < M; i++){
        scanf("%d %d %d", &u, &v, &t);
        adj[u].push_back(make_pair(v, t));
    }

    q.push(make_pair())
}