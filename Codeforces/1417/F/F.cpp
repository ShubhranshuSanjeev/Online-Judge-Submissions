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
#include <unordered_set>
#include <set>

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>

#define ivec1d(x, n, v) vec1d(x)(n, v)
#define ivec2d(x, n, m, v) vec2d(x)(n, ivec1d(x, m, v))
#define ivec3d(x, n, m, k, v) vec3d(x)(n, ivec2d(x, m, k, v))
#define ivec4d(x, n, m, k, l, v) vec4d(x)(n, ivec3d(x, m, k, l, v))

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
using namespace std;

const int MAXN = (int)5e5 + 5;

struct Edge{
    bool deleted;
    int from, to;
    Edge(bool a, int b, int c) : deleted(a), from(b), to(c) {}
};

int N, M, Q;
int P[MAXN], parent[MAXN], timer;
int tin[MAXN], tout[MAXN];
pii seg_tree[MAXN<<2];
vec1d(Edge) edges;
vec1d(int) adj[MAXN];
vec1d(pii) queries;

int find_set(int u){
    if(parent[u] == u) return u;
    return (parent[u] = find_set(parent[u]));
}

void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);

    if(u == v) return;

    parent[N] = parent[u] = parent[v] = N;
    adj[N].emplace_back(u);
    adj[N].emplace_back(v);
    N++;
}

void dfs(int u){
    tin[u] = timer++;
    for(int v : adj[u]){
        dfs(v);
    }
    tout[u] = timer;
}

pii query(int l, int h, int idx, int ql, int qh){
    if(l > h || l > qh || h < ql) return make_pair(0,0);
    if(l >= ql && h <= qh) return seg_tree[idx];

    divide(l, h, idx);
    return max(query(l, mid, lc, ql, qh), query(mid+1, h, rc, ql, qh));
}

void update_tree(int l, int h, int idx, int pos, pii val){
    if(l > h || l > pos || h < pos) return;
    if(l == h && l == pos){
        seg_tree[idx] = val;
        return;
    }

    divide(l, h, idx);
    if(pos <= mid) update_tree(l, mid, lc, pos, val);
    else update_tree(mid+1, h, rc, pos, val);

    seg_tree[idx] = max(seg_tree[lc], seg_tree[rc]);
}

int main(){
    // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("inp0.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int u, v, type, ei;

    scanf("%d %d %d", &N, &M, &Q);

    FOR(i, 0, N){
        scanf("%d", &P[i]);
        parent[i] = i;
    }

    FOR(i, 0, M){
        scanf("%d %d", &u, &v);
        --u; --v;
        edges.emplace_back(false, u, v);
    }

    FOR(i, 0, Q){
        scanf("%d %d", &type, &ei);
        --ei;
        queries.emplace_back(type, ei);
        if(type == 2)
            edges[ei].deleted = true;
    }

    for(auto& edge : edges){
        if(edge.deleted) continue;
        union_set(edge.from, edge.to);
    }

    for(int i = Q-1; i >= 0; i--){
        type = queries[i].first;
        if(type == 2){
            ei = queries[i].second;
            u = edges[ei].from, v = edges[ei].to;
            union_set(u, v);
        }
        else{
            queries[i].second = find_set(queries[i].second);
        }
    }

    timer = 0;
    FOR(i, 0, N){
        if(find_set(i) == i){
            dfs(i);
        }
    }

    FOR(i, 0, N){
        update_tree(0, N-1, 1, tin[i], make_pair(P[i], tin[i]));
    }

    FOR(i, 0, Q){
        type = queries[i].first;
        if(type == 1){
            u = queries[i].second;
            pii tmp = query(0, N-1, 1, tin[u], tout[u]);

            if(tmp.first == 0) printf("0\n");
            else {
                printf("%d\n", tmp.first);
                update_tree(0, N-1, 1, tmp.second, make_pair(0, 0));
            }
        }
    }

    return 0;
}