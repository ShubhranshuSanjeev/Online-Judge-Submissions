#include <cstdio>
#include <iostream>
#include <vector>

#define SIZE 1007
using namespace std;

int T, N, M;
int W[SIZE][SIZE];
int ans[SIZE][SIZE];
int poss[3][2] = {{1, 1}, {1, 0}, {1, -1}};

int main(){
    int i, j, k, r, c;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &N, &M);

        for(i = 1; i <= N; i++)
            for(j = 1; j <= M; j++) {
                scanf("%d", &W[i][j]);
                ans[i][j] = -1;
            }
        for(i = N; i > 0; i--){
            for(j = M; j > 0; j--){
                if(i == N) {
                    ans[N - i + 1][j] = 1;
                    continue;
                }
                for(k = 0; k < 3; k++){
                    r = i + poss[k][0];
                    c = j + poss[k][1];

                    if(r > 0 && r <= N && c > 0 && c <= M){
                        if(W[N-i+1][j] > W[N-r+1][c]) ans[N-i+1][j] = ans[N-i+1][j] == 0 ? 0 : 1;
                        else {
                            ans[N-i+1][j] = 0;
                            W[N-i+1][j] = max(W[N-i+1][j], W[N-r+1][c]);
                        }
                    }
                }
            }
        }

        for(i = 1; i <= N; i++) {
            for (j = 1; j <= M; j++) {
                printf("%d", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}