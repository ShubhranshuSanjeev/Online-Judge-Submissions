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
#define MAX 100007
#define MUL (ll)10000000
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int T, N, K, sheets[MAX], blockade[MAX];
    int p;
    string S;
    
    cin >> T;
    while (T--){
        cin >> N >> K;
        cin >> S;

        int ans = 0;
        FOR(i, 0, N){
            sheets[i] = blockade[i] = 0;
            if(S[i] == ':') sheets[i] += 1;
            else if(S[i] == 'X') blockade[i] += 1;
            
            if(i > 0) {
                sheets[i] += sheets[i-1];
                blockade[i] += blockade[i-1];
            }
        }

        int i = 0, j = 0;
        while(S[i] != 'I' && i < N) i++;
        while(S[j] != 'M' && j < N) j++;

        while(true){
            if(j >= N || i >= N) break;
            int p = K + 1 - (int)abs(i - j) - (int)abs(sheets[i] - sheets[j]);
            if(abs(blockade[i]-blockade[j]) > 0){
                if(j < i){
                    j++;
                    while(S[j] != 'X') j++;
                    while(S[j] != 'M' && j < N) j++;
                }
                else {
                    i++;
                    while(S[i] != 'X') i++;
                    while(S[i] != 'I' && i < N) i++;
                }
            }
            else if(p > 0){
                ans++;
                i++; j++;
                while(i < N && S[i] != 'I') i++;
                while(j < N && S[j] != 'M') j++;
            }
            else {
                if(j < i){
                    j++;
                    while(S[j] != 'M' && j < N) j++;    
                }
                else {
                    i++;
                    while(S[i] != 'I' && i < N) i++;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}