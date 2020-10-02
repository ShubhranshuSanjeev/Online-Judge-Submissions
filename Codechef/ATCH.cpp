#include <cstdio>
#include <cstring>
#include <cstdint>
#include <iostream>
#define MAX 1e18
#define SIZE 100007
using namespace std;

int T, N, A[SIZE];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        long long int s = 0, minVal = MAX, ans = -MAX;
        for(int i = 0; i < N; i++){
            s += A[i];
            ans = max(ans, max(s, s-minVal));
            if(s < 0) {
                minVal = MAX;
                s = 0;
            }
            else {
                minVal = min(minVal, (long long int)A[i]);
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}