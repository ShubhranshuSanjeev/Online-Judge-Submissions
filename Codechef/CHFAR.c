#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int arr[n];
		int c = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			if (arr[i]!=1)
				c++;
		}
		if(k>=c)
			printf("YES\n");
		else
			printf("NO\n");
		t--;
	}
	return 0;
}
