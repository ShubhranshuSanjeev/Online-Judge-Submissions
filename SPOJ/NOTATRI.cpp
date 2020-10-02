#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, i, j, l, h, mid, ans, arr[2007];
    while(true){
        scanf("%d", &n);
        if(n == 0) break;

        for(i = 0; i < n; i++) scanf("%d", &arr[i]);
        sort(arr, arr+n);

        ans = 0;

        for(i = 0; i < n; i++){
            for(j = i+1; j < n; j++){
                int a = arr[i]+arr[j];

                l = 0, h = n-1;
                while(l < h){
                    mid = (l+h)/2;
                    if(arr[mid] > a) h = mid;
                    else l = mid+1;
                }

                ans += arr[h] > a ? n-h : 0;
            }
        }
        printf("%d\n", ans);
    }
}