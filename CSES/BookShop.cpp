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

const int MAX = 1007;

pii books[MAX];
int h[MAX], s[MAX];
int dp[MAX][100007];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, x; cin >> n >> x;
    FOR(i, 0, n) cin >> books[i].first;
    FOR(i, 0, n) cin >> books[i].second;

    sort(books, books+n);
    FOR(i, 1, n+1){
        FOR(j, 1, x+1){
            if (books[i-1].first <= j){
                dp[i][j] = max(
                    books[i-1].second + dp[i-1][j - books[i-1].first],
                    dp[i-1][j]
                );
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][x] << "\n";
    return 0;
}