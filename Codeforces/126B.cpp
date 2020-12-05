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

const int MAX = 1000007;
const int MOD = 1000000009;
const int P = 31;

ll p_pow[MAX], hash_str[MAX];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    p_pow[0] = 1;
    FOR(i, 1, MAX){
        p_pow[i] = (p_pow[i-1]*P) % MOD;
    }    

    
    int N;
    string s;
    cin >> s;

    N = s.length();
    hash_str[0] = 0;

    FOR(i, 0, N) hash_str[i+1] = (hash_str[i] + (s[i]-'a'+1)*p_pow[i])%MOD;

    vector<pair<int, ll>> matches;
    FOR(l, 1, N){
    	ll hash_p = (hash_str[l] * p_pow[N-1]) % MOD;
    	ll hash_s = (hash_str[N] + MOD - hash_str[N-l]) % MOD;
    	hash_s = (hash_s * p_pow[l-1]) % MOD;
    	// cout << s.substr(0, l) << " " << s.substr(N-l, l) << " " << hash_s << " " << hash_p << "\n";
    	if(hash_p == hash_s)
    		matches.emplace_back(l, hash_s);
    }

    reverse(matches.begin(), matches.end());
	bool found = false;
    for(auto &x: matches){
    	int s_len = x.first;
    	ll s_hash = x.second;
    	found = false;
    	FOR(i, 1, min(N-s_len, N-1)){
    		ll curr_hash = (hash_str[i+s_len] + MOD - hash_str[i]) % MOD;
    		curr_hash = (curr_hash * p_pow[N-i-1]) % MOD;

    		if(curr_hash == s_hash){
    			found = true;
    			break;
    		} 
    	}

    	if(found){
    		cout << s.substr(0, s_len) << "\n";
    		break;
    	}
    }

    if(!found)
    	cout << "Just a legend\n";

    return 0;
}
