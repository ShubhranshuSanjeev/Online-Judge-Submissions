#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main(){
	int n,x,y;
	scanf("%d %d %d", &n, &x, &y);
	int A[n], B[n];
	vector<pair<int,int>> D(n);
	for(int i = 0; i < n; i++)scanf("%d", &A[i]);
	for(int i = 0; i < n; i++){
		scanf("%d", &B[i]);
		D[i].first = (int)abs(B[i]-A[i]);
		D[i].second = i;
	}
	sort(D.begin(), D.end(), greater<pair<int,int>>());

	long long int tip = 0;

	for(int i = 0; i < n; i++){
		int p = D[i].second;
		if(A[p] > B[p]){
			if(x){
				--x;
				tip+=A[p];
			}
			else{
				--y;
				tip+=B[p];
			}
		}
		else{
			if(y){
				--y;
				tip+=B[p];
			}
			else{
				--x;
				tip+=A[p];
			}
		}
	}
	printf("%lld\n", tip);
	return 0;
}

