#include <cstdio>
#include <algorithm>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
using namespace std;

const int MOD = 1e9+7;
long long dp[1000007];
int coins[103];

int main(){
    int n, x; scanf("%d %d", &n, &x);
    FOR(i, 0, n) {
        scanf("%d", &coins[i]);
    }

    dp[0] = 1ll;
    FOR(j, 0, n){
        FOR(i, 1, x+1){
            if(i-coins[j] < 0) continue;
            dp[i] = (dp[i] + dp[i-coins[j]]) % MOD;
        }
    }
    printf("%lld", dp[x]);
    return 0;
}