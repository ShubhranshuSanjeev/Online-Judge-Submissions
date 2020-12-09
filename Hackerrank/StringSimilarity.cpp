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

const int MAX = 1e5+7;
const int MOD = 1e9+9;
const int P = 53;

// ll p_pow[MAX], hash_s[MAX];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // p_pow[0] = 1;
    // FOR(i, 1, MAX) p_pow[i] = (p_pow[i-1] * P) % MOD;

	int T;
	cin >> T;
	
	while(T--){
		string s;
		cin >> s;

		int N = s.length();

		vec1d(int) z(N, 0);

		ll ans = N;
		for(int i = 1, l = 0, r = 0; i < N; i++){
			if(i <= r)
				z[i] = min(r-i+1, z[i-l]);

			while(i+z[i] < N && s[z[i]] == s[i+z[i]])
				++z[i];

			ans += z[i];

			if(i+z[i]-1 > r)
				l = i, r = i+z[i]-1;
		}

		/* String Hashing Implementation 
		hash_s[0]=0;
		FOR(i, 0, N) hash_s[i+1] = (hash_s[i] + (s[i]-'a'+1)*p_pow[i])%MOD;

		ll ans = N;
		FOR(i, 1, N){
			int max_len = 0;
			FOR(l, 1, N){
				ll curr_h0 = (hash_s[i+l] + MOD - hash_s[i])%MOD;
				curr_h0 = (curr_h0 * p_pow[N-i-1])%MOD;

				ll curr_h1 = (hash_s[l] * p_pow[N-1]) % MOD;

				if(curr_h0 != curr_h1) break;

				max_len = l;
			}
			ans+=max_len; 
		} */

		cout << ans << "\n";
	}        
    return 0;
}
