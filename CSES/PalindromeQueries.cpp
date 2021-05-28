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

const ll P = 11;
const ll MOD = 1e9+9;
const int MAX = 200007;

string str;
int N;
ll str_h[MAX], p_pow[MAX];
ll bit[MAX], bit_rev[MAX];
ll str_rev_h[MAX];

void update(int n, int val, int val_r){
    for(int i = n; i < N; i = i | (i + 1)){
        bit[i] = (bit[i] + val) % MOD;
    }
    for(int i = n; i < N; i = i | (i + 1)){
        bit_rev[i] = (bit[i] + val_r) % MOD;
    }
}

void query(int l){
    ll ans = 0;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> str;
    N = (int) str.size();

    p_pow[0] = 1; str_h[0] = str_rev_h[0] = 0;
    FOR(i, 1, N) p_pow[i] = (p_pow[i-1]*P) % MOD;
    FOR(i, 0, N) str_h[i+1] = ((str[i] - 'a' + 1) * p_pow[i]) % MOD;
    FOR(i, 0, N) str_rev_h[i+1] = ((str[N-i-1] - 'a' + 1) * p_pow[i]) % MOD;


    return 0;
}