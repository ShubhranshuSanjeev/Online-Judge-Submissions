#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <bitset>
#include <unordered_set>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for(int i = int(st); i != int(ed); i += step)
#define FOREACH(it, ds) for(auto it = ds.begin(); it != ds.end(); ++it)

using namespace std;

const int MAX = 1007;
const int MAXQ = 200007;
const int MAX2 = MAX << 2;

int N, Q;
int forest[MAX][MAX], bit[MAX][MAX];

/* void build_column_segments(int idx_r, int l_r, int idx, int l, int h){
    if(l > h) return;
    if(l == h) {
        seg_tree[idx_r][idx] = forest[l_r][l];
        return;
    }

    int mid = (l + h) >> 1,
        lst = idx << 1,
        rst = lst | 1;
    
    build_column_segments(idx_r, l_r, lst, l, mid);
    build_column_segments(idx_r, l_r, rst, mid+1, h);

    seg_tree[idx_r][idx] = seg_tree[idx_r][lst] + seg_tree[idx_r][rst];
}

void build_row_segments(int idx, int l, int h){
    if(l > h) return;
    if(l == h) {
        build_column_segments(idx, l, 1, 0, N-1);
        return;
    }

    int mid = (l + h) >> 1,
        lst = idx << 1,
        rst = lst | 1;
    
    build_row_segments(lst, l, mid);
    build_row_segments(rst, mid+1, h);

    FOR(i, 0, N2){
        seg_tree[idx][i] = seg_tree[lst][i] + seg_tree[rst][i];
    }
}

int query_column_segments(int idx_r, int idx, int l, int h, int c1, int c2){
    if(l > h || l > c2 || h < c1) return 0;
    if(l >= c1 && h <= c2) return seg_tree[idx_r][idx];

    int mid = (l + h) >> 1,
        lst = idx << 1,
        rst = lst | 1;
    
    return (
        query_column_segments(idx_r, lst, l, mid, c1, c2) +
        query_column_segments(idx_r, rst, mid+1, h, c1, c2)
    );
}

int query_row_segments(int idx, int l, int h, int r1, int r2, int c1, int c2){
    if(l > h || l > r2 || h < r1) return 0;
    if(l >= r1 && h <= r2) {
        return query_column_segments(idx, 1, 0, N-1, c1, c2);
    }
    
    int mid = (l + h) >> 1,
        lst = idx << 1,
        rst = lst | 1;
    
    return (
        query_row_segments(lst, l, mid, r1, r2, c1, c2) +
        query_row_segments(rst, mid+1, h, r1, r2, c1, c2)
    );
}

void update_column_segments(int idx_r, int idx, int l, int h, int c) {
    if(l > h || l > c || h < c) return;
    if(l == c && h == c){
        seg_tree[idx_r][idx] = seg_tree[idx_r][idx] ? 0 : 1;
        return;
    }

    int mid = (l + h) >> 1,
        lst = idx << 1,
        rst = lst | 1;
    
    update_column_segments(idx_r, lst, l, mid, c);
    update_column_segments(idx_r, rst, mid+1, h, c);

    seg_tree[idx_r][idx] = seg_tree[idx_r][lst] + seg_tree[idx_r][rst];
}
void update_row_segments(int idx, int l, int h, int r, int c) {
    if(l > h || l > r || h < r) return;
    if(l == r && h == r){
        update_column_segments(idx, 1, 0, N-1, c);
        return;
    }

    int mid = (l + h) >> 1,
        lst = idx << 1,
        rst = lst | 1;
    
    update_row_segments(lst, l, mid, r, c);
    update_row_segments(rst, mid+1, h, r, c);
    
    FOR(i, 0, N2){
        seg_tree[idx][i] = seg_tree[lst][i] + seg_tree[rst][i];
    }
}

void build(){
    build_row_segments(1, 0, N-1);
}

void update(int a, int b){
    update_row_segments(1, 0, N-1, a, b);
}

int query(int a, int b, int c, int d){
    return query_row_segments(1, 0, N-1, a, c, b, d);
} */

void update(int r, int c, int val){
    for(int i = r; i < N; i = i | (i + 1)){
        for(int j = c; j < N; j = j | (j + 1)){
            bit[i][j] += val;
        }
    }
}

int query(int r, int c){
    int ans = 0;
    for(int i = r; i >= 0; i = (i & (i + 1)) - 1){
        for(int j = c; j >= 0; j = (j & (j + 1)) - 1){
            ans += bit[i][j];
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    memset(bit, 0, sizeof(bit));

    cin >> N >> Q;
    FOR(i, 0, N) {
        FOR(j, 0, N){
            char c; cin >> c;
            forest[i][j] = c == '*';
            update(i, j, forest[i][j]);
        }
    }

    FOR(i, 0, Q){
        int q_type; cin >> q_type;
        --q_type;

        if(q_type) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            --a; --b; --c; --d;

            int w = query(c, d),
                x = query(a-1, d),
                y = query(c, b-1),
                z = query(a-1, b-1);
            int ans = w - x - y + z;
            cout << ans << "\n";
        }
        else {
            int a, b; cin >> a >> b;
            --a; --b;
            forest[a][b] = (forest[a][b] + 1) % 2;
            update(a, b, forest[a][b] ? 1 : -1);
        }
    }

    return 0;
}