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

const int MAX = 100007;

int N, M;
int parent[MAX], set_size[MAX];
int set_count, max_set_size;

int find_set(int u){
    if(u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

void union_set(int a, int b){
    int pa = find_set(a);
    int pb = find_set(b);

    if(pa == pb) return;
    if(set_size[pa] < set_size[pb]){
        int t = pa;
        pa = pb;
        pb = t;
    }

    parent[pb] = pa;
    set_size[pa] += set_size[pb];
    --set_count;
    max_set_size = max(max_set_size, set_size[pa]);
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
    FOR(i, 1, N+1){
        parent[i] = i;
        set_size[i] = 1;
    }
    set_count = N;
    max_set_size = 1;

    FOR(i, 0, M){
        int u, v; cin >> u >> v;
        union_set(u, v);
        cout << set_count << " " << max_set_size << "\n";
    }
    return 0;
}