#include <cstdio>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, A[2507], B[2507], C[2507], D[2507];
int E[16000000];

int main(){
    int i, j, k;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    }
    k = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            E[k++] = C[i]+D[j];
    sort(E, E+k);

    int cnt = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            int x = -(A[i]+B[j]);
            cnt += upper_bound(E, E+k, x) - lower_bound(E, E+k, x);
        }
    }
    printf("%d\n", cnt);
    return 0;
}