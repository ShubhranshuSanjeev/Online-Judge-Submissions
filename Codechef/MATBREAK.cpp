#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>

using namespace std;
const int mod = 1000000007;

long long int power(long long int x, long long int y)
{
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

int main(){
	int t,n,a;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &a);
		long long int curr, s = 0;
		long long int initVal = a;
		for(int i = 1; i <= n; i++){
			curr = power(initVal, (2*i-1));
			initVal = (curr*initVal) % mod;
			s = (s+curr) % mod;
		}
		printf("%lld\n", s);
	}
	return 0;
}

