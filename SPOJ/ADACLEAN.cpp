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

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define ivec1d(x, n, v) vec1d(x)(n, v)
#define ivec2d(x, n, m, v) vec2d(x)(n, ivec1d(x, m, v))
#define ivec3d(x, n, m, k, v) vec3d(x)(n, ivec2d(x, m, k, v))
#define ivec4d(x, n, m, k, l, v) vec4d(x)(n, ivec3d(x, m, k, l, v))

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
using namespace std;

const int MAX = 100007;
const int MOD = 1000000009;
const int P1 = 17;
const int P2 = 11;

ll p_pow1[MAX], p_pow2[MAX];
ll str_hash1[MAX], str_hash2[MAX];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif   			

    p_pow1[0] = p_pow2[0] = 1;
    FOR(i, 1, MAX){
        p_pow1[i] = (p_pow1[i-1]*P1) % MOD;
        p_pow2[i] = (p_pow2[i-1]*P2) % MOD;
    }

    int T, N, K;
    string str;

    cin >> T;

    while(T--){
    	cin >> N >> K;
    	cin >> str;

    	set<pll> unq_hash;
    	str_hash1[0] = str_hash2[0] = 0;

    	FOR(i, 0, N){
    		str_hash1[i+1] = (str_hash1[i] + (str[i] - 'a' + 1)*p_pow1[i]) % MOD;
    		str_hash2[i+1] = (str_hash2[i] + (str[i] - 'a' + 1)*p_pow2[i]) % MOD;
    	}

    	FOR(i, 0, N-K+1){
    		ll curr_h1 = (str_hash1[i+K] + MOD - str_hash1[i]) % MOD;
    		curr_h1 = (curr_h1 * p_pow1[N-i-1]) % MOD;

    		ll curr_h2 = (str_hash2[i+K] + MOD - str_hash2[i]) % MOD;
    		curr_h2 = (curr_h2 * p_pow2[N-i-1]) % MOD;

    		unq_hash.insert({curr_h1, curr_h2});
    	}

    	cout << ((int)unq_hash.size()) << "\n";
    }
 	

    return 0;
}
