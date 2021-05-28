#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
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

const ll P = 31;
const ll MOD = 1e9 + 9;
const int MAXN = 1000007;

string str;
ll str_hash[MAXN], p_pow[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> str;
    int N = (int) str.size();

    p_pow[0] = 1, str_hash[0] = 0;
    FOR(i, 1, N) p_pow[i] = (p_pow[i-1] * P) % MOD;
    FOR(i, 0, N) str_hash[i+1] = ((p_pow[i] * (str[i] - 'a' + 1)) + str_hash[i]) % MOD;

    FOR(i, 0, N-1){
        ll prefix_hash = (str_hash[i+1] * p_pow[N-i-1]) % MOD;
        ll suffix_hash = (str_hash[N] + MOD - str_hash[N-i-1]) % MOD;
        
        if(suffix_hash == prefix_hash){
            cout << (i+1) << " ";
        }
    }
    cout << "\n";
    return 0;
}