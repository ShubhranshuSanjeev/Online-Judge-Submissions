#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 1007
#define MAX2 200007
using namespace std;

struct Query{
    int row, col, pow, idx;
    Query(int a, int b, int c, int d) : row(a), col(b), pow(c), idx(d) {}

    bool operator <(const Query& other) const {
        return pow < other.pow;
    }
};

struct Height{
    int h, row, col;
    Height(int a, int b, int c) : h(a), row(b), col(c) {}

    bool operator <(const Height& other) const {
        return h < other.h;
    }
};

int T,H,W,Q;
int cells_height[MAX][MAX], sz[MAX][MAX], visited[MAX][MAX];
int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<Query> queries; vector<Height> heights;
vector<int> res(MAX2);
pii parent[MAX][MAX];

pii find_set(pii u){
    if(u == parent[u.first][u.second]) return u;
    return parent[u.first][u.second] = find_set(parent[u.first][u.second]);
}

void union_set(pii u, pii v){
    u = find_set(u);
    v = find_set(v);

    if(u == v) return;
    if(sz[u.first][u.second] >= sz[v.first][v.second]){
        parent[v.first][v.second] = u;
        sz[u.first][u.second] += sz[v.first][v.second];
    }
    else{
        parent[u.first][u.second] = v;
        sz[v.first][v.second] += sz[u.first][u.second];
    }
}

int main(){
    int r, c, p;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &H, &W, &Q);

        queries.clear(); heights.clear();
        memset(visited, 0, sizeof(visited));
        FOR(i, 0, H){
            FOR(j, 0, W){
                scanf("%d", &cells_height[i][j]);
                heights.push_back((Height){cells_height[i][j], i, j});
                parent[i][j] = make_pair(i, j);
                sz[i][j] = 1;
            }
        }
        sort(heights.begin(), heights.end());

        FOR(i, 0, Q){
            scanf("%d %d %d", &r, &c, &p);
            --r;--c;
            queries.push_back((Query){r,c,p,i});
        }
        sort(queries.begin(), queries.end());

        int ans = 0, k = 0;
        FOR(i, 0, Q){
            r = queries[i].row, c = queries[i].col, p = queries[i].pow;
            while(k < (H*W)){
                int x = heights[k].row, y = heights[k].col;
                if(heights[k].h < p){
                    FOR(j, 0, 4){
                        int vx = x+moves[j][0], vy = y+moves[j][1];
                        if(vx > -1 && vx < H && vy > -1 && vy < W && visited[vx][vy])
                            union_set(make_pair(vx, vy), make_pair(x, y));
                    }
                    visited[x][y] = 1;
                }
                else break;
                k++;
            }

            if(!visited[r][c]) { res[queries[i].idx] = 0; continue; }
            pii pa = find_set(make_pair(r,  c));
            res[queries[i].idx] = sz[pa.first][pa.second];
        }

        FOR(i, 0, Q){
            printf("%d\n", res[i]);
        }
    }
    return 0;
}