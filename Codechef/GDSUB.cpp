#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
#define SIZE 100001
#define MAX_DIST 8001
#define MOD 1000000007
using namespace std;

int N, K, arr[SIZE];
int dist_count, dp[MAX_DIST][SIZE];
unordered_map<long long int, int> um;
vector<int> farr;

long long int solve(int i, int s, long long int occ){
    if(i >= dist_count || s == K){
        dp[i][s] = 0;
        return 0;
    }
    if(dp[i][s] != -1) return (long long int)dp[i][s];

    long long int a = (solve(i+1, s+1, (occ*um[farr[i]])%MOD) + solve(i+1, s, occ)) % MOD;
    dp[i][s] = (int) a;
    return a;
}

int main(){
    dist_count = 0;
    scanf("%d %d", &N, &K);
    int i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        if(um.find(arr[i]) == um.end()){
            um[arr[i]] = 1;
            farr.push_back(arr[i]);
        }
        else ++um[arr[i]];
    }
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, 1) << "\n";
}