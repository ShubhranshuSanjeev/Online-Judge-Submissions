#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
	int t,n,k,a;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &k, &n);
		multiset<int, greater<int>> top;
		multiset<int, greater<int>> others;
		for(int i = 0; i < n; i++){
			scanf("%d", &a);
			if(top.size() < k){
				top.insert(a);
			}
			else{
				others.insert(a);
				int x = *(--top.end());
				if(x < *others.begin()){
					top.erase(--top.end());
					top.insert(*others.begin());
					others.erase(others.begin());
					others.insert(x);
				}
			}
			if(top.size() < k) printf("-1 ");
			else printf("%d ", *(--top.end()));
		}
		printf("\n");
	}
}

