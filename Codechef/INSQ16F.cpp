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
#define FORS(i, st, ed, step) for(int i = int(st); i != int(ed); i+=step)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
using namespace std;

const int MAX = 100007;
int N, t_len;
string all;
vec1d(string) str(MAX);
vec1d(int) p, lcp, inv_suff_map, str_pos;

void construct_suff_array(){
	int alphabets = 256;

	p.resize(t_len);
	vec1d(int) c(t_len);
	vec1d(int) cnt(max(alphabets, t_len), 0);

	FOR(i, 0, t_len) cnt[all[i]]++;
	FOR(i, 1, alphabets) cnt[i] += cnt[i-1];
	FOR(i, 0, t_len) p[--cnt[all[i]]] = i;

	c[p[0]] = 0;
	int classes = 1;
	FOR(i, 1, t_len){
		if(all[p[i]] != all[p[i-1]])
			classes++;
		c[p[i]] = classes-1;
	}


	vec1d(int) pn(t_len), cn(t_len);
	for(int k = 0; (1 << k) < t_len; k++){
		FOR(i, 0, t_len) pn[i] = (p[i] - (1 << k) + t_len)%t_len;

		fill(cnt.begin(), cnt.begin()+classes, 0);
		FOR(i, 0, t_len) cnt[c[pn[i]]]++;
		FOR(i, 1, classes) cnt[i] += cnt[i-1];
		FORS(i, t_len-1, -1, -1) p[--cnt[c[pn[i]]]] = pn[i];

		cn[p[0]] = 0;
		classes = 1;
		FOR(i, 1, t_len){
			pii a = make_pair(c[p[i]], c[(p[i] + (1 << k)) % t_len]);
			pii b = make_pair(c[p[i-1]], c[(p[i-1] + (1 << k)) % t_len]);

			if(a != b)
				classes++;
			cn[p[i]] = classes-1;
		}
		c.swap(cn);
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N;
    FOR(i, 0, N){ 
    	cin >> str[i];
    }

    all = str[0];
    FOR(i, 1, N){
    	all += '#';
    	all += str[i];
    }
    t_len = all.length();

    construct_suff_array();
    
    int k = 0;
    inv_suff_map.resize(t_len); lcp.resize(t_len, 0); str_pos.resize(N);
    FOR(i, 0, t_len) inv_suff_map[p[i]] = i;
    FOR(i, 0, t_len) {
    	if(inv_suff_map[i] == t_len-1){
    		k = 0;
    		continue;
    	}

    	int j = p[inv_suff_map[i] + 1];
    	while(i+k < t_len && j < t_len && all[i+k] == all[j+k] && all[i+k] != '#')
    		k++;

    	lcp[inv_suff_map[i]+1] = k;
    	if(k) k--;
    }

    for(int curr = 0, i = 0; i < N; i++){
    	str_pos[i] = inv_suff_map[curr];
    	curr += str[i].length()+1;
    }

    int Q; cin >> Q;
    while(Q--){
    	int a, b; cin >> a >> b;
    	--a; --b;

    	int pos_a = str_pos[a], 
    		pos_b = str_pos[b];

    	
    }
    return 0;
}
