#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007

using namespace std;
int N, M, K, is_special[MAX];
vector<pair<int,int>> adj[MAX];
int min_dist = INT32_MAX;

void dijkstra(int source){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> cost(N, -1);

    q.push(make_pair(0, source));
    cost[source] = 0;

    while(!q.empty()){
        int current = q.top().second;
        int path_cost = q.top().first;
        q.pop();

        if(path_cost > min_dist) return;
        if(is_special[current] && current != source) {
            min_dist = path_cost;
            return;
        }

        for(pair<int, int> to : adj[current]){
            if(cost[to.first] == -1 || (path_cost+to.second) < cost[to.first]){
                q.push(make_pair(path_cost+to.second, to.first));
                cost[to.first] = path_cost+to.second;
            }
        }
    }

}

int main(){
    int sp_node, x, y, z;
    memset(is_special, 0, sizeof(is_special));

    scanf("%d %d %d", &N, &M, &K);
    FOR(i, 0, K){
        scanf("%d", &sp_node);
        --sp_node;
        is_special[sp_node] = 1;
    }
    FOR(i, 0, M){
        scanf("%d %d %d", &x, &y, &z);
        --x; --y;
        adj[x].push_back(make_pair(y,z));
        adj[y].push_back(make_pair(x,z));
    }

    FOR(i, 0, N){
        if(is_special[i]){
            dijkstra(i);
        }
    }
    printf("%d\n", min_dist);
    return 0;
}