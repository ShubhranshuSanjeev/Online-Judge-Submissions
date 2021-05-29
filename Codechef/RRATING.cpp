#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,x,m,s = 0;
	scanf("%d", &n);
	multiset<long long int,greater<int>> top3;
	multiset<long long int,greater<int>> others;
	for(int it = 0; it < n; it++){
		scanf("%d", &m); m--;
		if(m){
            int l = others.size();
			for(int i = 0; i < min(s/3, l); i++){
				if(top3.size() < (s/3)){
					// cout << "INSERTED TOP: " << *others.begin() << "\n";
					top3.insert(*others.begin());
					others.erase(others.begin());
				}
				else{
					if(*(--top3.end()) < *others.begin()){
						// cout << "Erased: " << *(--top3.end()) << "\n";
						long long int x = *(--top3.end()); 
						top3.erase(--top3.end());
						// cout << "INSERTED: " << *(others.begin()) << "\n";
						top3.insert(*others.begin());
						others.erase(others.begin());
						others.insert(x);
					}
					else break;
				}
			}

			if(top3.size() ==  (s/3) && s >= 3) printf("%lld\n", *(--top3.end()));
			else printf("No reviews yet\n");
		}
		else{
			scanf("%d", &x);
			others.insert(x);
			s++;
		}
	}
	return 0;
}

