#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int t;
	long int n, k;
	scanf("%d", &t);
	while(t > 0)
	{
		cin >> n >> k;
		if((n/k)%k == 0) printf("NO\n");
		else printf("YES\n");
		t--;
	}
	return 0;
}
