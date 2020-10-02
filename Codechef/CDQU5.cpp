#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX_SIZE 1000007
#define MOD 1000000009
using namespace std;

int T, X;
int dp[MAX_SIZE];

int main(){
    scanf("%d", &T);

    dp[0]=dp[2]=dp[3]=1;
    for(int i = 4; i <= MAX_SIZE; i++){
        dp[i] = (dp[i-2]+dp[i-3])%MOD;
    }
    while(T--){
        scanf("%d", &X);
        printf("%d\n", dp[X]);
    }
    return 0;
}