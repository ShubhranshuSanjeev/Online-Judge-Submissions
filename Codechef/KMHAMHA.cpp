#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 1007
using namespace std;

int T, N;
vector<pii> cells;
int sz_row[MAX], sz_col[MAX];
int parent_row[MAX], parent_col[MAX];
bool deleted_row[MAX], deleted_col[MAX];
unordered_map<int, int> rows, columns, r_set, c_set;

//int find_set(int u, int parent[]){
//    if(u == parent[u]) return parent[u];
//    return (parent[u] = find_set(parent[u], parent));
//}
//
//void union_set(int u, int v, int parent[], int sz[]){
//    u = find_set(u, parent);
//    v = find_set(v, parent);
//
//    if(u == v) return;
//    if(sz[u] < sz[v]){
//        int tmp = u;
//        u = v;
//        v = tmp;
//    }
//    parent[v] = u;
//    sz[u] += sz[v];
//}

int main(){
    int x,y;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
//        FOR(i, 0, N){
//            parent_row[i] = parent_col[i] = i;
//            sz_row[i] = sz_col[i] = 1;
//            deleted_row[i] = deleted_col[i] = false;
//        }
        FOR(i, 0, N){
            scanf("%d %d", &x, &y);
            cells.emplace_back(x, y);
            rows[x]++;
            columns[y]++;
        }
        FOR(i, 0, N){
            if(rows[cells[i].first] >= columns[cells[i].second]){
                if(r_set.find(cells[i].first) == r_set.end())
                    r_set[cells[i].first] = 1;
                else
                    r_set[cells[i].first]++;
            }
            else {
                if(c_set.find(cells[i].second) == c_set.end())
                    c_set[cells[i].second] = 1;
                else
                    c_set[cells[i].second]++;
            }

        }
        int ans = r_set.size() + c_set.size();
//        FOR(i, 0, N-1){
//            FOR(j, i+1, N){
//                if(cells[i].first == cells[j].first){
//                    union_set(i, j, parent_row, sz_row);
//                }
//                else if(cells[i].second == cells[j].second){
//                    union_set(i, j, parent_col, sz_col);
//                }
//            }
//        }
//        int ans = 0;
//        FOR(i, 0, N){
//            int pa_r = find_set(i, parent_row), pa_c = find_set(i, parent_col);
//            if(deleted_row[pa_r] || deleted_col[pa_c])
//                continue;
//            if(sz_row[pa_r] >= sz_col[pa_c]) deleted_row[pa_r] = true;
//            else deleted_col[pa_c] = true;
//            ans++;
//        }
        printf("%d\n", ans);
        cells.clear();
        columns.clear();
        rows.clear();
        r_set.clear();
        c_set.clear();
    }
    return 0;
}