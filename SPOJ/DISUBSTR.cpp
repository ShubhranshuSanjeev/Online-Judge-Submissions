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

const int MAX = 1000007;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T; cin >> T;
    while(T--){
    	string s; cin >> s;
    	s += '$';

    	int N = s.length(), alphabets = 256;
    	vec1d(int) suffix_array(N);
    	vec1d(int) equi_class(N);
    	vec1d(int) cnt(max(alphabets, N), 0);

    	FOR(i, 0, N) cnt[s[i]]++;
    	FOR(i, 1, alphabets) cnt[i] += cnt[i-1];
    	FOR(i, 0, N) suffix_array[--cnt[s[i]]] = i;

    	equi_class[suffix_array[0]] = 0;
    	int classes = 1;
    	FOR(i, 1, N){
    		if(s[suffix_array[i]] != s[suffix_array[i-1]])
    			classes++;
    		equi_class[suffix_array[i]] = classes-1;
    	}


    	vec1d(int) pn(N);
    	vec1d(int) cn(N);
    	for(int k = 0; (1 << k) < N; k++){
    		FOR(i, 0, N){
    			pn[i] = (suffix_array[i] - (1<<k) + N) % N;
    		}

    		fill(cnt.begin(), cnt.begin()+classes, 0);
    		FOR(i, 0, N) cnt[equi_class[pn[i]]]++;
    		FOR(i, 1, classes) cnt[i] += cnt[i-1];
    		FORS(i, N-1, -1, -1) suffix_array[--cnt[equi_class[pn[i]]]] = pn[i];

    		cn[suffix_array[0]] = 0;
    		classes = 1;
    		FOR(i, 1, N){
    			pii a = make_pair(equi_class[suffix_array[i]], equi_class[ (suffix_array[i] + (1 << k)) % N ]);
    			pii b = make_pair(equi_class[suffix_array[i-1]], equi_class[ (suffix_array[i-1] + (1 << k)) % N ]);

    			if(a != b)
    				classes++;
    			cn[suffix_array[i]] = classes-1;
    		}

    		equi_class.swap(cn);
    	}

    	suffix_array.erase(suffix_array.begin());
    	N--;

    	vec1d(int) lcp(N, 0);
    	vec1d(int) rank(N, 0);

    	FOR(i, 0, N){
    		rank[suffix_array[i]] = i;
    	}

    	int k = 0;
    	FOR(i, 0, N){
    		if(rank[i] == N-1){
    			k = 0;
    			continue;
    		}

    		int j = suffix_array[rank[i]+1];
    		while(i+k < N && j+k < N && s[i+k] == s[j+k])
    			k++;

    		lcp[rank[i]+1] = k;
    		if(k) k--;
    	}

    	ll tt_sub_cnt = 0;
    	FOR(i, 0, N){
    		int suff_len = N - suffix_array[i];
    		ll sub_cnt = suff_len - lcp[i];
    		// cout << s.substr(suffix_array[i], N) << " " << lcp[i] << " " << sub_cnt << "\n";

    		tt_sub_cnt += sub_cnt; 
    	}

    	cout << tt_sub_cnt << "\n";
    }

    return 0;
}
