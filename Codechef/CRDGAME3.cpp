#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        int z, x = a/9, y = b/9;
        if(x == y) printf("1 %d\n", x+1);
        else {
            if(x > y){
               z = y + (y*9 == b ? 0 : 1);
               printf("1 %d\n", z);
            }
            else {
                z = x + (x*9 == a ? 0 : 1);
                printf("0 %d\n", z);
            }
        }
    }
	return 0;
}

