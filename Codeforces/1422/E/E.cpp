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
using namespace std;

string str;
int N;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("inp1.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> str;
    N = str.size();

    auto ch = ivec1d(char, N+1, '`');
    auto dp = ivec1d(int, N+1, N+1);
    auto ans = ivec1d(string, N+1, "");
    dp[N] = 0;

    for(int i = N-1; i >= 0; i--){
        bool flag = false;
        if(i < N-1 && str[i] == str[i+1]){
            if(dp[i+1] == 0 ||
              (ans[i+2][0] == str[i] && ch[i+2] < str[i])||
              (ans[i+2][0] < str[i])){
                dp[i] = dp[i+2];
                ans[i] = ans[i+2];
                ch[i] = ch[i+2];
                flag = true;
            }
        }

        if(!flag){
            dp[i] = 1 + dp[i+1];
            ans[i] += str[i];

            if(dp[i] > 10){
                for(int j = 0; j < 4; j++)
                    ans[i] += ans[i+1][j];
                for(int j = 0; j < 3; j++)
                    ans[i] += '.';
                for(int j = 8; j < 10; j++)
                    ans[i] += ans[i+1][j];
            }
            else ans[i] += ans[i+1];

            if(i == N-1 || ans[i+1][0] == str[i])
                ch[i] = ch[i+1];
            else
                ch[i] = ans[i+1][0];
        }
    }

    FOR(i, 0, N){
        cout << dp[i] << " " << ans[i] << "\n";
    }

    // t[N-1]=s[N-1]=ps[N-1]=0;
    // for(int i = N-2; i > -1; i--){
    //     if(str[i] < str[i+1]) t[i] = 1;
    //     else if(str[i] > str[i+1]) t[i] = 0;
    //     else t[i] = t[i+1];
    // }
    // int it = N-2;
    // while(it > -1){
    //     if(!t[it] && str[it] == str[it+1]){
    //         s[it] = 1;
    //         it-=2;
    //     }
    //     else{
    //         s[it] = 0;
    //         it--;
    //     }
    // }

    // // cout << str << "\n";
    // FOR(i, 0, N) cout << t[i] << " ";
    // cout << "\n";
    // FOR(i, 0, N) cout << s[i] << " ";
    // cout << "\n";

    // ps[N-1] = s[N-1];
    // for(int i = N-2; i > -1; i--){
    //     ps[i] = s[i] + ps[i+1];
    // }

    // // FOR(i, 0, N) cout << s[i] << " ";
    // // cout << "\n";


    // FOR(i, 0, N){
    //     int l = (N-i-2*ps[i]);
    //     cout << l << " ";
    //     int j = i;
    //     if(l > 10){
    //         int last;
    //         int j = N-1, cnt = 0;
    //         while(j > -1){
    //             if(!s[j] && !s[j-1]){
    //                 last = j-1;
    //                 break;
    //             }
    //             j--;
    //         }
    //         j = i;
    //         while(cnt < 5){
    //             if(s[j]){
    //                 j+=2;
    //                 continue;
    //             }
    //             cout << str[j];
    //             j++; cnt++;
    //         }
    //         cout << "..." << str[last] << str[last+1] << "\n";
    //     }
    //     else{
    //         while(j < N){
    //             if(s[j]){
    //                 j+=2;
    //                 continue;
    //             }
    //             cout << str[j];
    //             j++;
    //         }
    //         cout << "\n";
    //     }
    // }

    return 0;
}