#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    int n,k,i;
    while(t--){
        vector<int>dino;
        scanf("%d %d", &n, &k);
        int flag = 0;
        for(i = 1; i <= n-1; i++){
            if(k+1 == i){ printf("%d ", n); flag = 1;}
            printf("%d ", i);
        }
        if(flag == 0) printf("%d\n", n);
        else printf("\n");
    }
}
