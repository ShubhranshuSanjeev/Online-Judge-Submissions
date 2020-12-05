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

const int MAX = 2000010;
const int MOD = 1000000009;
const int P1 = 53;
const int P2 = 71;

ll p_pow1[MAX], p_pow2[MAX];
ll mod_inv1[MAX], mod_inv2[MAX];
ll hash_str1[MAX], hash_str2[MAX];

ll binary_exp(ll base, ll power) {
    if(power == 0)
        return 1;
    ll ans = binary_exp(base, power/2);
    if(power%2)
        return (((ans*ans)%MOD)*base)%MOD;
    else
        return (ans*ans)%MOD;
}
 
ll mod_inverse(ll num) {
    return binary_exp(num, MOD - 2)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int N, K, G;
    string str_cd;

    cin >> N >> K;
    cin >> str_cd;

    string tmp = str_cd.substr(0, K);
    str_cd = str_cd+tmp;

    int len_cd = str_cd.length();

    p_pow1[0] = p_pow2[0] = 1;
    FOR(i, 1, len_cd){
    	p_pow1[i] = (p_pow1[i-1] * P1)%MOD;
    	p_pow2[i] = (p_pow2[i-1] * P2)%MOD;
    }

    FOR(i, 0, len_cd){
    	mod_inv1[i] = mod_inverse(p_pow1[i]);
    	mod_inv2[i] = mod_inverse(p_pow2[i]);
    }

    hash_str1[0]=hash_str2[0]=0;
    FOR(i, 0, len_cd){
    	hash_str1[i+1] = (hash_str1[i] + ((str_cd[i]-'a'+1)*p_pow1[i])%MOD)%MOD;
    	hash_str2[i+1] = (hash_str2[i] + ((str_cd[i]-'a'+1)*p_pow2[i])%MOD)%MOD;
    }

    cin >> G;

    map<pll, int> hash_games;
    FOR(i, 0, G){
    	string game;
    	cin >> game;

    	ll hash_g1, hash_g2;
    	hash_g1=hash_g2=0;

    	FOR(j, 0, K){
    		hash_g1 = (hash_g1+(game[j]-'a'+1)*p_pow1[j])%MOD;
    		hash_g2 = (hash_g2+(game[j]-'a'+1)*p_pow2[j])%MOD; 
    	}

    	pll hash_g = make_pair(hash_g1, hash_g2);

    	hash_games[hash_g] = i+1;
    }

    vec1d(pll) hash_subs;
    FOR(i, 0, len_cd-K+1){
    	ll curr_h1 = (hash_str1[i+K] + MOD - hash_str1[i]) % MOD;
    	curr_h1 = (curr_h1 * mod_inv1[i]) % MOD;

    	ll curr_h2 = (hash_str2[i+K] + MOD - hash_str2[i]) % MOD;
    	curr_h2 = (curr_h2 * mod_inv2[i]) % MOD;

    	pll curr_h = make_pair(curr_h1, curr_h2);
    	hash_subs.push_back(curr_h);
    }

    bool flag = false;
    map<pll, int> visited;
    int st = 0;
    FOR(i, 0, K){
    	st = i;

    	int match_count = 0;
    	int curr = i;
    	int l = hash_subs.size();
    	while(curr < l && match_count < N){
    		if(visited.find(hash_subs[curr]) != visited.end())
    			break;
    		if(hash_games.find(hash_subs[curr]) == hash_games.end())
    			break;

    		visited[hash_subs[curr]]++;
    		curr += K;
    		match_count++;
    	}

    	if(match_count == N && visited.size() == N){
    		flag = true;
    		break;
    	}

    	visited.clear();
    }

    if(!flag)
    	cout << "NO\n";
    else {
    	cout << "YES\n";
    	int curr = st, match_count = 0;
    	int l = hash_subs.size();
    	while(curr < l && match_count < N){
    		cout << hash_games[hash_subs[curr]] << " ";
    		curr+=K;
    		match_count++;
    	}
    }
    return 0;
}
