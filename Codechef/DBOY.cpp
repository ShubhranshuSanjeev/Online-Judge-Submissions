#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 100007
using namespace std;

int main(){
	int t,n;
	scanf("%d", &t);
	do{
		scanf("%d", &n);
		int H[n], K[n], MAXVAL = -1;

		for(int i = 0; i < n; i++){
			scanf("%d", &H[i]);
			if(MAXVAL < H[i]) MAXVAL = H[i];
		}
		for(int i = 0; i < n; i++) scanf("%d", &K[i]);

		int dp[2*MAXVAL+1];
		for(int i = 0; i < (2*MAXVAL+1); i++) dp[i] = INF;

		for(int i = 0; i <= 2*MAXVAL; i++){
			for(int j = 0; j < n; j++){
				if(i == 0) dp[0] = 0;
				else{
					int x = K[j];
					if(x <= i) dp[i] = min(dp[i], dp[i-x] + 1);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) ans += dp[2*H[i]];
		printf("%d\n", ans);
	} while (--t);

	return 0;
}

