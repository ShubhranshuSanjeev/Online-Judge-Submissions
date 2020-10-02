#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#define FOR(st, ed) for(int i = st; i < ed; i++)
#define FOR2(st, ed) for(int j = st; j < ed; j++)
#define pii pair<int,int>
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
using namespace std;

class SegmentTree{
private:
    vector<int> tree;
    int size;

    static int merge(int a, int b){
        return min(a, b);
    }

    void build(int l, int h, int idx, vector<pii> &data){
        if(l > h) return;
        if(l == h){
            tree[idx] = data[l].second;
            return;
        }

        divide(l, h, idx);
        build(l, mid, lc, data);
        build(mid+1, h, rc, data);
        tree[idx] = merge(tree[lc], tree[rc]);
    }

    int query(int l, int h, int ql, int qh, int idx){
        if(l > h || l > qh || h < ql) return INT_MAX;
        if(l >= ql && h <= qh) return tree[idx];

        divide(l, h, idx);
        return merge(query(l, mid, ql, qh, lc), query(mid+1, h, ql, qh, rc));
    }

public:
    SegmentTree(int size, vector<pii> &data){
        this->size = size;
        tree.resize(size << 2);
        build(0, size-1, 1, data);
    }
    int query(int ql, int qh){
        return query(0, size-1, ql, qh, 1);
    }
};

int main(){
    int T, N, Q, K, L, R, ci, pi;
    vector<pii> cokes;
    vector<int> temp;

    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d %d", &N, &Q, &K, &L, &R);

        cokes.clear();
        temp.clear();
        FOR(0, N){
            scanf("%d %d", &ci, &pi);
            cokes.emplace_back(ci, pi);
        }
        sort(cokes.begin(), cokes.end());
        for(pii a: cokes){
            temp.push_back(a.first);
        }

        SegmentTree seg_t(N, cokes);
        int l, h, ans;
        FOR(1, Q+1){
            if(K < L) L++, R++;
            else if (K > R) L--, R--;
            else L--, R++;

            l = lower_bound(temp.begin(), temp.end(), L) - temp.begin();
            h = (upper_bound(temp.begin(), temp.end(), R) - temp.begin()) - 1;
            if(h < l) printf("-1 ");
            else {
                ans = seg_t.query(l ,h);
                if(ans == INT_MAX ) printf("-1 ");
                else printf("%d ", ans);
            }
        }
        printf("\n");
    }
    return 0;
}