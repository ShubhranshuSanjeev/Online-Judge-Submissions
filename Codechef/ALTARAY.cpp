#include<stdio.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		long long int arr[n];
		int soln[n];
		for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
		//for(int i = 0; i < n; i++) printf("%lld ", arr[i]);
		soln[n-1] = 1;

		for (int i = n-2; i >= 0; i--)
		{
			if((arr[i+1]*arr[i]) < 0)
				soln[i] = 1 + soln[i+1];
			else
				soln[i] = 1;
		}

		for(int i = 0; i < n; i++) printf("%d ", soln[i]);
		printf("\n");
	}
	return 0;
}



