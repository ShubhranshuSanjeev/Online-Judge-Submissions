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

const int MAX = 200007;
int parent[MAX], sz[MAX];

int find_set(int u){
    if(u == parent[u]) return u;
    return (parent[u] = find_set(parent[u]));
}

void union_set(int u, int v){
    if(sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int N, D;
    scanf("%d %d", &N, &D);
    
    vec2d(int) point(N, vector<int> (D));
    FOR(i, 0, N) 
        FOR(j, 0, D)
            scanf("%d", &point[i][j]);

    vector<pair<int, pii>> edges;

    FOR(mask, 0, ((1<<D)/2)){
        vec1d(pii) e;
        FOR(i, 0, N){
            int val = 0;
            FOR(j, 0, D){
                if((mask >> j) & 1)
                    val -= point[i][j];
                else
                    val += point[i][j];
            }
            e.push_back(make_pair(val, i));
        }

        int source = min_element(e.begin(), e.end())->second;
        int sink = max_element(e.begin(), e.end())->second;
        FOR(i, 0, N){
            int dist_s = 0, dist_e = 0;
            FOR(j, 0, D){
                dist_s += abs(point[source][j]-point[i][j]);
                dist_e += abs(point[sink][j]-point[i][j]);
            }

            edges.push_back(make_pair(dist_s, make_pair(source, i)));
            edges.push_back(make_pair(dist_e, make_pair(sink, i)));
        }
    }

    sort(edges.begin(), edges.end(), greater<pair<int, pii>>());

    FOR(i, 0, N){
        parent[i] = i;
        sz[i] = 1;
    }
    ll max_wt = 0;
    for(auto x: edges){
        int pu = find_set(x.second.first);
        int pv = find_set(x.second.second);

        if(pu != pv){
            union_set(pu, pv);
            max_wt += x.first;
        }
    }

    printf("%lld\n", max_wt);
    return 0;
}