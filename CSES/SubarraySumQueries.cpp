#include <iostream>
#include <algorithm>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
using namespace std;

const int MAX = 200007;
const int MAX2 = MAX << 2;

int N, Q;
int arr[MAX];

struct Node{
    ll sum,
        left_max_sum,
        right_max_sum,
        max_sum;

    Node() {}

    void set(ll a){
        this->sum = this->left_max_sum = this->right_max_sum = this->max_sum = a;
    }

    void merge(Node left_child, Node right_child){
        this->sum = left_child.sum + right_child.sum;

        this->left_max_sum = max(
            left_child.left_max_sum,
            left_child.sum + right_child.left_max_sum
        );

        this->right_max_sum = max(
            right_child.right_max_sum,
            right_child.sum + left_child.right_max_sum
        );

        this->max_sum = max(
            this->sum,
            max(
                left_child.right_max_sum + right_child.left_max_sum,
                max(
                    left_child.max_sum,
                    right_child.max_sum
                )
            )
        );
    }
} seg_tree[MAX2];

void build_tree(int idx, int l, int h){
    if(l > h) return;
    if(l == h) {
        seg_tree[idx].set((ll)arr[l]);
        return;
    }

    int mid = (l + h) >> 1,
        lc = idx << 1,
        rc = lc | 1;

    build_tree(lc, l, mid);
    build_tree(rc, mid+1, h);

    seg_tree[idx].merge(seg_tree[lc], seg_tree[rc]);
}

void update_tree(int idx, int l, int h, int pos, int val){
    if(l > pos || h < pos) return;
    if(l == h && h == pos) {
        seg_tree[idx].set((ll)val);
        return;
    }

    int mid = (l + h) >> 1,
        lc = idx << 1,
        rc = lc | 1;

    update_tree(lc, l, mid, pos, val);
    update_tree(rc, mid+1, h, pos, val);

    seg_tree[idx].merge(seg_tree[lc], seg_tree[rc]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N >> Q;
    FOR(i, 0, N) cin >> arr[i];
    build_tree(1, 0, N-1);

    FOR(i, 0, Q) {
        int k, x; cin >> k >> x;
        update_tree(1, 0, N-1, k-1, x);
        cout << seg_tree[1].max_sum * (seg_tree[1].max_sum > 0)  << "\n";
    }

    return 0;
}