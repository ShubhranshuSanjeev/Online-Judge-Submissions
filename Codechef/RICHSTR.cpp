#include <cstdio>
#include <algorithm>
#define MAX 100007
#define MAX2 (MAX << 2)
#define FOR(st, ed, step) for(int i = st; i < ed; i+=step)

using namespace std;

int T, N, Q, subs_rich[MAX];
char A[MAX];
int seg_tree[MAX2];

void build_tree(int l, int h, int idx){
    if(l > h) return;
    if(l == h){
        seg_tree[idx] = subs_rich[l];
        return;
    }

    int mid = (l+h)>>1, lc = idx<<1, rc = lc|1;
    build_tree(l, mid, lc);
    build_tree(mid+1, h, rc);
    seg_tree[idx] = max(seg_tree[lc], seg_tree[rc]);
}

int query(int ql, int qh, int l, int h, int idx){
    if(l > h || l > qh || h < ql) return 0;
    if(l >= ql && h <= qh) return seg_tree[idx];

    int mid = (l+h)>>1, lc = idx<<1, rc = lc|1;
    return max(query(ql, qh, l, mid, lc), query(ql, qh, mid+1, h, rc));
}

int main(){
    int L, R;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &Q);
        scanf("%s", A);
        FOR(0, N-2, 1) {
            subs_rich[i] = (A[i] == A[i + 1] || A[i] == A[i + 2] || A[i + 1] == A[i + 2]);
        }
        build_tree(0, N-2, 1);

        FOR(0, Q, 1){
            scanf("%d %d", &L, &R);
            L--; R--;
            if(query(L, R-2, 0, N-2, 1)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}