#include <cstdio>
#include <string>
#include <algorithm>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
using namespace std;

const int MOD = 1e9+7;
long long dp[1007][1007];
char mat[1007][1007];

int main(){
    int n; scanf("%d\n", &n);
    FOR(i, 0, n){
        FOR(j, 0, n){
            scanf("%c", &mat[i][j]);
        }
        char tmp;
        scanf("%c", &tmp);
    }

    FOR(i, 0, n){
        FOR(j, 0, n){
            if(mat[i][j] == '*') dp[i][j] = 0ll;
            else if(i == 0 && j == 0) dp[i][j] = 1ll;
            else if(i == 0) dp[i][j] = dp[i][j-1];
            else if(j == 0) dp[i][j] = dp[i-1][j];
            else {
                long long l = 0, u = 0;
                if(j > 0) {l = dp[i][j-1];}
                if(i > 0) {u = dp[i-1][j];}

                dp[i][j] = (l+u) % MOD;
            }
        }
    }
    printf("%lld", dp[n-1][n-1]);
    return 0;
}