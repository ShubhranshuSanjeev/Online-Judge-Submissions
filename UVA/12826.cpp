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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int a,b,c,d,e,f;
    int moves[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int tc = 0;

    while(scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) == 6){
        queue<pair<pii, int>> q;
        auto visited = ivec2d(bool, 9, 9, false);

        q.push(make_pair(make_pair(a, b), 0));
        visited[a][b] = true;

        while(!q.empty()){
            pair<pii, int> curr = q.front();
            q.pop();

            int cr = curr.first.first;
            int cc = curr.first.second;
            int mv_cnt = curr.second;

            if(cr == c && cc == d){
                printf("Case %d: %d\n", ++tc, mv_cnt);
                break;
            }

            for(int i = 0; i < 8; i++){
                int nr = cr + moves[i][0];
                int nc = cc + moves[i][1];

                if(nr > 0 && nr < 9 && nc > 0 && nc < 9 && !visited[nr][nc] && !(nr == e && nc == f)){
                    q.push(make_pair(make_pair(nr, nc), mv_cnt+1));
                    visited[nr][nc] = true;
                }
            }
        }
    }

    return 0;
}