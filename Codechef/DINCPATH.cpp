#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007
using namespace std;

int T, N, M;
ll A[MAX];
map<ll, vector<pii>> edges;

int main(){
    int u, v;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &N, &M);

        int dp[N+2], lazy[N+2];
        FOR(i, 0, N){
            scanf("%lld", &A[i]);
            dp[i] = 1;
        }

        FOR(i, 0, M){
            scanf("%d %d", &u, &v);
            --u; --v;
            if(A[v] > A[u]) edges[A[v]-A[u]].push_back(make_pair(u,v));
            if(A[u] > A[v]) edges[A[u]-A[v]].push_back(make_pair(v,u));
        }

        for(const auto& it : edges){
            for(const auto& jt: it.second){
                u = jt.first, v = jt.second;
                lazy[v] = 1;
            }

            for(const auto& jt: it.second){
                u = jt.first, v = jt.second;
                lazy[v] = max(lazy[v], dp[u]+1);
            }

            for(const auto& jt: it.second){
                u = jt.first, v = jt.second;
                dp[v] = max(lazy[v], dp[v]);
            }
        }

        int ans = 0;
        FOR(i, 0, N){
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
        edges.clear();
    }
    return 0;
}