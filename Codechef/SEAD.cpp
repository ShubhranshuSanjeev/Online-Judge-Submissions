#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#define FOR(st, ed) for(int i = st; i < ed; i++)
#define FOR2(st, ed) for(int j = st; j < ed; j++)
using namespace std;

int main(){
    int N, M, T, D;
    scanf("%d", &N);
    vector<int> A(N+2);

    FOR(1, N+1){
        scanf("%d", &A[i]);
    }
    A[N+1] = INT_MAX;
    int h = (int) log2(N);
    int sp_table[h+1][N+1];
    FOR(0, h+1){
        FOR2(0, N+1){
            sp_table[i][j] = -1;
        }
    }

    FOR(1, N+1){
        sp_table[0][i] = A[i+1]-A[i];
    }

    FOR(1, h+1){
        int val=(1<<(i-1)), val1=(1<<(i));
        for(int j=1; (j-1+val1) <= N; j++){
            sp_table[i][j]=max(sp_table[i-1][j],sp_table[i-1][j+val]);
        }
    }

    scanf("%d", &M);
    while(M--){
        scanf("%d %d", &T, &D);

        int k = (upper_bound(++A.begin(), A.end(), T) - A.begin()) - 1;
        if(k == 1) printf("1\n");
        else {
            int l = 1, h = k-1, ans = k;
            while(l <= h){
                int mid = (l+h)>>1, hi = log2(k - mid);
                int a = max(sp_table[hi][mid], sp_table[hi][k-(1<<hi)]);
                if(a <= D){
                    ans = mid;
                    h = mid-1;
                }
                else l = mid+1;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
