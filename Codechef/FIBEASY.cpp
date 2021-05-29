#include <iostream>
#include <cstdio>
// #include <math.h>
using namespace std;

int main()
{
	// long long int f[60];
	// f[0] = 0;
 //    f[1] = 1;
 //    for (int i = 2; i < 60; i++)
 //    {
 //        f[i] = f[i - 1] + f[i - 2];
 //    }

	int t;
	cin >> t;
	while(t--)
	{
		unsigned long long int n;
		scanf("%llu", &n);

		if(n == 2 || n == 3) printf("1\n");
		else if(n == 1) printf("0\n");
		else
		{
			unsigned long long int i = 4;
			unsigned long long int nth = 0;

			while(i <= n)
			{
				i = i*2;
				nth+=1;
			}

			nth = nth % 4;

			if(nth == 1) printf("2\n");
			else if(nth == 2) printf("3\n");
			else if(nth == 3) printf("0\n");
			else printf("9\n");
		}

		// int p = (int) log2(n);
		// unsigned long long int nth = pow(2,p);

		// nth = (nth - 1) % 60;
		// printf("%lld\n", f[nth]%10);
	}
	return 0;
}

