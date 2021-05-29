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

const int P = 56;
const int MAX = 200011;
const int MOD = 1000000009;

ll p_pow[MAX], str_hash[MAX];
int N;

char s[MAX];

ll get_substr_hash(int st, int ed){
	return (str_hash[ed] - str_hash[st]*p_pow[st] + MOD ) % MOD;
}

int get_lcp(int i, int j, int k, int l){
	int L = 0;
	int R = l+1;
	while(R-L > 1){
		int M = (L + R) >> 1;
		if(k+M >= N) continue;

		int m_hash = get_substr_hash(j, j+M);
		int l_hash = get_substr_hash(i, i+M);
		int r_hash = get_substr_hash(k, k+M);

		if(m_hash == l_hash && l_hash == r_hash) L = M;
		else R = M;
	}

	return L;
}

int get_lcs(int i, int j, int k, int l){
	int L = 0;
	int R = l+1;

	while(R-L > 1){
		int M = (L + R) >> 1;
		if(i-M < 0) continue;

		int m_hash = get_substr_hash(j-M, j+1);
		int l_hash = get_substr_hash(i-M, i+M);
		int r_hash = get_substr_hash(k, k+M);

	}
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    p_pow[0] = 1;
    FOR(i, 1, MAX) p_pow[i] = (p_pow[i-1]*P)%MOD;

    scanf("%s", s);
    N = strlen(s);

    str_hash[0] = 0;
    FOR(i, 0, N){
    	str_hash[i+1] = (str_hash[i] + p_pow[i]*(s[i]-'a'+1)) % MOD;	
    }

    FOR(l, 1, N/3){
    	FOR(i, 0, N-2*l){
    		int j = i+l;
    		int k = j+l;

    		int _lcp = get_lcp(i, j, k, l);
    		int _lcs = get_lcs(i, j, k, l);
    	}
    }

    return 0;
}
