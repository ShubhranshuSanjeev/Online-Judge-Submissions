#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAX 10007
#define N 107
using namespace std;

int n, A[N];
long long int dp[N][MAX];

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

long long int countGCD(int idx, int a, int n){
	if(idx == n) return (a==1);
	if(dp[idx][a] != -1) return dp[idx][a];

	dp[idx][a] = countGCD(idx+1, a, n) + countGCD(idx+1, gcd(A[idx], a), n);

	return dp[idx][a];
}

void countSubSequences(int n){
	long long int c = 0;
	for(int i = 0; i < n; i++)
		c+= countGCD(i+1, A[i], n);
	printf("%lld\n", c);
}



int main(){
	int t,n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < n; i++) scanf("%d", &A[i]);
		sort(A, A+n);
		countSubSequences(n);
	}
	return 0;
}

