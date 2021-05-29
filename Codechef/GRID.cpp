#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int t,n;
	scanf("%d", &t);
	do{
		scanf("%d", &n);
		char GRID[n][n];
		int lastObsR[n], lastObsC[n];
		memset(lastObsR, -1, sizeof(lastObsR));
		memset(lastObsC, -1, sizeof(lastObsC));

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf(" %c", &GRID[i][j]);
				if(GRID[i][j] == '#'){
					lastObsR[i] = j;
					lastObsC[j] = max(lastObsC[j], i);
				}
			}
			// cout << lastObsR[i] << "\n";
		}
		long long int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = n-1; j > lastObsC[i]; j--){
				if(i > lastObsR[j]) ++ans;
			}
		}
		printf("%lld\n", ans);
	}while(--t);
	return 0;
}

