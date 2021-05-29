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

int timer, lgn, cns;
vector<pair<int,ll>> adj[MAX];
vec1d(int) tin, tout;
vec2d(int) pa;

void dfs(int u, int p){
    tin[u] = ++timer;
    pa[u][0] = p;
    FOR(i, 1, lgn+1){
        pa[u][i] = pa[pa[u][i-1]][i-1];
    }
    for(pii v: adj[u]){
        if(v.first != p){
            dfs(v.first, u);
        }
    }
    tout[u] = ++timer;
}

int get_lca(int u, int v){
    if(tin[u] <= tin[v] && tout[u] >= tout[v]){
        return u;
    }
    if(tin[v] <= tin[u] && tout[v] >= tout[u]){
        return v;
    }

    for(int i = lgn; i >= 0; --i){
        if(!(tin[pa[u][i]] <= tin[v] && tout[pa[u][i]] >= tout[v])){
            u = pa[u][i];
        }
    }
    return pa[u][0];
}

void dfs1(int s, int e, int p, ll c){
    if(s == e){
        cns = c;
        return;
    }
    for(pii v: adj[s]){
        if(v.first != p){
            dfs1(v.first, e, s, c+v.second);
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

    int T,N,Q,R;
    cin >> T;
    while(T--){
        cin >> N >> Q >> R;

        FOR(i, 0, N+1){
            adj[i].clear();
        }
        lgn = ceil(log2(N+1));
        timer = 0;
        tin.resize(N+1);
        tout.resize(N+1);
        pa.assign(N+1, vec1d(int)(lgn));

        FOR(i, 1, N){
            int u, v;
            ll w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        dfs(R,R);
        FOR(i, 0, Q){
            int u, v;
            cin >> u >> v;
            int lca = get_lca(u, v);
            dfs1(lca, u, lca, (ll)0);
            ll ans = cns;
            dfs1(lca, v, lca, (ll)0);
            ans += cns;
            cout << ans << "\n";
        }
    }

    return 0;
}