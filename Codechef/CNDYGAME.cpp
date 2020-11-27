#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define ivec1d(x, n, v) vec1d(x)(n, v)
#define ivec2d(x, n, m, v) vec2d(x)(n, ivec1d(x, m, v))
#define ivec3d(x, n, m, k, v) vec3d(x)(n, ivec2d(x, m, k, v))
#define ivec4d(x, n, m, k, l, v) vec4d(x)(n, ivec3d(x, m, k, l, v))

#define FOR(i, st, ed) for(ll i = (ll)st; i < (ll)ed; i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007
using namespace std;

const ll MOD = 1000000007;

int main(){
    ll T, N, Q, R, A[MAX];
    scanf("%lld", &T);

    while(T--){
        scanf("%lld", &N);
        ll op = -1;
        FOR(i, 0, N){
            scanf("%lld", &A[i]);
            if(A[i] == 1) op = i;
        }
        
        ll c1[N+5], c2[N+5], c3[N+5];
        FOR(i, 0, N-1){
            if(op == -1 || op == (N-1)) {
                c1[i] = A[i]&1 ? (A[i]-1) : A[i];
                if(i > 0) c1[i] = (c1[i-1] + c1[i]) % MOD;
            }
            else if(op == N-1) {
                c2[i] = A[i]&1 ? A[i]-1 : A[i];
                if(i > 0) c2[i] = (c2[i-1] + c2[i]) % MOD;
            }
            else if(op > 0 && op < N-1){
                if(A[i] == 1) c3[i] = 0;
                else if(A[i+1] == 1) c3[i] = A[i]&1 ? A[i] : (A[i]-1);
                else c3[i] = A[i]&1 ? (A[i]-1) : A[i];

                if(i > 0) c3[i] = (c3[i-1] + c3[i]) % MOD;
            }
        }
        if(op == -1 || op == (N-1)) 
            c1[N-1] = ((N > 1 ? c1[N-2] : 0) + (A[N-1]&1 ? A[N-1] : (A[N-1]-1))) % MOD;
        else if(op == N-1) 
            c2[N-1] = ((N > 1 ? c2[N-2] : 0) + 1) % MOD;
        else if(op > 0 && op < N-1)
            c3[N-1] = ((N > 1 ? c3[N-2] : 0) + (A[N-1]&1 ? A[N-1] : (A[N-1]-1))) % MOD;

        scanf("%lld", &Q);
        FOR(i, 0, Q){
            scanf("%lld", &R);
            ll turns = R/N, rem = R%N, ans = 0;
            
            if(op == 0) {
                if(rem == 0) {
                    ans = turns % MOD;
                }
                else {
                    ans = (turns + 1) % MOD;
                }
            }
            else if(op == -1) {
                if(rem == 0){
                    ans = (c1[N-1]*(turns-1)) % MOD;
                    ans = ((ans + (N == 1 ? 0 : c1[N-2])) % MOD + A[N-1] % MOD) % MOD; 
                }
                else{
                    ans = (c1[N-1]*turns) % MOD;
                    if(rem > 1) ans = (ans + c1[rem-2]) % MOD;
                    ans = (ans + A[rem-1])%MOD;
                }
            }
            else if(op == N-1) {
                ans = (c1[N-1]*turns) % MOD;
                if(rem > 1) ans = (ans + c1[rem-2]) % MOD;
                ans = (ans + A[rem-1]) % MOD;
            }
            else {
                if(rem == 0){
                    ans = (c3[N-1]*(turns-1)) % MOD;
                    ans = ((ans + c3[N-2]) % MOD + A[N-1] % MOD) % MOD;
                }
                else {
                    ans = (c3[N-1]*turns) % MOD;
                    if((rem-1) == op){
                        if(op > 1) ans = (ans + c3[op-2])%MOD;
                        ans = (ans + (A[op-1]&1 ? A[op-1] : (A[op-1]+1)))%MOD; 
                    }
                    else {
                        if(rem > 1) ans = (ans + c3[rem-2]) % MOD;
                        ans = (ans + A[rem-1]) % MOD;
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}