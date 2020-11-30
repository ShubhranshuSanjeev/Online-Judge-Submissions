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

const int MAX = 300007;

int n, m;
ll ans[MAX], lvl[MAX];
vector<int> adj[MAX];
vector<pii> q[MAX];

void dfs(int u, int prev, int dep, ll s){
    for(auto &p: q[u]){
        int l = dep, r = dep + p.first;
        lvl[l] += p.second;
        if((r+1) < n) lvl[r+1] -= p.second;
    }

    s += lvl[dep];
    ans[u] = s;

    for(auto &v: adj[u]){
        if(v != prev)
            dfs(v, u, dep+1, s);
    }

    for(auto &p: q[u]){
        int l = dep, r = dep + p.first;
        lvl[l] -= p.second;
        if((r+1) < n) lvl[r+1] += p.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    FOR(i, 0, n-1){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> m;
    while(m--){
        int v,d,x;
        cin >> v >> d >> x;

        q[v].push_back({d, x});
    }

    memset(lvl, 0, sizeof(lvl));
    dfs(1, 1, 0, 0);

    FOR(i, 1, n+1){
        cout << ans[i] << " ";
    }
    cout << "\n";

    
    return 0;
}