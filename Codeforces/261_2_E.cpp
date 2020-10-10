#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007
using namespace std;

int N, M;
vector<pii> edges[MAX];

int main(){
    int u, v, w;
    scanf("%d %d", &N, &M);
    FOR(i, 0, M){
        scanf("%d %d %d", &u, &v, &w);
        edges[w].push_back(make_pair(u, v));
    }

    int dp[N+2], lazy[N+2];
    memset(dp, 0, sizeof(dp));
    FOR(i, 1, 100001){
        FOR(j, 0, edges[i].size()){
            u = edges[i][j].first, v = edges[i][j].second;
            lazy[v] = 0;
        }
        FOR(j, 0, edges[i].size()){
            u = edges[i][j].first, v = edges[i][j].second;
            lazy[v] = max(lazy[v], dp[u]+1);
        }
        FOR(j, 0, edges[i].size()){
            u = edges[i][j].first, v = edges[i][j].second;
            dp[v] = max(lazy[v], dp[v]);
        }
    }

    int ans = 0;
    FOR(i, 1, N+1){
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}