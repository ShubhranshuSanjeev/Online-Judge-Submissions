#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <array>

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

const int MAX = 200007;
const int MAX2 = 600007;
const int MAX3 = MAX2 << 2;

int N, Q;
int seg_tree[MAX3];
int salary_arr[MAX];
vector<array<int, 3>> queries;
vector<int> salaries;

void point_update(int idx, int l, int h, int p, int v){
    if(l > p || h < p) return;
    if(l == h && h == p){
        seg_tree[idx] += v;
        return;
    }

    int mid = (l + h) >> 1,
        lc = idx << 1,
        rc = lc | 1;
    
    point_update(lc, l, mid, p, v);
    point_update(rc, mid+1, h, p, v);

    seg_tree[idx] = seg_tree[lc] + seg_tree[rc];
}

int query_tree(int idx, int l, int h, int ql, int qh){
    if(l > qh || h < ql) return 0;
    if(l >= ql && h <= qh) return seg_tree[idx];

    int mid = (l + h) >> 1,
        lc = idx << 1,
        rc = lc | 1;
    
    return (
        query_tree(lc, l, mid, ql, qh) +
        query_tree(rc, mid+1, h, ql, qh)
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

    int unq_count;
    memset(seg_tree, 0, sizeof(seg_tree));

    cin >> N >> Q;
    FOR(i, 0, N) {
        int salary; cin >> salary;
        salary_arr[i] = salary;
        salaries.push_back(salary);
    }
    
    FOR(i, 0, Q){
        char q_type; int a, b; 
        cin >> q_type >> a >> b;

        int q_type_int = q_type == '?';
        queries.push_back({q_type_int, a, b});

        salaries.push_back(b);
        if(q_type_int) {
            salaries.push_back(a);
        }
    }
    sort(salaries.begin(), salaries.end());
    salaries.erase(unique(salaries.begin(), salaries.end()), salaries.end());
    unq_count = salaries.size();
    FOR(i, 0, N) {
        int pos = (upper_bound(salaries.begin(), salaries.end(), salary_arr[i]) - salaries.begin())-1;
        point_update(1, 0, unq_count-1, pos, 1);
    }

    for(auto query : queries){
        int q_type = query[0],
            a = query[1],
            b = query[2];
        
        if(q_type){
            int l_idx = (upper_bound(salaries.begin(), salaries.end(), a) - salaries.begin())-1;
            int u_idx = (upper_bound(salaries.begin(), salaries.end(), b) - salaries.begin())-1;

            int cnt = query_tree(1, 0, unq_count-1, l_idx, u_idx);
            cout << cnt << "\n";
        }
        else {
            int current_salary = salary_arr[a-1];
            salary_arr[a-1] = b;
            
            int idx = (upper_bound(salaries.begin(), salaries.end(), current_salary) - salaries.begin())-1;
            int pos = (upper_bound(salaries.begin(), salaries.end(), b) - salaries.begin())-1;
            point_update(1, 0, unq_count-1, idx, -1);
            point_update(1, 0, unq_count-1, pos, 1);
        }
    }
    return 0;
}