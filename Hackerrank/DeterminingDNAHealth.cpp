#include <cstdio>
#include <iostream>
#include <ios>
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

const ll MAX = 1000007;

struct TrieNode{
	bool is_leaf = false;

	ll link = -1;
	ll match_fail;
	
	vector<ll> matches;
	vector<ll> healths;
	map<char, ll> next;

	/*
	  ll parent;
	  char parent_ch;
	  map<char, ll> go;
	  TrieNode(ll p = -1, char ch = '$') : parent(p), parent_ch(ch) {} 
	*/
};

ll N, S;
string genes[MAX];
vec1d(TrieNode) trie(2);
ll health[MAX], max_hlt, min_hlt;

void add_string(string const& s, ll h_val, ll str_id){
	ll node = 1;
	for(char ch : s){
		if(trie[node].next.find(ch) == trie[node].next.end()){
			trie[node].next[ch] = trie.size();
			trie.emplace_back();
		}

		node = trie[node].next[ch]; 
	}

	trie[node].is_leaf = true;
	trie[node].matches.push_back(str_id);
	trie[node].healths.push_back(h_val);
}

void construct_fail_links(){
	trie[1].link = 0;
	
	queue<ll> q; q.push(1);
	while(!q.empty()){
		ll curr = q.front();
		q.pop();

		for(auto &entries: trie[curr].next){
			char ch = entries.first;
			ll nxt = entries.second;

			int suff = trie[curr].link;
			while(suff && !trie[suff].next.count(ch))
				suff = trie[suff].link;
			suff = suff ? trie[suff].next[ch] : 1;

			trie[nxt].link = suff;
			trie[nxt].match_fail = trie[suff].is_leaf ? suff : trie[suff].match_fail;

			q.push(nxt); 
		}
	}
}



/* Recursive approach to generate fail links on the fly
ll go(ll node, char ch);

ll get_link(ll node){
	if(trie[node].link == -1){
		if(node == 1)
			trie[node].link = 0;
		else if(trie[node].parent == 1)
			trie[node].link = 1;
		else
			trie[node].link = go(get_link(trie[node].parent), trie[node].parent_ch);
	}

	return trie[node].link;
}

ll go(ll node, char ch){
	if(trie[node].go.find(ch) == trie[node].go.end()){
		if(trie[node].next.find(ch) != trie[node].next.end())
			trie[node].go[ch] = trie[node].next[ch];
		else
			trie[node].go[ch] = node == 1 ? 1 : go(get_link(node), ch);
	}

	return trie[node].go[ch];
}
*/

void search(string const& s, ll l, ll r){
	ll node = 1, len = s.length();
	ll t_hlt = 0;
	for(ll i = 0; i < len; i++){
		
		while(node && !trie[node].next.count(s[i]))
			node = trie[node].link;
		node = node ? trie[node].next[s[i]] : 1;

		// node = go(node, s[i]);

		for (ll v = node; v; v = trie[v].match_fail) {
	      	if (trie[v].is_leaf){
	        	for(auto x = lower_bound(trie[v].matches.begin(), trie[v].matches.end(), l);
	        		x != trie[v].matches.end() && *x <= r; ++x){
	        		t_hlt += trie[v].healths[distance(trie[v].matches.begin(), x)];
	        	}
	      	}
	    }
	}
	max_hlt = max(max_hlt, t_hlt);
	min_hlt = min(min_hlt, t_hlt);
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
    for(ll i = 0; i < N; ++i) cin >> genes[i];
    for(ll i = 0; i < N; ++i) cin >> health[i];
    for(ll i = 0; i < N; ++i) add_string(genes[i], health[i], i);

    max_hlt = INT64_MIN;
    min_hlt = INT64_MAX;
    
    construct_fail_links();

    cin >> S;
    for(ll i = 0; i < S; i++){
    	ll l, r; cin >> l >> r;
    	string dna; cin >> dna;
    	
    	search(dna, l, r);
    }
    cout << min_hlt << " " << max_hlt;
    return 0;
}
