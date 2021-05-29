#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int t,n,ai;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);

		vector<int> arr;
		vector<int> subsets;
		multiset<int> subsetSum;

		for(int i = 0; i < (1<<n); i++){
			scanf("%d", &ai);
			subsetSum.insert(ai);
			//cout << "Inserting: " << ai << "\n";
		}

		subsets.push_back(0);
		int ptr = 0;

		while(!subsetSum.empty()){
			//cout << "New iter: " << ptr << " " << subsets.size() << "\n";

			for(int i = ptr; i < subsets.size(); i++){
				//cout << "Erasing: " << subsets[i] << "\n";
				subsetSum.erase(subsets[i]);
			}
			if(subsetSum.empty()) break;

			int newEle = *subsetSum.begin();
			//cout << "New Element: " << newEle << "\n";

			subsetSum.erase(subsetSum.begin());
			arr.push_back(newEle);

			int l = subsets.size();
			ptr = l+1;

			for(int i = 0; i < l; i++) {
				//cout << "Inserting Subset: " << (newEle + subsets[i]) << "\n";
				subsets.push_back(newEle + subsets[i]);
			}
		}
		for(int i = 0; i < arr.size(); i++) printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;
}

