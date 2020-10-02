#include <cstdio>
using namespace std;

int main(){
    int t,a,b,c;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &a, &b, &c);
        printf("%d ", (a < c ? 1 : -1));
        printf("%d\n", (c < (long long)a*b ? b : -1));
    }
    return 0;
}