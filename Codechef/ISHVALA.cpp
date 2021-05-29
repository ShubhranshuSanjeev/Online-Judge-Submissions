#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    int n,m,x,y,s,i,j,xi,yi,px,py,tx,ty;
    while(t--){
        px=py=tx=ty=0;
        scanf("%d %d", &n, &m);
        scanf("%d %d %d", &x, &y, &s);
        for(i = 0; i < x; i++){
            scanf("%d", &xi);
            tx+=(xi-px-1)/s;
            px = xi;
        }
        tx+=(n-px)/s;
        for(i = 0; i < y; i++){
            scanf("%d", &yi);
            ty+=(yi-py-1)/s;
            py = yi;
        }
        ty+=(m-py)/s;
        printf("%d\n", (tx*ty));
    }
}
