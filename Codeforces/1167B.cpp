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

const int MAX = 200007;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    vector<int> a = {4, 8, 15, 16, 23, 42};
    int ans[4];
    
    for(int i = 0; i < 4; i++){
        cout << "? " << i+1 << " " << i+2 << endl;
        cout.flush();
        cin >> ans[i];
    }

    do {
        bool flag = true;
        for(int i = 0; i < 4; i++){
            flag &= (a[i]*a[i+1] == ans[i]);
        }
        if(flag) break;
    } while(next_permutation(a.begin(), a.end()));

    cout << "!";
    for(int i = 0; i < 6; i++){
        cout << " " << a[i]; 
    }
    cout << endl;
    cout.flush();

    return 0;
}
