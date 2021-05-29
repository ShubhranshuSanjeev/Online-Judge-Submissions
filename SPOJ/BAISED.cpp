#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	int t,n,r,i;
	vector<int> arr;
	cin >> t;
	while(t--){
		arr.clear();
		cin >> n;
		string names[n];
		for(i = 0; i < n; i++){
			cin >> names[i] >> r;
			arr.push_back(r);
		}
		sort(arr.begin(), arr.end());
		long long int bas = 0;
		for(i = 0; i < n; i++){
			int er = arr[i];
			bas += (int)abs(er-i-1);
		}
		cout << bas << "\n";
	}
	return 0;
}
