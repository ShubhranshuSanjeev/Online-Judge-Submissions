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
const int P = 53;

ll p_pow[MAX], mod_inv[MAX];
ll hash_str[MAX], hash_str_r[MAX];
bool is_palin[MAX], used[MAX];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int K, N;
    cin >> K >> N;

    p_pow[0] = 1;
    FOR(i, 1, N) p_pow[i] = (p_pow[i-1] * P) % MOD;

    vec1d(pii) beauty;
    unordered_map<ll, multiset<pii>> st, st_r;
    FOR(i, 0, K){

    	string s;
    	int b;
    	cin >> s >> b;

    	beauty.emplace_back(b, i);

    	ll curr_h = 0, curr_h_r = 0;
    	FOR(j, 0, N){
    		curr_h = (curr_h + (s[j]-'a'+1)*p_pow[j])%MOD;
    		curr_h_r = (curr_h_r + (s[N-j-1]-'a'+1)*p_pow[j])%MOD;
    	}

    	hash_str[i] = curr_h;
    	hash_str_r[i] = curr_h_r;


    	if(curr_h_r == curr_h) {
    		is_palin[i] = true;
	    	st[curr_h].insert({-b, i});
    	}
    	else {
    		is_palin[i] = false;
	    	st_r[curr_h_r].insert({-b, i});
    	}
    }

    sort(beauty.begin(), beauty.end(), greater<pii>());

    ll ans = 0;
    // bool cent_f = false;
    FOR(i, 0, K){
    	int b = beauty[i].first;
    	int p = beauty[i].second;
    	ll curr_h = hash_str[p], curr_h_r = hash_str_r[p];

    	if(b < 1) break;
    	if(used[p]) continue;

    	if(!is_palin[p]){
    		if(st_r.find(curr_h) != st_r.end() && !st_r[curr_h].empty()){
    			auto op = st_r[curr_h].begin();
    			if(b >= (*op).first){
    				ans += b-(*op).first;
    				
    				used[(*op).second] = true;
    				used[p] = true;
    				
    				st_r[curr_h].erase(op);
    				st_r[curr_h_r].erase({-b, p});
    			}
    		}
    	}
    	else {
    		// if(!cent_f){
    		// 	ans += b;
    		// 	used[p] = true;
    		// 	cent_f = true;

    		// 	st[curr_h].erase({-b, p});
    		// }
    		// else{

			auto op = st[curr_h].begin();
			if((*op).second == p) {
				if(st[curr_h].size() == 1){
					if(!cent_f){
						cent_f = true;
						ans += b;
						
						used[p] = true;
						st[curr_h].erase(op);
						// --c_pp;
					}
					continue;
				}
				++op;
			}

			if((-(*op).first) > -1 || ((-(*op).first) < 0 && cent_f)){
				ans += b-(*op).first;
				used[(*op).second] = true;
				used[p] = true;
				
				st[curr_h].erase(op);
				st[curr_h].erase({-b, p});
				// c_pp -= ans <= b ? 1 : 2;
			}
			else{
				cent_f = true;
				ans += b;
				
				used[p] = true;
				st[curr_h].erase({-b, p});
			}
    		// }
    	}
    }

    cout << ans << "\n";
    return 0;
}
