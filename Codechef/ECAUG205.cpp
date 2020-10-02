#include <cstdio>
#include <iostream>
#include <vector>
#define SIZE 100007
using namespace std;

int t, n, k;
vector<int> arr;

int main(){
    scanf("%d", &t);
    while(t--){
        arr.clear();
        scanf("%d %d", &n, &k);
        arr.resize(n);
        int l = 1, h = 0, mid, cnt, i;
        for(i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(h < arr[i])
                h = arr[i];
        }
        int ans = 0;
        while(l <= h){
            mid = (l+h)/2;
            cnt = 0;
            for(i = 0; i < n; i++)
                cnt += arr[i]/mid;
            if(cnt > k) l = mid+1;
            else if(cnt == k) {
                ans = mid;
                l = mid+1;
            }
            else h = mid-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}