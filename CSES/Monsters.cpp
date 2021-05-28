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

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for(int i = int(st); i != int(ed); i += step)
#define FOREACH(it, ds) for(auto it = ds.begin(); it != ds.end(); ++it)

using namespace std;

const int MAX = 1007;
int N, M;
char mat[MAX][MAX];
int visited[MAX][MAX], dist[MAX][MAX];
tuple<int,int,char> prev_cell[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int moves[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    char dir[] = {'D', 'U', 'R', 'L'};
    queue<tuple<int, int, int>> q;
    int sr, sc;

    memset(dist, -1, sizeof(dist));

    cin >> N >> M;
    FOR(i, 0, N) {
        FOR(j, 0, M) {
            cin >> mat[i][j];
            if(mat[i][j] == 'M') {
                q.emplace(i, j, 0);
                dist[i][j] = 0;
            }
            if(mat[i][j] == 'A') sr = i, sc = j;
        }
    }

    while(!q.empty()){
        auto tup = q.front();
        int r = get<0>(tup),
            c = get<1>(tup),
            step = get<2>(tup);

        q.pop();
        for(auto move: moves){
            int nr = r + move[0];
            int nc = c + move[1];

            if(nr > -1 && nr < N && nc > -1 && nc < M && mat[nr][nc] != '#'){
                if(dist[nr][nc] == -1 || dist[nr][nc] > (step+1)){
                    dist[nr][nc] = step+1;
                    q.emplace(nr, nc, dist[nr][nc]);
                }
            }
        }
    }

    bool possible = false;
    int er, ec;

    memset(visited, 0, sizeof(visited));
    q.emplace(sr, sc, 0);
    while(!q.empty()){
        auto tup = q.front();
        int r = get<0>(tup),
            c = get<1>(tup),
            step = get<2>(tup);
        q.pop();
        if(r == 0 || r == N-1 || c == 0 || c == M-1){
            possible = true;
            er = r; ec = c;
            break;
        }

        int idx = 0;
        for(auto move: moves){
            int nr = r + move[0];
            int nc = c + move[1];
            char c_dir = dir[idx];
            if(nr > -1 && nr < N && nc > -1 && nc < M && mat[nr][nc] != '#'){
                if((dist[nr][nc] == -1 || dist[nr][nc] > (step+1)) && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.emplace(nr, nc, step+1);
                    prev_cell[nr][nc] = make_tuple(r, c, c_dir);
                }
            }
            ++idx;
        }
    }
    if(!possible) cout << "NO\n";
    else {
        vector<char> ans;
        int cr = er, cc = ec;
        while(cr != sr || cc != sc){
            auto tup = prev_cell[cr][cc];
            cr = get<0>(tup);
            cc = get<1>(tup);
            ans.push_back(get<2>(tup));
        }
        cout << "YES\n" << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for(char d: ans){
            cout << d;
        }
        cout << "\n";
    }
    return 0;
}