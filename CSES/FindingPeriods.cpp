#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
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

const int MAXN = 1000007;

string str;
int z[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> str;
    int N = (int) str.size();

    int l = 0, r = 0;
    FOR(i, 1, N){
        if(i <= r) z[i] = min(r-i+1, z[i-l]);
        while(i + z[i] < N && str[z[i]] == str[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;

        if(z[i] == N-i) cout << i << " ";
    }
    cout << N << "\n";
    return 0;
}