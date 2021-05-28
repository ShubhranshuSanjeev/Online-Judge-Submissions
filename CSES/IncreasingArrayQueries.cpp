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

const int MAX = 200007;
const int MAX2 = MAX << 2;

int N, Q;
vector<pii> queries[MAX];
ll X[MAX], prefix[MAX];
ll contrib[MAX], ans[MAX], seg_tree[MAX2];

void update(int idx, int l, int h, int pos, ll val){
    if(l > h || l > pos || h < pos) return;
    if(l == pos && h == pos){
        seg_tree[idx] += val;
        return;
    }

    int mid = (l + h) >> 1,
        lst = idx << 1,
        rst = lst | 1;
    
    update(lst, l, mid, pos, val);
    update(rst, mid+1, h, pos, val);

    seg_tree[idx] = seg_tree[lst] + seg_tree[rst];
}

ll query(int idx, int l, int h, int ql, int qh){
    if(l > qh || h < ql || l > h) return 0;
    if(l >= ql && h <= qh) return seg_tree[idx];

    int mid = (l + h) >> 1,
        lst = idx << 1,
        rst = lst | 1;
    
    return (
        query(lst, l, mid, ql, qh) +
        query(rst, mid+1, h, ql, qh)
    );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    memset(seg_tree, 0, sizeof(seg_tree));

    cin >> N >> Q;
    FOR(i, 1, N+1) {
        cin >> X[i];
        prefix[i] = X[i] + prefix[i-1];
    }
    X[N+1] = 1e18;
    prefix[N+1] = X[N+1] + prefix[N];

    FOR(i, 0, Q) {
        int a, b; cin >> a >> b;
        queries[a].emplace_back(b, i);
    }

    deque<ll> stck = {N+1};
    FORS(i, N, 0, -1){
        while(!stck.empty() && X[i] >= X[stck.front()]){
            update(1, 1, N, stck.front(), -contrib[stck.front()]);
            stck.pop_front();
        }
        contrib[i] = (stck.front() - i - 1) * X[i] - (prefix[stck.front() - 1] - prefix[i]);
        update(1, 1, N, i, contrib[i]);
        stck.push_front(i);
        
        FOREACH(q, queries[i]) {
            int pos = upper_bound(stck.begin(), stck.end(), q->first) - stck.begin() - 1;
            ans[q->second] = (pos ? query(1, 1, N, i, stck[pos-1]) : 0) + (q->first - stck[pos]) * X[stck[pos]] - (prefix[q->first] - prefix[stck[pos]]);
        }
    }

    FOR(i, 0, Q) cout << ans[i] << "\n";

    return 0;
}