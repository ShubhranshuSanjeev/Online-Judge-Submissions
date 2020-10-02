#include <cstdio>

#define MOD 1000000007

using namespace std;

int power(int n){
    int res = 1;
    int a = 2;
    long long int tmp;
    while(n > 0){
        if(n & 1) {
            tmp = ((long long int)res*a) % MOD;
            res = (int)tmp;
        }
        n = n >> 1;
        long long int tmp = ((long long int)a%MOD * a%MOD) % MOD;
        a = (int)tmp;
    }
    return res;
}

int main() {
    int t, n, i, a;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &a);
        }

        printf("%d", power(n-1));
        for(i = 1; i < n; i++) { printf(" %d", power(n-i-1)); }
        printf("\n");
    }
    return 0;
}