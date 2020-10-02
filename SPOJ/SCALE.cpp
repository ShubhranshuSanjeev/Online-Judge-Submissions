#include <cstdio>
#include <cmath>

using namespace std;

int log(int n, int b){
    return  n > 1 ? (1 + log(n/b, b)) : 0;
}

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    int i, flag = 0;
    long long int a = 0;

    for(i = n; i > 0; i--){
        a += (long long int) pow(3, i-1);
        if(a > x) { flag = 1; break; }
    }

    if(flag) {
//        printf("\n");
        for(int j = i; j <= n; j++)
            printf("%d ", j);
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}