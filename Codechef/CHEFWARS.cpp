#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int t, h, p;
	scanf("%d", &t);
	while(t--){
	    scanf("%d %d", &h, &p);
	    double x = log2(h);
	    while(p > 0){
	        h -= p;
	        p /= 2;
	    }
	    printf("%d\n", (h < 1));
	}
	return 0;
}

