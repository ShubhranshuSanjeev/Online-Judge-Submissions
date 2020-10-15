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

int T, N, A[MAX];
ll mx_ele, ans;

int main(){
    scanf("%d", &T);

    while (T--){
        scanf("%d", &N);
        mx_ele = INT64_MIN;
        FOR(i, 0, N){
            scanf("%d", &A[i]);
            mx_ele = max(mx_ele, (ll)A[i]);
        }

        sort(A, A+N, [](int a, int b){return abs(a) > abs(b);});
        if(mx_ele < 0){
            printf("%lld\n", (ll)A[N-5]*A[N-1]*A[N-2]*A[N-3]*A[N-4]);
            continue;
        }
        ans = (ll)A[0]*A[1]*A[2]*A[3]*A[4];
        FOR(i, 5, N){
            FOR(j, 0, 5){
                ll tmp = A[i];
                FOR(k, 0, 5){
                    if(k == j) continue;
                    tmp *= A[k];
                }
                ans = max(ans, tmp);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}