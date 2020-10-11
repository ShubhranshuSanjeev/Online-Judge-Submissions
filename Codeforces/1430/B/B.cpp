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
#define MAX 200007
using namespace std;

int T, N, K;
int A[MAX];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &K);
        FOR(i, 0, N){
            scanf("%d", &A[i]);
        }
        sort(A, A+N, greater<int>());

        ll ans = 0;
        FOR(i, 0, K+1){
            ans += A[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}