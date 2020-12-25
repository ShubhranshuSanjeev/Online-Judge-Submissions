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

const int MAX = 2000007;
const int LOGN = (int)log2(MAX) + 2;
const int CHA = 256;

int p[MAX], c[LOGN][MAX], cnt[MAX];
int pn[MAX], cn[MAX], inv_suff[MAX];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string str, str2;
    cin >> str >> str2;

    int len_a = (int)str.size();
    str += "$";
    str += str2;
    int len = (int)str.size();

    // vec1d(int) p(len), c(len);
    // vec1d(int) cnt(max(len, alphabets));

    for(int i = 0; i < len; i++) cnt[str[i]]++;
    for(int i = 1; i < CHA; i++) cnt[i] += cnt[i-1];
    for(int i = 0; i < len; i++) p[--cnt[str[i]]] = i; 

    int classes = 1;
	c[0][p[0]] = 0;
	for(int i = 1; i < len; i++){
		if(str[p[i]] != str[p[i-1]])
			classes++;
		c[0][p[i]] = classes-1;
	}

	// vec1d(int) pn(len), cn(len);
	for(int k = 0; (1 << k) < len; k++){
		for(int i = 0; i < len; i++){
			pn[i] = (p[i] - (1 << k) + len) % len;
		}

		fill(cnt, cnt+classes, 0);
		for(int i = 0; i < len; i++) cnt[c[k][pn[i]]]++;
		for(int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
		for(int i = 0; i < len; i++) p[--cnt[c[k][pn[i]]]] = pn[i];

		classes = 1;
		c[k+1][p[0]] = 0;
		for(int i = 1; i < len; i++){
			// pair<int, int> p1 = make_pair(c[p[i]], c[(p[i] + (1 << k))%len]);
			// pair<int, int> p2 = make_pair(c[p[i-1]], c[(p[i-1] + (1 << k))%len]);
			bool f1 = c[k][p[i]] != c[k][p[i-1]];
			bool f2 = c[k][(p[i] + (1 << k))%len] != c[k][(p[i-1] + (1 << k))%len];
			if(f1 || f2)
				classes++;
			c[k+1][p[i]] = classes-1;
		}

		// swap(c, cn);
	}

	// vec1d(int) lcp(len);
	// vec1d(int) inv_suff(len, 0);
    for(int i = 0; i < len; i++) inv_suff[p[i]] = i;
    
    int k = 0, ans = 0;
    for(int i = 0; i < len; i++){
        if(inv_suff[i] == len-1){
            k = 0;
            continue;
        }

        int j = p[inv_suff[i] + 1];
        while(i+k < len && j+k < len && str[i+k] == str[j+k] && str[i+k] != '$')
            k++;

        bool f1 = j < len_a;
        bool f2 = p[inv_suff[i]] > len_a;
        if((f1&&f2) || (!f1&&!f2))
        	ans = max(ans, k);

        if(k) --k;
    }

    cout << ans << "\n";
    return 0;
}
