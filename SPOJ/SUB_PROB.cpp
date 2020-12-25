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
#define pii pair<int, int>
#define pll pair<ll, ll>

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define ivec1d(x, n, v) vec1d(x)(n, v)
#define ivec2d(x, n, m, v) vec2d(x)(n, ivec1d(x, m, v))
#define ivec3d(x, n, m, k, v) vec3d(x)(n, ivec2d(x, m, k, v))
#define ivec4d(x, n, m, k, l, v) vec4d(x)(n, ivec3d(x, m, k, l, v))

#define FOR(i, st, ed) for (int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h) >> 1, lc = idx << 1, rc = lc | 1;
using namespace std;

const int MAX = 1000007;
const int MAXN = 1003;

int N, root, nodes;
bool found[MAXN];
string text, str[MAXN];

struct Vertex {
  bool is_leaf = false;
  bool visited = false;

  int link = -1;
  int parent = -1;
  char parent_ch;

  vector<int> matches;
  map<char, int> next;
  map<char, int> go;

  Vertex(int p = -1, char ch = '$') : parent(p), parent_ch(ch) {}
};

vector<Vertex> trie(1);

void add_string(string const &s, int str_id) {
  int v = 0;

  for (char c : s) {
    if (trie[v].next.find(c) == trie[v].next.end()) {
      trie[v].next[c] = trie.size();
      trie.emplace_back(v, c);
    }

    v = trie[v].next[c];
  }

  trie[v].is_leaf = true;
  trie[v].matches.push_back(str_id);
}

int go(int v, char c);

int get_link(int v) {

  if (trie[v].link == -1) {
    if (v == 0 || trie[v].parent == 0)
      trie[v].link = 0;
    else
      trie[v].link = go(get_link(trie[v].parent), trie[v].parent_ch);
  }

  return trie[v].link;
}

int go(int v, char c) {
  
    if (!trie[v].go.count(c)) {
    if (trie[v].next.count(c))
      trie[v].go[c] = trie[v].next[c];
    else
      trie[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
  }

  return trie[v].go[c];
}

void search() {
  int len = (int)text.length();
  for (int i = 0, st = 0; i < len; i++) {
    st = go(st, text[i]);
    for (int v = st; v != -1 && !trie[v].visited; v = trie[v].link) {
      trie[v].visited = true;

      if (trie[v].is_leaf)
        for (int str_id : trie[v].matches)
          found[str_id] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cin >> text;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> str[i];
    add_string(str[i], i);
  }

  search();
  for (int i = 0; i < N; i++)
  {
    cout << (found[i] ? 'Y' : 'N') << "\n";
  }
  return 0;
}
