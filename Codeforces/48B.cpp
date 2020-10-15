#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007
using namespace std;

int main(){
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    int A[N][M];
    FOR(i, 0, N){
        FOR(j, 0, M){
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d %d", &a, &b);

    // to find a matrix of dimension a*b with minimum value.
    int ans = INT32_MAX;
    FOR(i, 0, N){
        FOR(j, 0, M){
            int x = INT32_MAX, y = INT32_MAX;
            if((i+a-1) < N && (j+b-1) < M) {
                x = 0;
                FOR(k, i, i + a) {
                    FOR(l, j, j + b) {
                        x += A[k][l];
                    }
                }
            }
            if((i+b-1) < N && (j+a-1) < M) {
                y = 0;
                FOR(k, i, i + b) {
                    FOR(l, j, j + a) {
                        y += A[k][l];
                    }
                }
            }
//            cout << i << " " << j << " " << x << " " << y << "\n";
            ans = min(ans, min(x, y));
        }
    }
    printf("%d\n", ans);
    return 0;
}