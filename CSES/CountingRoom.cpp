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

const int MAX = 1003;
int N, M;
char mat[MAX][MAX];
int visited[MAX][MAX];
int moves[][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int r, int c){
    visited[r][c] = 1;
    for(auto move: moves){
        int nr = r + move[0];
        int nc = c + move[1];
        if(nr > -1 && nr < N && nc > -1 && nc < M && !visited[nr][nc] && mat[nr][nc] == '.')
            dfs(nr, nc);
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

    cin >> N >> M;
    FOR(i, 0, N) FOR(j, 0, M) cin >> mat[i][j];

    int rooms = 0;
    memset(visited, 0, sizeof(visited));
    FOR(i, 0, N)
        FOR(j, 0, M)
            if(!visited[i][j] && mat[i][j] == '.'){
                dfs(i, j);
                ++rooms;
            }
    cout << rooms << "\n";
    return 0;
}