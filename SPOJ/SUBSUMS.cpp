#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void generateSubsets(int start, int n, vector<int> &v, const int* arr){
    int i, j, s;
    for(i = 0; i < (1 << n); i++){
        s = 0;
        for(j = 0; j < n; j++)
            if(i & (1 << j))
                s += arr[j+start];
//        cout << "Sum: " << s << "\n";
        v.push_back(s);
    }
}

int main(){
    int n, A, B, i;
    long long int ans = 0;
    vector<int> left, right;
    vector<int> :: iterator low, high;
    int S[50];

    scanf("%d %d %d", &n, &A, &B);
    for(i = 0; i < n; i++) scanf("%d", &S[i]);

    generateSubsets(0, n/2, left, S);
    generateSubsets(n/2, n&1 ? n/2+1 : n/2, right, S);
    sort(right.begin(), right.end());

    for(i = 0; i < left.size(); i++){
        low = lower_bound(right.begin(), right.end(), A-left[i]);
        high = upper_bound(right.begin(), right.end(), B-left[i]);
        ans += (high-right.begin()) - (low-right.begin());
    }
    printf("%lld\n", ans);
    return 0;
}