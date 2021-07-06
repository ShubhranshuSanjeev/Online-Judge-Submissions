#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <bitset>
#include <unordered_set>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for(int i = int(st); i != int(ed); i += step)
#define FOREACH(it, ds) for(auto it = ds.begin(); it != ds.end(); ++it)

using namespace std;

const int MAX = 100007;
const int MOD = 1e9+7;

ll dp[MAX][107];
int x[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int N, M;
    cin >> N >> M;

    FOR(i, 0, N) cin >> x[i];

    memset(dp, 0, sizeof(dp));
    if(x[0] == 0) {
        FOR(i, 1, M+1) dp[0][i] = 1;
    } else {
        dp[0][x[0]] = 1;
    }

    FOR(i, 1, N){
        if(x[i] == 0){
            FOR(j, 1, M+1){
                for(int k: {j-1, j, j+1}){
                    if(k >= 1 && k <= M){
                        (dp[i][j] += dp[i-1][k]) %= MOD;
                    }
                }
            }
        } else {
            for(int k: {x[i]-1, x[i], x[i]+1}){
                if(k >= 1 && k <= M){
                    (dp[i][x[i]] += dp[i-1][k]) %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    FOR(i, 1, M+1){
        (ans += dp[N-1][i]) %= MOD;
    }
    cout << ans << "\n";

    return 0;
}