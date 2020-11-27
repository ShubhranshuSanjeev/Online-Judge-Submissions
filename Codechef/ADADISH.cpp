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
#define MAX 300007
#define MUL (ll)10000000
using namespace std;

int main(){
    int T, N, C[5];
    scanf("%d", &T);

    while (T--){
        scanf("%d", &N);
        FOR(i, 0, N){
            scanf("%d", &C[i]);
        }
        sort(C, C+N, greater<int>());
        int b1 = 0, b2 = 0;
        FOR(i, 0, N){
            if(b1 < b2) b1 += C[i];
            else b2 += C[i];
        }
        printf("%d\n", max(b2, b1));
        // if(N == 1) printf("%d\n", C[0]);
        // if(N == 2) printf("%d\n", max(C[0], C[1]));
        // if(N == 3) printf("%d\n", min(min(max(C[0]+C[2], C[1]), max(C[0]+C[1], C[2])), max(C[1]+C[2], C[0])));
        // if(N == 4) printf("%d\n", min(min(max(C[0]+C[1], C[2]+C[3]), max(C[0]+C[2], C[1]+C[3])), max(C[0]+C[3], C[1]+C[2])));
    }
    return 0;
}
