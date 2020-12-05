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
const int P = 11;

ll p_pow[MAX];
ll hash_a[MAX], hash_b[MAX], hash_c[MAX];

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

    string a, b, c;
    while(cin >> a >> b >> c){

    	int l1 = a.length(), l2 = b.length(), l3 = c.length(); 
    	int n = max(l1, max(l2, l3));


    	hash_a[0] = hash_b[0] = hash_c[0] = 0;
    	FOR(i, 0, n){
    		if(i < l1) hash_a[i+1] = (hash_a[i] + (a[i] - 'a' + 1)*p_pow[i]) % MOD;
    		if(i < l2) hash_b[i+1] = (hash_b[i] + (b[i] - 'a' + 1)*p_pow[i]) % MOD;
    		if(i < l3) hash_c[i+1] = (hash_c[i] + (c[i] - 'a' + 1)*p_pow[i]) % MOD;
    	}

    	// a -> 0, b -> 1, c -> 2;
    	int max_substr01 = 0,
    		max_substr02 = 0,
    		max_substr10 = 0,
    		max_substr12 = 0,
    		max_substr20 = 0,
    		max_substr21 = 0;

    	
    	/*
		* 0 1 2
		* 0 2 1
		* 1 0 2
		* 1 2 0
		* 2 0 1
		* 2 1 0
		*
		* 0 1, 1 2, 0 2, 2 1, 1 0, 2 0 
    	*/


    	for(int l = min(l1, l2); l > 0; l--){
    		// 0 and 1
    		ll curr_h0 = (hash_a[l1] + MOD - hash_a[l1-l]) % MOD;
    		curr_h0 = (curr_h0 * p_pow[l-1]) % MOD;

    		ll curr_h1 = hash_b[l];
    		curr_h1 = (curr_h1 * p_pow[l2-1])%MOD;

    		cout << l << " " << l1-l << " " << a.substr(l1-l, l) << " " << b.substr(0, l) << " " << curr_h0 << " " << curr_h1 << "\n";

    		if(curr_h0 == curr_h1) max_substr01 = max(max_substr01, l);

    		// 1 and 0
    		curr_h1 = (hash_b[l2] + MOD - hash_b[l2-l]) % MOD;
    		curr_h1 = (curr_h1 * p_pow[l-1]) % MOD;

    		curr_h0 = (hash_a[l] + MOD - hash_a[0]) % MOD;
    		curr_h0 = (curr_h0 * p_pow[l1-1]) % MOD;

    		// cout << a.substr(0, l) << " " << b.substr(l2-l, l) << " " << curr_h0 << " " << curr_h1 << "\n";

    		if(curr_h0 == curr_h1) max_substr10 = max(max_substr10, l);
    	}
    	
    	for(int l = min(l1, l3); l > 0; l--){
	    	// 0 and 2
    		ll curr_h0 = (hash_a[l1] + MOD - hash_a[l1-l]) % MOD;
    		curr_h0 = (curr_h0 * p_pow[l-1]) % MOD;

    		ll curr_h2 = (hash_c[l] + MOD - hash_c[0]) % MOD;
    		curr_h2 = (curr_h2 * p_pow[l2-1])%MOD;

    		if(curr_h0 == curr_h2) max_substr02 = max(max_substr02, l);

    		// 2 and 0
    		curr_h2 = (hash_c[l3] + MOD - hash_c[l3-l]) % MOD;
    		curr_h2 = (curr_h2 * p_pow[l-1]) % MOD;

    		curr_h0 = (hash_a[l] + MOD - hash_a[0]) % MOD;
    		curr_h0 = (curr_h0 * p_pow[l1-1]) % MOD;

    		if(curr_h0 == curr_h2) max_substr20 = max(max_substr20, l);
    	}

    	for(int l = min(l2, l3); l > 0; l--){
    		// 1 and 2
    		ll curr_h1 = (hash_b[l2] + MOD - hash_b[l2-l]) % MOD;
    		curr_h1 = (curr_h1 * p_pow[l-1]) % MOD;

    		ll curr_h2 = (hash_c[l] + MOD - hash_c[0]) % MOD;
    		curr_h2 = (curr_h2 * p_pow[l3-1]) % MOD;

    		if(curr_h1 == curr_h2) max_substr12 = max(max_substr12, l);
	    	
	    	// 2 and 1
    		curr_h2 = (hash_c[l3] + MOD - hash_c[l3-l]) % MOD;
    		curr_h2 = (curr_h2 * p_pow[l-1]) % MOD;

    		curr_h1 = (hash_b[l] + MOD - hash_b[0]) % MOD;
    		curr_h1 = (curr_h1 * p_pow[l2-1])%MOD;

    		if(curr_h1 == curr_h2) max_substr21 = max(max_substr21, l);
    	}

    	cout << " Seq: 0 1 2 -> " << max_substr01 << " " << max_substr12 << "\n";
    	cout << " Seq: 0 2 1 -> " << max_substr02 << " " << max_substr21 << "\n";
    	cout << " Seq: 1 0 2 -> " << max_substr10 << " " << max_substr02 << "\n";
    	cout << " Seq: 1 2 0 -> " << max_substr01 << " " << max_substr12 << "\n";
    	cout << " Seq: 2 0 1 -> " << max_substr20 << " " << max_substr01 << "\n";
    	cout << " Seq: 2 1 0 -> " << max_substr21 << " " << max_substr10 << "\n";


    	// 0 1 2
    	int perm1 = l1-max_substr01 + l2 + l3-max_substr12;
    	// 0 2 1
    	int perm2 = l1-max_substr02 + l3 + l2-max_substr21;
    	// 1 0 2
    	int perm3 = l2-max_substr10 + l1 + l3-max_substr02;
    	// 1 2 0
    	int perm4 = l2-max_substr12 + l3 + l1-max_substr20;
    	// 2 0 1
    	int perm5 = l3-max_substr20 + l1 + l2-max_substr01;
    	// 2 1 0
    	int perm6 = l3-max_substr21 + l2 + l1-max_substr10;

    	int ans = min(perm6, min(perm5, min(perm4, min(perm3, min(perm2, perm1)))));   
    	
    	cout << ans << "\n";
    }

    return 0;
}
