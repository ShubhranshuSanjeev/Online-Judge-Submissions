#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(st, ed) for(int i = st; i < ed; i++)
#define forEach(ds) for(auto it : ds)
#define MAX 500007

using namespace std;

int N, Q, pos;
vector<int> adj[MAX];
int first[MAX], last[MAX], A[MAX];
int seg_tree[MAX << 2], lazy[MAX << 2];

void propagate(int l, int h, int idx){
    if(lazy[idx] != 0){
        seg_tree[idx] += (h-l+1)*lazy[idx];
        if(l != h){
            lazy[idx << 1] += lazy[idx];
            lazy[idx << 1|1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void build_tree(int l, int h, int idx){
    if(l > h) return;

    lazy[idx] = 0;
    if(l == h) {
        seg_tree[idx] = A[l];
        return;
    }

    int mid = (l+h)>>1, lc = idx<<1, rc = lc|1;
    build_tree(l, mid, lc);
    build_tree(mid+1, h, rc);

    seg_tree[idx] = seg_tree[rc]+seg_tree[lc];
}

void update_tree(int ql, int qh, int l, int h, int idx, int val){
    propagate(l, h, idx);
    if(l > h || l > qh || h < ql) return;
    if(l >= ql && h <= qh){
        lazy[idx] += val;
        propagate(l, h, idx);
        return;
    }

    int mid = (l+h)>>1, lc = idx<<1, rc = lc|1;
    update_tree(ql, qh, l, mid, lc, val);
    update_tree(ql, qh, mid+1, h, rc, val);
    seg_tree[idx] = seg_tree[rc] + seg_tree[lc];
}

void point_update(int l, int h, int idx, int point, int val){
    propagate(l, h, idx);
    if(l > h || l > point || h < point) return;
    if(l == h && l == point){
        seg_tree[idx] = val;
        return;
    }

    int mid = (l+h)>>1, lc = idx<<1, rc = lc|1;
    point_update(l, mid, lc, point, val);
    point_update(mid+1, h, rc, point, val);
    seg_tree[idx] = seg_tree[rc] + seg_tree[lc];
}

int query(int l, int h, int ql, int qh, int idx){
    propagate(l, h, idx);
    if(l > h || l > qh || h < ql) return 0;
    if(l >= ql && h <= qh) return seg_tree[idx];

    int mid = (l+h)>>1, lc = idx<<1, rc = lc|1;
    int a = query(l, mid, ql, qh, lc);
    int b = query(mid+1, h, ql, qh, rc);

    return b + a;
}

void dfs(int u = 0, int p = -1){
    first[u] = pos++;
    forEach(adj[u]){
        if(it != p)
            dfs(it, u);
    }
    last[u] = pos-1;
}

int main(){
    int x, y;
    char a;

    scanf("%d %d", &N, &Q);
    FOR(0, N-1){
        scanf("%d %d", &x, &y);
        --x; --y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    FOR(0, N){
        scanf("%d", &A[i]);
    }

    pos = 0;
    dfs();
    build_tree(0, N-1, 1);

    FOR(0, Q){
        scanf("\n%c ", &a);
//        printf("%c ", a);
        FOR(0, N){
            int f = first[i], l = last[i];
            if(f == l) continue;
            int val = query(0, N-1, f, f, 1);
            point_update(0, N-1, 1, f, 0);
            update_tree(f+1, l, 0, N-1, 1, val);
        }

        if(a == '+'){
            scanf("%d %d", &x, &y);
//            printf("%d %d\n", x, y);
            int p = first[--x];
            point_update(0, N-1, 1, p, y);
        }
        else {
            scanf("%d", &x);
//            printf("%d \n", x);
            int p = first[--x];
            printf("ans: %d\n", query(0, N-1, p, p, 1));
        }
    }
    return 0;
}