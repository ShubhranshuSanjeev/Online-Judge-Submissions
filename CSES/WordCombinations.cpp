#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <bitset>
#include <unordered_set>
 
#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>
 
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for(int i = int(st); i != int(ed); i += step)
#define FOREACH(it, ds) for(auto it = ds.begin(); it != ds.end(); ++it)
 
using namespace std;
 
const int MAX = 5007;
const ll MOD = (ll)1e9 + 7;
 
int N, K;
ll dp[MAX];
string text;
 
struct Vertex {
    bool is_leaf;
    vector<int> next;
 
    Vertex() {
        is_leaf = false;
        next.assign(26, -1);
    }
};
 
vector<Vertex> trie(1);
 
void add_string(const string& s){
    int i = 0;
    for(char c: s){
        if(trie[i].next[c - 'a'] == -1){
            trie[i].next[c - 'a'] = trie.size();
            trie.emplace_back();
        }
        i = trie[i].next[c - 'a'];
    }
    trie[i].is_leaf = true;
}
 
ll search(int st){
    ll ans = 0;
    int v = 0;
    FOR(i, st, text.length()){
        if(trie[v].next[text[i] - 'a'] == -1) return ans;
        v = trie[v].next[text[i] - 'a'];
        
        if(trie[v].is_leaf) {
            ans = (ans + dp[i+1]) % MOD;
        }
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    cin >> text;
    cin >> N;
    FOR(i, 0, N) {
        string word; cin >> word;
        add_string(word);
    }
 
    dp[text.size()] = 1;
    FORS(i, text.size()-1, -1, -1){
        dp[i] = search(i);
    }
    
    cout << dp[0] << "\n";
    return 0;
}