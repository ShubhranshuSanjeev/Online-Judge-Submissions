#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	int t,n; scanf("%d", &t);
	while(t--){
		multiset<int> num;
		multiset<int> med;
		int sz = -1, mid = -1;
		while(1){
			scanf("%d", &n);
			if(!n) break;
			if(n == -1){
				printf("%d\n", *(--med.end()));
				med.erase(--med.end());
				sz--; int x = sz >> 1;
				if(mid == x){
					med.insert(*num.begin());
					num.erase(num.begin());
				}
				mid = x;
			}
			else{
				num.insert(n);
				sz++;
				int x = sz >> 1;
				if(x != mid){
					med.insert(*num.begin());
					num.erase(num.begin());
				}
				mid = x;
				if(num.empty()) continue;
				if(*num.begin() < *(--med.end())){
					int y = *(--med.end());
					med.erase(--med.end());
					med.insert(*num.begin());
					num.erase(num.begin());
					num.insert(y);
				}
			}
		}
	}
	return 0;
}
