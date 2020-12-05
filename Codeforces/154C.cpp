#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <limits>
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
const int P = 1001;
const int MOD = 1000000009;

int u[MAX], v[MAX];
ll hashes[MAX];

ll hash_int(int n){
	ll hash_n = 1;
	ll p_pow = P;
	while(n){
		if(n&1)
			hash_n = (hash_n * p_pow);
		p_pow = (p_pow*p_pow);
		n = n >> 1;
	}
	return hash_n;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int N, M;

    cin >> N >> M;

    memset(hashes, 0, sizeof(hashes));

    FOR(i, 0, M){
    	cin >> u[i] >> v[i];
    	hashes[u[i]] = (hashes[u[i]] + hash_int(v[i])) ;
    	hashes[v[i]] = (hashes[v[i]] + hash_int(u[i])) ;
    }

    ll ans = 0;
    FOR(i, 0, M){
    	if((hashes[u[i]] + hash_int(u[i])) == (hashes[v[i]] + hash_int(v[i])))
    		ans++;
    }

    hashes[0] = INT64_MAX;
    sort(hashes, hashes+(N+1));
    int match = 1;
    FOR(i, 1, N){
    	if(hashes[i] == hashes[i-1]){
    		match++;
    		continue;
    	}

    	ans += 1LL*match*(match-1)/2;
    	match=1; 
    }

    ans += 1LL*match*(match-1)/2;
    cout << ans << "\n";

    return 0;
}
