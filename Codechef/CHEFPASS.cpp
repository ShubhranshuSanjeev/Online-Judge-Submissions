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
#include <bitset>
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
using namespace std;

const int MAX = 100007;
vec1d(string) A, B;
map<char, vec1d(int)> adj;
map<char, int> in_deg, out_deg, visited;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T; cin >> T;
    while(T--){
        int N, M;
        cin >> N;
        FOR(i, 0, N){
            string a; cin >> a;

            A.emplace_back(a);

            if(out_deg.find(a[0]) == out_deg.end()){
                out_deg.insert(make_pair(a[0], 1));
            }
            else {
                out_deg[a[0]]++;
            }

            if(in_deg.find(a.back()) == in_deg.end()){
                in_deg.insert(make_pair(a.back(), 1));
            }
            else {
                in_deg[a.back()]++;
            }

            adj[a[0]].emplace_back(a.back());
            adj[a.back()].emplace_back(a[0]);
        }


    }

    return 0;
}