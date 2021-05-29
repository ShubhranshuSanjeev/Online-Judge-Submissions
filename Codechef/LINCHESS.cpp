#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t, n, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        int pi, i;
        int player = -1;
        int minMoves = INT32_MAX;
        for(i = 0; i < n; i++) {
            scanf("%d", &pi);
            if(k%pi == 0){
                int x = k/pi;
                if(minMoves > x){
                    minMoves = k/pi;
                    player = pi;
                }
            }
        }
        
        printf("%d\n", player);
    }
	return 0;
}

