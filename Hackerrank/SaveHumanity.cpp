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

const int MAX = 1000007;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T; cin >> T;
    while(T--){

        string s, virus;
        cin >> s >> virus;
        s += '$';

        int N = s.length();
        int alphabet = 256;

        vec1d(int) p(N);
        vec1d(int) c(N);

        vec1d(int) cnt(max(N, alphabet), 0);
        
        FOR(i, 0, N) cnt[s[i]]++;
        FOR(i, 1, alphabet) cnt[i] += cnt[i-1];
        FOR(i, 0, N) p[--cnt[s[i]]] = i;
           
           c[p[0]] = 0;
           int classes = 1;
        FOR(i, 1, N){
            if(s[p[i]] != s[p[i-1]])
                classes++;
            c[p[i]] = classes-1;
        }

        vec1d(int) pn(N), cn(N);
        for(int k = 0; (1 << k) < N; ++k){
            FOR(i, 0, N){
                pn[i] = (p[i] - (1 << k) + N) % N;
            }

            fill(cnt.begin(), cnt.begin()+classes, 0);
            FOR(i, 0, N) cnt[c[pn[i]]]++;
            FOR(i, 1, classes) cnt[i] += cnt[i-1];
            for(int i = N-1; i > -1; i--){
                p[--cnt[c[pn[i]]]] = pn[i];
            }

            cn[p[0]] = 0;
            classes = 1;
            FOR(i, 1, N){
                pii curr = make_pair(c[p[i]], c[(p[i]+(1 << k)) % N]); 
                pii prev = make_pair(c[p[i-1]], c[(p[i-1]+(1 << k)) % N]);
                if(prev != curr)
                    classes++;
                cn[p[i]] = classes-1;
            }

            c.swap(cn);
        }

        p.erase(p.begin());
        N = s.length()-1;
        vec1d(int) rank(N, 0);

        FOR(i, 0, N) rank[p[i]] = i;

        vec1d(int) lcp(N, 0);
        int k = 0;

        for(int i = 0; i < N; i++){
            if(rank[i] == N-1){
                k = 0;
                continue;
            }

            int j = p[rank[i] + 1];
            while(i+k < N && j+k < N && s[i+k] == s[j+k])
                k++;

            lcp[rank[i]+1] = k;
            if(k) --k;
        }

        int v_len = virus.length();
        int prev_matched = false, prev_first_mismatch = INT32_MAX; 
        set<int> match_positions;
        FOR(i, 0, N){
            if((N-p[i]) < v_len){
            	prev_matched = false;
            	prev_first_mismatch = INT32_MAX;
                continue;
            }
            else if(lcp[i] >= v_len && prev_matched)
                match_positions.insert(p[i]);
            else if(lcp[i] >= v_len && !prev_matched)
            	continue;
            
           	int mismatch = 0, first_mismatch = INT32_MAX, st = 0;
           	if(prev_first_mismatch < lcp[i] && prev_first_mismatch < v_len){
           		mismatch = 1;
           		st = prev_first_mismatch + 1;
           	}

            FOR(j, st, v_len){
            	if(s[j+p[i]] != virus[j] && mismatch) {
            		mismatch++;
            		break;
            	}
                if(s[j+p[i]] != virus[j]) {
                	mismatch++;
                	first_mismatch = j;
                }
            }

            prev_first_mismatch = first_mismatch;
            if(mismatch < 2){
                prev_matched = true;
                match_positions.insert(p[i]);
            }
            else{
                prev_matched = false;
            }
        }

        if(match_positions.empty())
            cout << "No Match!\n";
        else{
            for(auto ele: match_positions){
                cout << ele << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
