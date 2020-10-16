#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 107
using namespace std;

int main(){
    int T, N, M;
    ll A[MAX][MAX];
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &N, &M);
        FOR(i, 0, N){
            FOR(j, 0, M){
                scanf("%lld", &A[i][j]);
            }
        }
        ll ans = 0;
        FOR(i, 0, (N/2 + (N&1 ? 1 : 0)) ){
            FOR(j, 0, (M/2 + (M&1 ? 1 : 0))){
                int x = N-i-1;
                int y = M-j-1;
                vector<ll> s;
                s.push_back(A[i][j]);
                if(x != i) s.push_back(A[x][j]);
                if(y != j) s.push_back(A[i][y]);
                if(x != i && y != j) s.push_back(A[x][y]);
                sort(s.begin(), s.end());
                ll med = s[s.size()/2], tmp = 0;
                for(int u : s){
                    tmp+=abs(med-u);
                }
                ans+=tmp;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}