#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>

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
const int MAX2 = MAX << 2;
const int LOGN = 17;

vec1d(int) adj[MAX], cost[MAX];

int timer, chain_count;
int node_depth[MAX], node_chain_id[MAX];
int node_subtree_size[MAX], node_position_in_base[MAX];
int parent[LOGN][MAX], chain_head[MAX], base_array[MAX];

struct EDGE_WEIGHT_SEG_TREE_NODE{
    int min_path;
    int max_path;
};

EDGE_WEIGHT_SEG_TREE_NODE wt_seg_tree[MAX2];
EDGE_WEIGHT_SEG_TREE_NODE wt_query_tree[MAX2];

void build_wt_seg_tree(int l, int h, int idx){
    if(l == h){
        wt_seg_tree[idx] = (EDGE_WEIGHT_SEG_TREE_NODE) {base_array[l], base_array[l]};
        return;
    }
    divide(l, h, idx);
    build_wt_seg_tree(l, mid, lc);
    build_wt_seg_tree(mid+1, h, rc);
    wt_seg_tree[idx].max_path = max(wt_seg_tree[lc].max_path, wt_seg_tree[rc].max_path);
    wt_seg_tree[idx].min_path = min(wt_seg_tree[lc].min_path, wt_seg_tree[rc].min_path);
}

void query_wt_seg_tree(int l, int h, int idx, int ql, int qh){
    if(l > h || l > qh || h < ql) {
        wt_query_tree[idx] = (EDGE_WEIGHT_SEG_TREE_NODE) {INT32_MAX, INT32_MIN};
        return;
    }

    if(l >= ql && h <= qh) {
        wt_query_tree[idx] = (EDGE_WEIGHT_SEG_TREE_NODE){wt_seg_tree[idx].min_path, wt_seg_tree[idx].max_path};
        return;
    } 

    divide(l, h, idx);
    query_wt_seg_tree(l, mid, lc, ql, qh);
    query_wt_seg_tree(mid+1, h, rc, ql, qh);
    wt_query_tree[idx].min_path = min(wt_query_tree[lc].min_path, wt_query_tree[rc].min_path);
    wt_query_tree[idx].max_path = max(wt_query_tree[lc].max_path, wt_query_tree[rc].max_path);
}

pii query_up(int u, int v){
    int u_chain, v_chain = node_chain_id[v];
    int max_edge_wt = INT32_MIN, min_edge_wt = INT32_MAX;
    EDGE_WEIGHT_SEG_TREE_NODE* res;

    while(true){
        u_chain = node_chain_id[u];
        if(u_chain == v_chain){
            if(u == v) break;

            query_wt_seg_tree(0, timer, 1, node_position_in_base[v]+1, node_position_in_base[u]);
            max_edge_wt = max(max_edge_wt, wt_query_tree[1].max_path);
            min_edge_wt = min(min_edge_wt, wt_query_tree[1].min_path);
            break;
        }

        query_wt_seg_tree(0, timer, 1, node_position_in_base[chain_head[u_chain]], node_position_in_base[u]);
        max_edge_wt = max(max_edge_wt, wt_query_tree[1].max_path);
        min_edge_wt = min(min_edge_wt, wt_query_tree[1].min_path);
        u = parent[0][chain_head[u_chain]];
    }
    return make_pair(min_edge_wt, max_edge_wt);
}

int LCA(int u, int v){
	int log, tmp;
	if(node_depth[u] < node_depth[v])
		tmp = u, u = v, v = tmp;
 
	for(log = 0; (1 << log) <= node_depth[u]; log++);
	log--;
 
	for(int i = log; i >= 0; i--)
		if(node_depth[u]-node_depth[v] >= 1<<i)
			u = parent[i][u];
 
	if(u == v) return u;
 
	for(int i = log; i >= 0; i--)
		if(parent[i][u] != -1 && parent[i][u] != parent[i][v])
			u = parent[i][u], v = parent[i][v];
 
	return parent[0][u];
}


void query(int u, int v){
    if(u == v){
        printf("0 0\n");
        return;
    }

    int lca = LCA(u, v);
    pii a = query_up(u, lca);
    pii b = query_up(v, lca);
    printf("%d %d\n", min(b.first, a.first), max(b.second, a.second));
}

void HLD(int u, int prev_node = -1, int traversed_edge_wt = -1){
    if(chain_head[chain_count] == -1) {
        chain_head[chain_count] = u;
    }
    node_chain_id[u] = chain_count;
    node_position_in_base[u] = timer;
    base_array[timer++] = traversed_edge_wt;

    int heavy_node = -1, heavy_edge_wt = 0;
    FOR(i, 0, adj[u].size()){
        if(adj[u][i] != prev_node){
            int v = adj[u][i];
            if(heavy_node == -1 || node_subtree_size[heavy_node] < node_subtree_size[v]){
                heavy_node = v;
                heavy_edge_wt = cost[u][i];
            }
        }
    }

    if(heavy_node != -1){
        HLD(heavy_node, u, heavy_edge_wt);
    }

    FOR(i, 0, adj[u].size()){
        if(adj[u][i] != prev_node && adj[u][i] != heavy_node){
            chain_count++;
            HLD(adj[u][i], u, cost[u][i]);
        }
    }
}

void dfs(int u, int p = -1, int h = 0){
    parent[0][u] = p;
    node_depth[u] = h;
    node_subtree_size[u] = 1;

    FOR(i, 0, adj[u].size()){
        int v = adj[u][i];
        if(v != p){
            dfs(v, u, h+1);
            node_subtree_size[u] += node_subtree_size[v];
        }   
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int N, K;
    scanf("%d", &N);
    
    timer = 0;
    chain_count = 0;
    for(int i = 0; i <= N; i++){
        chain_head[i] = -1;
        for(int j = 0; j < LOGN; j++) {
            parent[j][i] = -1;
        }
    }
    FOR(i, 1, N){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v);
        cost[u].emplace_back(w);

        adj[v].emplace_back(u);
        cost[v].emplace_back(w);
    }

    dfs(1);
    HLD(1);

    timer--;
    build_wt_seg_tree(0, timer, 1);
    
    for(int i = 1; (1 << i) < N; i++){
        for(int j = 0; j <= N; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }

    scanf("%d", &K);
    FOR(i, 0, K){
        int u, v;
        scanf("%d %d", &u, &v);
        query(u, v);
    }
    return 0;
}