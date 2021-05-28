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

const int MAXN = 2000007;
const int LOGN = 23;

// int p[MAXN], c[LOGN][MAXN];
// int pn[MAXN], cnt[LOGN][MAXN];

string s;
int f[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    memset(f, -1, sizeof(f));

    cin >> s; s += s;
    int N = s.length();
    
    int k = 0;
    FOR(j, 1, N){
        char ch = s[j];
        int i = f[j-k-1];
        while (i != -1 && ch != s[k+i+1]){
            if(ch < s[k+i+1]) k = j-i-1;
            i = f[i];
        }
        if(ch != s[k+i+1]){
            if(ch < s[k]) k = j;
            f[j-k] = -1;
        }
        else f[j-k] = i+1;
    }

    cout << s.substr(k, N/2) << "\n";

    /* int alphabet = 256;
    
    FOR(i, 0, N) cnt[0][s[i]]++;
    FOR(i, 1, alphabet) cnt[0][i] += cnt[0][i-1];
    FOR(i, 0, N) p[--cnt[0][s[i]]] = i;
   	
    c[0][p[0]] = 0;
    int classes = 1;
    FOR(i, 1, N){
    	if(s[p[i]] != s[p[i-1]])
    		classes++;
    	c[0][p[i]] = classes-1;
    }

    for(int k = 0; (1 << k) < N; ++k){
    	FOR(i, 0, N){
    		pn[i] = (p[i] - (1 << k) + N) % N;
    	}

    	FOR(i, 0, N) cnt[k+1][c[k][pn[i]]]++;
    	FOR(i, 1, classes) cnt[k+1][i] += cnt[k+1][i-1];
    	for(int i = N-1; i > -1; i--){
    		p[--cnt[k+1][c[k][pn[i]]]] = pn[i];
    	}

    	c[k+1][p[0]] = 0;
    	classes = 1;
    	FOR(i, 1, N){
            int w = c[k][p[i]],
                x = c[k][(p[i]+(1 << k)) % N],
                y = c[k][p[i-1]],
                z = c[k][(p[i-1]+(1 << k)) % N];
    		if(w != y || x != z)
    			classes++;
    		c[k+1][p[i]] = classes-1;
    	}
    }

    int idx = p[0];
    if(idx >= N/2){
        cout << s.substr(idx, N/2) << s.substr(0, idx-N/2) << "\n";
    }
    else{
        cout << s.substr(idx, N/2) << "\n";
    } */
    return 0;
}