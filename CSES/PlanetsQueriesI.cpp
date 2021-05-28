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
#include <bitset>
#include <unordered_set>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for(int i = int(st); i != int(ed); i += step)
#define FOREACH(it, ds) for(auto it = ds.begin(); it != ds.end(); ++it)

using namespace std;

const int MAX = 200007;
const int LOGN = 31;

int N, Q;
int up[LOGN][MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N >> Q;
    FOR(i, 1, N+1) cin >> up[0][i];
    FOR(i, 1, 31){
        FOR(j, 1, N+1){
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }

    FOR(i, 0, Q){
        ll u, k; cin >> u >> k;
        ll st = 0;
        while(k){
            if(k & 1) u = up[st][u];
            st++;
            k = k>>1;
        }
        cout << u << "\n";
    }

    return 0;
}