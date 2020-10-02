#include <cstdio>
#include <cstring>
#define MAX 100001

using namespace std;

int T, A, B, K;
int seive[MAX];

int main(){
    int i, j, cnt;
    scanf("%d", &T);
    memset(seive, 0, sizeof(seive));
    for(i = 2; i <= MAX; i++){
        if(seive[i] == 0)
            for(j = i; j <= MAX; j += i)
                seive[j]++;
    }

    while(T--){
        cnt = 0;
        scanf("%d %d %d", &A, &B, &K);
        for(i = A; i <= B; i++)
            if(seive[i] == K) cnt++;

        printf("%d\n", cnt);
    }
}