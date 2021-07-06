#include <cstdio>
#include <algorithm>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
using namespace std;

const int MOD = 1e9+7;
int dp[1000007], coins[103];

int main(){
    int n, x; scanf("%d %d", &n, &x);
    FOR(i, 1, x+1){
        dp[i] = 1e9;
    }

    FOR(i, 0, n) {
        scanf("%d", &coins[i]);
        dp[coins[i]] = 1ll;
    }

    dp[0] = 0ll;
    FOR(i, 1, x+1){
        FOR(j, 0, n){
            if(i-coins[j] < 0) continue;
            dp[i] = min(dp[i], dp[i-coins[j]]+1);
        }
    }
    int ans = dp[x] == 1e9 ? -1 : dp[x];
    printf("%d", ans);
    return 0;
}