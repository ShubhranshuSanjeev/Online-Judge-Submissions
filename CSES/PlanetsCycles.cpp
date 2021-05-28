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

const int MAX = 200007;

int N, t_cnt, teleport[MAX];
int teleport_count[MAX], visited[MAX];
queue<int> planets;

void dfs(int u){
    planets.push(u);
    if(visited[u]) {
        t_cnt += teleport_count[u];
        return;
    }
    visited[u] = 1;
    t_cnt++;
    dfs(teleport[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N;
    FOR(i, 1, N+1){
        cin >> teleport[i];
    }

    memset(teleport_count, 0, sizeof(teleport_count));
    memset(visited, 0, sizeof(visited));
    FOR(i, 1, N+1){
        if(!visited[i]){
            t_cnt = 0;
            dfs(i);

            int d = 1;
            while(!planets.empty()){
                if(planets.front() == planets.back()){
                    d = 0;
                }
                teleport_count[planets.front()] = t_cnt;
                t_cnt -= d;
                planets.pop();
            }
        }
    }

    FOR(i, 1, N+1){
        cout << teleport_count[i] << " ";
    }
    cout << "\n";

    return 0;
}