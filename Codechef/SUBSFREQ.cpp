#include <cstdio>
#include <map>
#include <unordered_map>
#include <iostream>

#define MOD 1000000007

using namespace std;
int main(){
    int t, n, i, j, maxN;
    int A[500007];

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        unordered_map<int, int> m;

        long long int ans[n+1];
        int freq[n+1];
        maxN = 0;
        for(i = 0; i < n; i++) {
            ans[i+1] = freq[i+1] = 0;
            scanf("%d", &A[i]);
            if(m.find(A[i]) == m.end()) m[A[i]] = 1;
            else ++m[A[i]];

            maxN = max(maxN, m[A[i]]);
        }

        // Computing Binomial Coefficient before hand.
        long long int factorial[maxN+1], inverse[MOD+1];
        factorial[0] = 1; inverse[1] = 1;
        for (int i = 1; i <= maxN; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }
        for(int i = 2; i < MOD; i++){
            inverse[i] = (MOD - (MOD/i) * inverse[MOD%i] % MOD) % MOD;
        }

        long long int C[maxN+1][maxN+1];
        long long int D[maxN+1][maxN+1];
        C[0][0] = 1;
        for(i = 1; i <= maxN; i++){
            C[i][0] = C[i][i] = 1;
            D[i][0] = 1;
            for(j = 1; j < i; j++){
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
                D[i][j] =  (C[i][j] + D[i][j-1]) % MOD;
            }
            D[i][i] = (1 + D[i][j-1]) % MOD;
        }

        unordered_map<int, int> :: iterator it;

        int u, currCount, r;
        long long int poss, s;

        for(i = 0; i < n; i++){
            u = A[i];
            freq[u]++;
            currCount = freq[u];
            poss =  factorial[m[u]] * inverse[factorial[currCount]] % MOD * inverse[factorial[m[u] - currCount]] % MOD;
            s = 1;
            for(it = m.begin(); it != m.end(); it++){
                if((*it).first == u) continue;
                r = currCount - ((*it).first < u ? 1 : 0);
                if((*it).second < r) r = (*it).second;
                s = (s * D[(*it).second][r]) % MOD;
            }
            poss = (poss * s) % MOD;
            ans[u] = (ans[u] + poss) % MOD;
        }

/*
        int u, currCount, r;
        long long int poss, s;
        for(it = m.begin(); it != m.end(); it++){
            u = (*it).first;
            currCount = (*it).second;
            for(i = 1; i <= currCount; i++){
                poss = C[currCount][i];
                s = 1;
                for(jt = m.begin(); jt != m.end(); jt++){
                    if(it == jt) continue;
                    r = i - ((*jt).first < u ? 1 : 0);
                    if((*jt).second < r) r = (*jt).second;
                    s = (s * D[(*jt).second][r]) % MOD;
                }
                poss = (poss * s) % MOD;
                ans[u] = (ans[u] + poss) % MOD;
            }
        }
*/

        for(i = 1; i <= n; i++){
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}