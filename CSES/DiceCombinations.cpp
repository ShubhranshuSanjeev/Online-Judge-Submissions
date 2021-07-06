#include <cstdio>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
using namespace std;

const int MOD = 1e9+7;
long long dp[1000007];

int main(){
    int n; scanf("%d", &n);
    dp[0] = 1ll;
    FOR(i, 1, n+1){
        FOR(j, 1, 7){
            if(i-j < 0) break;
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    printf("%ld",dp[n]);
    return 0;
}