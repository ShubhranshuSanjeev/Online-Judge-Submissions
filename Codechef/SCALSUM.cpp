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
#include <unordered_set>
#include <chrono>

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
#define MAX 300007
using namespace std;

const int K = 80, INF = 0x3f3f3f3f;
unsigned int wt[MAX], val[MAX]; 
int depth[MAX], pa[MAX], num[MAX];
bool visited[MAX];
vec1d(int) adj[MAX];
vec2d(int) vert;
vec1d(unsigned int) memo[MAX];

void dfs(int u, int h = 0, int prev = 1){
    val[u] = val[prev] + (wt[u] * wt[u]);
    depth[u] = h;
    
    if(vert.size() == h) vert.push_back({});
    vert[h].push_back(u);

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v != prev){
            pa[v] = u;
            dfs(v, h+1, u);
        }
    }
}

unsigned int query(int u, int v){
    unsigned int ans = 0;
    while(u != v && !visited[u]){
        ans = ans + (wt[u]*wt[v]);
        u = pa[u];
        v = pa[v];
    }

    if(u == v) ans = ans + val[u];
    else ans = ans + memo[depth[u]][num[u]*(int)vert[depth[u]].size()+num[v]];

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    int N, Q, u, v;
    cin >> N >> Q;

    FOR(i, 1, N+1){
        cin >> wt[i];
    }
    FOR(i, 1, N){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    val[1] = 0;
    dfs(1);
    vert.push_back({});

    for(int i = 0; i < vert.size(); i+=K){
        pii best = {INF, INF};  
        FOR(j, i, min(i+K, (int)vert.size())){
            best = min(best, {vert[j].size(), j});
        }

        int id = 0;
        for(auto &x: vert[best.second]){
            num[x] = id++;
        }

        for(auto &x: vert[best.second])
            for(auto &y: vert[best.second]){
                if(num[x] <= num[y]) memo[best.second].push_back(query(x, y));
                else memo[best.second].push_back(memo[best.second][num[y]*id+num[x]]);
            }
        
        for(auto &x: vert[best.second]) visited[x] = true;
    }

    FOR(i, 0, Q) {
        cin >> u >> v;
        cout << query(u, v) << "\n";
    }
    return 0;
}


/* *TLE Implementation

struct Query{
    int from, to, pos, dep;
    Query(int a, int b, int c, int d) : from(a), to(b), pos(c), dep(d){}
};
bool compare(Query q1, Query q2){
    return q1.dep < q2.dep;
}

const ll MOD = (ll)1 << 32;
const ll MUL = 10000000;
int wt[MAX], depth[MAX], pa[MAX];
vec1d(int) adj[MAX];
vec1d(Query) queries;
ll val[MAX];

void dfs(int u, int h = 0, int prev = 1){
    val[u] = (val[prev] + ((ll)wt[u] * wt[u])%MOD)%MOD;
    depth[u] = h;
    
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v != prev){
            pa[v] = u;
            dfs(v, h+1, u);
        }
    }
}

int main(){
    int N, Q, u, v;
    scanf("%d %d", &N, &Q);

    FOR(i, 1, N+1){
        scanf("%d", &wt[i]);
    }
    FOR(i, 1, N){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    val[1] = 0;
    dfs(1);

    FOR(i, 0, Q) {
        scanf("%d %d", &u, &v);
        queries.push_back((Query){u, v, i, depth[u]});
    }
    sort(queries.begin(), queries.end(), compare);

    ll res[MAX], ans;
    pii k;
    unordered_map<pii, ll> dp;
    FOR(i, 0, Q){
        u = queries[i].from, v = queries[i].to;
        int p = queries[i].pos;
        ans = 0;

        int a = u, b = v;
        while (true){
            if(a < b){
                int tmp = a;
                a = b;
                b = tmp;
            }
            
            k = make_pair(a, b);
            if(dp.count(k)){
                ans = (ans + dp[k])%MOD;
                break;
            }
            if(a == b) {
                ans = (ans + val[a])%MOD;
                break;
            }
            ans = (ans + ((ll)wt[a] * wt[b])%MOD)%MOD;
            a = pa[a];
            b = pa[b];
        }
        if(u < v){
            int tmp = u;
            u = v;
            v = tmp;
        }
        if(u < v){
            int tmp = u;
            u = v;
            v = tmp;
        }
        k = make_pair(u, v);
        dp.insert(make_pair(k, ans));
        res[p] = ans;
    }

    FOR(i, 0, Q){
        printf("%lld\n", res[i]);
    }
    return 0;
}

*/