#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main(){
	int t,n,q,fi,di;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &q);
		int pos = 0;
		long long int ans = 0;
		for(int i = 0; i < q; i++){
			scanf("%d %d", &fi, &di);
			ans += (int)(abs(fi-pos)+abs(fi-di));
			pos = di;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
