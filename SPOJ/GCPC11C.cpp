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

int T, N, M;
vec2d(int) adj, radj;
vec1d(int) in_deg, out_deg, visited;

void dfs(int u){
    visited[u] = 1;
    FOR(v, 0, N){
        if((adj[u][v] || adj[v][u]) && !visited[v]){
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> T;
    while(T--){
        cin >> N >> M;

        int u, v;
        FOR(i, 0, M){
            cin >> u >> v;

            out_deg[u]++;
            in_deg[v]++;
            adj[u][v] = adj[v][u] = 1;
        }

        dfs(1);

        int connected = 1;
        FOR(i, 0, N){
            if(!visited[i]){
                connected = 0;
                break;
            }
        }

        // int has_cycle = 0;
        int has_eulerian_path = 1;
        u = v = -1;
        FOR(i, 0, N){
            if(in_deg[i] != out_deg[i]){
                if(u == -1){
                    u = i;
                }
                else if(v == -1){
                    v = i;
                }
                else {
                    has_eulerian_path = 0;
                    break;
                }
            }
        }

        if(u == -1){
            cout << "recheck hints\n";
        }
        else if(!connected || !has_eulerian_path){
            cout << "missing hints\n";
        }
        else {
            has_eulerian_path = 0;
            if((in_deg[u] == out_deg[u]+1) && (out_deg[v] == in_deg[v]+1)) {
                has_eulerian_path = 1;
            }
            else if ((in_deg[v] == out_deg[v]+1) && (out_deg[u] == in_deg[u]+1)){
                has_eulerian_path = 1;
            }

            if(has_eulerian_path){
                cout << "Ordering is possible.\n";
            }
            else {
                cout << "The door cannot be opened.\n";
            }
        }
    }

    return 0;
}