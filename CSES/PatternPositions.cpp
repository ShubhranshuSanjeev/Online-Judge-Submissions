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

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for(int i = int(st); i != int(ed); i += step)
#define FOREACH(it, ds) for(auto it = ds.begin(); it != ds.end(); ++it)

using namespace std;

const int MAX = 500007;
string str;
vector<int> patterns;

struct trieNode {
    bool is_leaf;
    bool visited;

    int link;
    int parent;
    char parent_ch;

    vector<int> next;
    vector<pii> matches;
    vector<int> go;

    trieNode(int pid = -1, char pch = '$') {
        is_leaf = visited = false;
        link = -1;
        parent = pid; parent_ch = pch;

        next.assign(26, -1);
        go.assign(26, -1);
    }
};

vector<trieNode> trie(1);

void add_string(string const& s, int str_idx){
    int idx = 0;
    FOREACH(it, s){
        char c = *it;
        int cidx = c-'a';
        if(trie[idx].next[cidx] == -1) {
            trie[idx].next[cidx] = trie.size();
            trie.emplace_back(idx, c);
        }
        idx = trie[idx].next[cidx];
    }
    trie[idx].is_leaf = true;
    trie[idx].matches.emplace_back(str_idx, (int)s.size());
}

int go(int v, char c);
int get_link(int v){
    if(trie[v].link == -1){
        if(v == 0 || trie[v].parent == 0){
            trie[v].link = 0;
        } else {
            trie[v].link = go(get_link(trie[v].parent), trie[v].parent_ch);
        }
    }

    return trie[v].link;
}

int go(int v, char c){
    int cidx = c-'a';
    if(trie[v].go[cidx] == -1){
        if(trie[v].next[cidx] != -1){
            trie[v].go[cidx] = trie[v].next[cidx];
        } else {
            trie[v].go[cidx] = v == 0 ? 0 : go(get_link(v), c);
        }
    }

    return trie[v].go[cidx];
}

void search(){
    int idx = 0;
    FOR(i, 0, str.size()){
        char c = str[i];
        idx = go(idx, c);
        for(int v = idx; v != -1 && !trie[v].visited; v = get_link(v)){
            trie[v].visited = true;
            if(trie[v].is_leaf){
                FOREACH(match, trie[v].matches){
                    patterns[match->first] = i-match->second+2;
                }
            }
        }
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

    int pattern_count;
    cin >> str;
    cin >> pattern_count;
    FOR(i, 0, pattern_count){
        string pattern; cin >> pattern;
        add_string(pattern, i);
    }
    patterns.assign(pattern_count, -1);
    search();
    FOREACH(it, patterns){
        cout << (*it) << "\n";
    }
    return 0;
}