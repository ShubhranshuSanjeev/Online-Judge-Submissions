#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int t, m;
    int arr[20007][2];

    scanf("%d", &t);
    while (t--){
        scanf("%d", &m);
        for(int i = 0; i < m; i++) scanf("%d %d", &arr[i][0], &arr[i][1]);
        sort(arr, arr+m);
        
    }

    return 0;
}