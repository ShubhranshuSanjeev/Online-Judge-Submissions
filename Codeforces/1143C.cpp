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

int N, c[MAX];
vector<int> adj[MAX];
set<int> vert;

void dfs(int u){
    bool del = true & (c[u] == 1);
    for(auto &v : adj[u]){
        dfs(v);
        del &= c[v] == 1;
    }

    if(del) vert.insert(u);
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
    int root = 1;

    FOR(i, 1, N+1){
        int ci, pi;
        cin >> pi >> ci;
        
        if(pi == -1) root = i;
        else adj[pi].push_back(i);
        c[i] = ci;
    }

    dfs(root);
    for(auto &x : vert){
        cout << x << " ";
    }
    if(vert.size() == 0) 
        cout << -1;
    cout << "\n";
    return 0;
}