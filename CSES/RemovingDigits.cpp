#include <cstdio>
#include <string>
#include <algorithm>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
using namespace std;

const int MOD = 1e9+7;
long long dp[1000007];

int main(){
    int n; scanf("%d", &n);
    FOR(i, 1, n+1) dp[i] = 1e9;
    dp[0] = 0ll;
    FOR(i, 1, n+1){
        for(char c: to_string(i)){
            dp[i] = min(dp[i], dp[i-(c-'0')]+1);
        }
    }
    printf("%lld", dp[n]);
    return 0;
}