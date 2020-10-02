#include <cstdio>
#include <cstring>
#define MAX_SCORE 1378
#define ALPHABET_COUNT 52

using namespace std;

int T, L, S;
long long int dp[ALPHABET_COUNT + 7][MAX_SCORE + 7][ALPHABET_COUNT + 7];

long long int solve(int i, int l, int s){
    if(i > ALPHABET_COUNT || i > S || l == L || s >= S){
        dp[i][s][l] = s == S && l == L;
        return dp[i][s][l];
    }
    if(dp[i][s][l] != -1)
        return dp[i][s][l];
    long long int a = solve(i+1, l+1, s+i);
    long long int b = solve(i+1, l, s);
    dp[i][s][l] = a+b;

    return a+b;
}

int main(){
    int i = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &L, &S);
        memset(dp, -1, sizeof(dp));
        if(S > MAX_SCORE || L > ALPHABET_COUNT)  printf("Case %d: 0\n", i++);
        else
            printf("Case %d: %lld\n", i++, solve(1, 0, 0));
    }
    return 0;
}