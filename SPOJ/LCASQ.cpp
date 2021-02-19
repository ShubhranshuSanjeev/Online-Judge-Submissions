#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
using namespace std;

const int MAX = 100007;
const int MAX2 = MAX << 2;
const int LOGN = 17;

int timer;
vec1d(int) adj[MAX];
vec1d(int) height, tin, euler;
vec1d(int) seg_tree;


void build_seg_tree(int idx, int l, int h){
    if(l == h){
        seg_tree[idx] = euler[l];
        return;
    }

    divide(l, h, idx);
    build_seg_tree(lc, l, mid);
    build_seg_tree(rc, mid+1, h);

    seg_tree[idx] = height[seg_tree[lc]] < height[seg_tree[rc]] ? seg_tree[lc] : seg_tree[rc];
}

int query_seg_tree(int idx, int l, int h, int ql, int qh){
    if(l > h || l > qh || h < ql){
        return -1;
    }
    if(l >= ql && h <= qh){
        return seg_tree[idx];
    }

    divide(l, h, idx);    
    int a = query_seg_tree(rc, mid+1, h, ql, qh);
    int b = query_seg_tree(lc, l, mid, ql, qh);
    
    if(a == -1) return b;
    if(b == -1) return a;

    return (height[a] < height[b] ? a : b);
}

int get_lca(int u, int v){
    if(tin[u] > tin[v]){
        swap(u, v);        
    }
    // printf("%d %d\n", tin[u], tin[v]);
    return query_seg_tree(1, 0, euler.size()-1, tin[u], tin[v]);
}

void dfs(int u, int p = -1, int h = 0){
    height[u] = h;
    tin[u] = euler.size();
    euler.emplace_back(u);

    for(int v: adj[u]){
        if(v != p){
            dfs(v, u, h+1);
            euler.emplace_back(u);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int N, Q; scanf("%d", &N);

    timer = 0;
    height.resize(N+1);
    tin.resize(N+1);
    FOR(u, 0, N){
        int M, v;
        scanf("%d", &M);
        FOR(i, 0, M){
            scanf("%d", &v);
            adj[u].emplace_back(v);
        }
    }

    dfs(0);
    seg_tree.resize(euler.size() << 2);
    build_seg_tree(1, 0, euler.size()-1);

    scanf("%d", &Q);
    FOR(i, 0, Q){
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", get_lca(u, v));
    }
    return 0;
}