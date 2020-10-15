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
#define MAX 3001
using namespace std;

int main(){
    int N, A[MAX], cnt[2*MAX];

    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &N);
    FOR(i, 0, N){
        scanf("%d", &A[i]);
        cnt[A[i]]++;
    }
//    sort(A, A+N);
    int ans = 0;
    FOR(i, 1, N+1){
        if(cnt[i] > 1){
            FOR(j, i+1, 2*MAX){
                if(cnt[i] == 1) break;
                if(cnt[j] == 0) {
                    cnt[i]--, cnt[j]++;
                    ans+= j-i;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}