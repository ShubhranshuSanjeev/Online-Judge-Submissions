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

vec2d(int) adj;
vec1d(int) in_deg, out_deg, is_a_node, visited;

void dfs(int u){
    visited[u] = 1;
    FOR(v, 0, 26){
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

    int T; cin >> T;
    while (T--){
        int N; cin >> N;

        adj.assign(26, vec1d(int)(26, 0));
        in_deg.assign(26, 0);
        out_deg.assign(26, 0);
        is_a_node.assign(26, 0);
        visited.assign(26, 0);

        FOR(i, 0, N){
            string w; cin >> w;
            int f_ch = w[0] - 'a';
            int l_ch = w.back() - 'a';
            out_deg[f_ch]++;
            in_deg[l_ch]++;
            is_a_node[f_ch] = is_a_node[l_ch] = 1;
            adj[f_ch][l_ch] = adj[l_ch][f_ch] = 1;
        }

        int s;
        for(s = 0; !is_a_node[s]; s++);
        dfs(s);

        int connected = 1;
        FOR(i, 0, 26){
            if(is_a_node[i] && !visited[i]){
                connected = 0;
                break;
            }
        }

        if(!connected){
            cout << "The door cannot be opened.\n";
            continue;
        }

        int has_eulerian_path = 1;
        int start = -1, end = -1;
        FOR(i, 0, 26){
            if(in_deg[i] != out_deg[i]){
                if(start == -1){
                    start = i;
                }
                else if(end == -1){
                    end = i;
                }
                else {
                    has_eulerian_path = 0;
                    break;
                }
            }
        }

        if(!has_eulerian_path){
            cout << "The door cannot be opened.\n";
            continue;
        }

        has_eulerian_path = 0;
        if(start == -1){
            has_eulerian_path = 1;
        }
        else if((in_deg[start] == out_deg[start]+1) && (out_deg[end] == in_deg[end]+1)) {
            has_eulerian_path = 1;
        }
        else if ((in_deg[end] == out_deg[end]+1) && (out_deg[start] == in_deg[start]+1)){
            has_eulerian_path = 1;
        }

        if(has_eulerian_path){
            cout << "Ordering is possible.\n";
        }
        else {
            cout << "The door cannot be opened.\n";
        }
    }
    return 0;
}