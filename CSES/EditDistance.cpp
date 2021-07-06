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

const int MAX = 5007;

int dp[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string a, b;
    cin >> a;
    cin >> b;

    int n = a.length();
    int m = b.length();

    FOR(i, 0, n+1) dp[i][0] = i;
    FOR(i, 0, m+1) dp[0][i] = i;

    FOR(i, 1, n+1){
        FOR(j, 1, m+1){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(
                    min(dp[i-1][j], dp[i][j-1]),
                    dp[i-1][j-1]
                );
            }
        }
    }
    cout << dp[n][m] << "\n";

    return 0;
}