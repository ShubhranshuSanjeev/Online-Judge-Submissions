#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

const long long int mod = 2147483647; 

using namespace std;

int main()
{
	int n; scanf("%d", &n);
	char G[n+7][n+7];
	int moves[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
	long long int dp[n+7][n+7];
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf(" %c", &G[i][j]);
			if(i == 1 && j == 1) continue;
			if(G[i][j] == '.'){
				dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod) % mod;
			}
		}
	}
	
	if(dp[n][n]) printf("%lld\n", dp[n][n]);
	else{
		queue<int> q;
		q.push(10001);
		while(!q.empty()){
			int ur = q.front()/10000;
			int uc = q.front()%10000;
			
			if(ur == n && uc == n) break;
			q.pop();
			for(int i = 0; i < 4; i++){
				int vr = ur + moves[i][0];
				int vc = uc + moves[i][1];
				if(vr > 0 && vr <= n && vc > 0 && vc <= n && G[vr][vc] == '.'){
					G[vr][vc] = '#';
					if(vr == n && vc == n){
						printf("THE GAME IS A LIE\n");
						return 0;
					}
					q.push(vr*10000+vc);
				}
			}
		}
		printf("INCONCEIVABLE\n");
	}
	return 0;
