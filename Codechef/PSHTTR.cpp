#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(st, ed) for(int i = st; i < ed; i++)
#define forEach(ds) for(auto it = ds.begin(); it != ds.end(); it++)
#define MAX 100007
using namespace std;

struct query{
    int u, v, k, idx;
};

bool compareQuery(const query &a, const query &b){
    return a.k < b.k;
}

int T, N, M, pos;
vector<pair<int, int>> adj[MAX], edges;
vector<query> queries;
vector<int> seg_tree, lazy;
int last[MAX], first[MAX], ans[MAX];
int visited[MAX];

void propagate(int l, int h, int idx){
    if(lazy[idx] != 0){
        seg_tree[idx] ^= lazy[idx];
        if(l != h){
            lazy[idx << 1] ^= lazy[idx];
            lazy[idx << 1|1] ^= lazy[idx];
        }
        lazy[idx] = 0;
    }
}
void update_tree(int ql, int qh, int l, int h, int idx, int val){
    propagate(l, h, idx);
    if(l > h || l > qh || h < ql) return;
    if(l >= ql && h <= qh){
        lazy[idx] ^= val;
        propagate(l, h, idx);
        return;
    }

    int mid = (l+h)>>1, lc = idx<<1, rc = lc|1;
    update_tree(ql, qh, l, mid, lc, val);
    update_tree(ql, qh, mid+1, h, rc, val);
    seg_tree[idx] = seg_tree[rc]^seg_tree[lc];
}

int query(int l, int h, int ql, int qh, int idx){
    propagate(l, h, idx);
    if(l > h || l > qh || h < ql) return 0;
    if(l >= ql && h <= qh) return seg_tree[idx];

    int mid = (l+h)>>1, lc = idx<<1, rc = lc|1;
    int a = query(l, mid, ql, qh, lc);
    int b = query(mid+1, h, ql, qh, rc);

    return b^a;
}

void dfs(int u){
    visited[u] = 1;
    first[u] = pos++;

    forEach(adj[u]){
        int v = it->first;
        int c = it->second;
        if(!visited[v]) {
            edges.emplace_back(make_pair(c, v));
            dfs(v);
        }
    }
    last[u] = pos-1;
}

int main(){
    int u, v, c, k, idx, curr;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);

        pos = 0;
        seg_tree.clear();
        lazy.clear();
        queries.clear();
        edges.clear();
        FOR(0, N){
            adj[i].clear();
            visited[i] = 0;
        }

        FOR(0, N-1){
            scanf("%d %d %d", &u, &v, &c);
            --u; --v;
            adj[u].emplace_back(make_pair(v,c));
            adj[v].emplace_back(make_pair(u,c));
        }

        dfs(0);
        sort(edges.begin(), edges.end());

        seg_tree.resize(pos << 2, 0);
        lazy.resize(pos << 2, 0);

        scanf("%d", &M);
        FOR(0, M){
            scanf("%d %d %d", &u, &v, &k);
            --u; --v;
            queries.emplace_back((struct query){ u,v,k,i });
        }
        sort(queries.begin(), queries.end(), compareQuery);

        int j = 0;
        forEach(queries){
            u = it->u, v = it->v, k = it->k, idx = it->idx;
            while(j < edges.size() && edges[j].first <= k){
                curr = edges[j].second, c = edges[j].first;
                update_tree(first[curr], last[curr], 0, pos-1, 1, c);
                j++;
            }
            ans[idx] = query(0, pos-1, first[u], first[u], 1) ^ query(0, pos-1, first[v], first[v], 1);
        }

        FOR(0, M){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
