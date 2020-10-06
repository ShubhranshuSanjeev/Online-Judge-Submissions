#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007
#define MAX2 (MAX << 2)

using namespace std;

int A[MAX], N, Q;

struct Node {
    int max_val, min_val;
    Node(): max_val(0), min_val(INT32_MAX){}
    Node(int a) : max_val(a), min_val(a){}

    void merge(Node a, Node b){
        max_val = max(a.max_val, b.max_val);
        min_val = min(a.min_val, b.min_val);
    }
};

class SegmentTree{
private:
    vector<Node> tree;
    int size;

    void build(int l, int h, int idx){
        if(l > h) return;
        if(l == h){
            tree[idx] = (Node){ A[l] };
            return;
        }

        divide(l, h, idx);
        build(l, mid, lc);
        build(mid+1, h, rc);
        tree[idx].merge(tree[lc], tree[rc]);
    }

    Node query(int l, int h, int ql, int qh, int idx){
        if(l > h || l > qh || h < ql){
            Node tmp = (Node) {};
            return tmp;
        }
        if(l >= ql && h <= qh) return tree[idx];

        divide(l, h, idx);
        Node tmp = (Node){};
        tmp.merge(query(l, mid, ql, qh, lc), query(mid+1, h, ql, qh, rc));
        return tmp;
    }

public:
    SegmentTree(int size){
        this->size = size;
        tree.resize(size << 2);
        build(0, size-1, 1);
    }
    Node query(int ql, int qh){
        return query(0, size-1, ql, qh, 1);
    }
};

int main(){
    int l, r;
    scanf("%d", &N);
    FOR(i, 0, N){
        scanf("%d", &A[i]);
    }
    auto *seg_tree = new SegmentTree(N);
    scanf("%d", &Q);
    while(Q--){
        scanf("%d %d", &l, &r);
        Node tmp = seg_tree->query(l, r);
        Node tmp1 = (Node){};
        tmp1.merge(seg_tree->query(0, l-1), seg_tree->query(r+1, N-1));
        double ans = tmp.min_val + max((tmp.max_val-tmp.min_val)/2.0, tmp1.max_val*1.0);
        printf("%.1lf\n", ans);
    }
    return 0;
}
