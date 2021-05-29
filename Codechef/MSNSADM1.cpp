#include <cstdio>
using namespace std;

int main()
{
	int t, n, A[150], b, B[150];
	scanf("%d", &t);
	while(t > 0)
	{
		scanf("%d", &n);
		int max = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
			A[i] = 20*A[i];
		}
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &b);
			A[i]-=b*10;
			if(A[i] < 0) A[i] = 0;
			if(max < A[i]) max = A[i];
		}
		printf("%d\n", max);
		t--;
	}
	return 0;
}
