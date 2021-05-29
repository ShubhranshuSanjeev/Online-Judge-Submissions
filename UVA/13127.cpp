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

const int MAX = 1007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int N, M, B, P;
    vec1d(pii) adj[MAX];
    vec1d(int) banks(MAX), police;
    vec1d(int) visited(MAX), dist(MAX);

    while(scanf("%d %d %d %d", &N, &M, &B, &P) == 4){

        police.clear();
        banks.assign(MAX, 0);
        dist.assign(MAX, INT32_MAX);
        for(int i = 0; i < N; i++){
            adj[i].clear();
        }

        for(int i = 0; i < M; i++){
            int u, v, t;
            scanf("%d %d %d", &u, &v, &t);

            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }

        for(int i = 0; i < B; i++){
            int b; scanf("%d", &b);
            banks[b] = 1;
        }

        for(int i = 0; i < P; i++){
            int p; scanf("%d", &p);
            police.push_back(p);
        }

        if(P == 0){
            printf("%d *\n", B);
            bool first = true;
            for(int i = 0; i < N; i++){
                if(banks[i]){
                    if(first){
                        printf("%d", i);
                        first = false;
                    }
                    else{
                        printf(" %d", i);
                    }
                }
            }
            printf("\n");
            continue;
        }

        for(int i = 0; i < P; i++){
            int curr_police = police[i];

            priority_queue<pii, vec1d(pii), greater<pii>> q;
            visited.assign(MAX, -1);

            q.push(make_pair(curr_police, 0));
            visited[curr_police] = 0;

            while(!q.empty()){
                int u = q.top().first;
                int c = q.top().second;

                q.pop();

                if(dist[u] > c){
                    dist[u] = c;
                }
                else {
                    continue;
                }

                for(auto ed: adj[u]){
                    int v = ed.first;
                    int t = ed.second;

                    if(visited[v] == -1 || visited[v] > c+t){
                        q.push(make_pair(v, c+t));
                        visited[v] = c+t;
                    }
                }
            }
        }

        int maxDist = 0, cnt = 0;
        for(int i = 0; i < N; i++){
            if(banks[i]){
                if(maxDist < dist[i]){
                    maxDist = dist[i];
                    cnt = 1;
                }
                else if(maxDist == dist[i]){
                    ++cnt;
                }
            }
        }

        if(maxDist == INT32_MAX){
            printf("%d *\n", cnt);
        }
        else {
            printf("%d %d\n", cnt, maxDist);
        }

        bool first = true;
        for(int i = 0; i < N; i++){
            if(banks[i] && maxDist == dist[i]){
                if(first){
                    printf("%d", i);
                    first = false;
                }
                else{
                    printf(" %d", i);
                }
            }
        }
        printf("\n");
    }

    return 0;
}