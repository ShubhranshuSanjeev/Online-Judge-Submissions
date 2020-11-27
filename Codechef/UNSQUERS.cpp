#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

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
#define MAX 100007
using namespace std;

struct Node{
    int val, lz;
    Node *l, *r;
    
    Node(){
        val = lz = 0;
        l = r = nullptr;
    }

    Node(const Node* a){
        if(a == nullptr){
            val = lz = 0;
            l = r = nullptr;
        }
        else {
            val = a->val;
            lz = a->lz;
            l = a->l;
            r = a->r;
        }
    }
};

void propagate(Node* &node, int l, int r){
    node->l = new Node(node->l);
    node->r = new Node(node->r);
    
    if(node->lz){
        node->val += node->lz;
        if(l < r){
            node->l->lz += node->lz;
            node->r->lz += node->lz;
        }
        node->lz = 0;
    }
}

void update(Node* &node, int l, int r, int tl, int tr){
    propagate(node, l, r);
    if(l > r || l > tr || r < tl) return;
    if(l >= tl && r <= tr){
        node->val++;
        node->l->lz++;
        node->r->lz++;
        return;
    }

    int mid = (l + r) >> 1;
    update(node->l, l, mid, tl, tr);
    update(node->r, mid+1, r, tl, tr);
    node->val = max(node->l->val, node->r->val);
}

int get(Node* &node, int l, int r, int tl, int tr){
    if(!node) return 0;
    propagate(node, l, r);
    if(l > r || l > tr || r < tl) return 0;
    if(l >= tl && r <= tr) return node->val;
    
    int mid = (l + r) >> 1;
    return max(get(node->l, l, mid, tl, tr), get(node->r, mid+1, r, tl, tr));
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int N, Q, s, L, R, H[MAX];
    Node* roots[MAX];

    scanf("%d %d %d", &N, &Q, &s);
    
    vector<int> st;
    st.push_back(0);
    H[0] = 1e9;
    roots[0] = new Node();

    FOR(i, 1, N+1){
        scanf("%d", &H[i]);
        while(H[st.back()] < H[i])
            st.pop_back();

        roots[i] = new Node(roots[i-1]);
        update(roots[i], 1, N, st.back() + 1, i);
        st.push_back(i);
    }

    int last = 0;
    FOR(i, 0, Q){
        scanf("%d %d", &L, &R);
        L = (L + s * 1LL * last - 1) % N + 1;
        R = (R + s * 1LL * last - 1) % N + 1;

        if(L > R) swap(L, R);
        last = get(roots[R], 1, N, L, R);
        printf("%d\n", last);
    }

    return 0;
}