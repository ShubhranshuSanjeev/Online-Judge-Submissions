#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t > 0)
	{
		int n, start, end, i;
		map<int, int> m;
		map<int, int> :: iterator it;
		scanf("%d", &n);

		int rp[n], c[n], zH[n];
		memset(c, 0, n*sizeof(c[0]));

		for(i = 0; i < n; i++)
		{
			scanf("%d", &rp[i]);
			start = i-rp[i] > 0 ? i-rp[i] : 0;
			c[start]+=1;
			if(rp[i]+i < n-1) c[rp[i]+i+1]-=1;
		}

		for(i = 0; i < n; i++)
		{
			if(i > 0) c[i]+=c[i-1];
			if(m.find(c[i]) != m.end()) m[c[i]]+= 1;
			else m[c[i]] = 1;
		}

		int flag = 1;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &zH[i]);
			if(m.find(zH[i]) == m.end()) flag = 0;
			else if(m[zH[i]] == 0) flag = 0;
			else m[zH[i]]-=1;
		}

		if(flag == 1) printf("YES\n");
		else printf("NO\n");

		t--;
	}
	return 0;
}

