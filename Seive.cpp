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
#include <chrono>

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

const int MAX = 100007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int N = 100007;
    vec1d(bool) is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 2; i*i < N+1; i++){
        if(is_prime[i]){
            for(int j = i*i; j < N+1; j+=i)
                is_prime[j] = false;
        }
    }
    chrono::duration<double> finalTime = chrono::high_resolution_clock::now() - start;
    cout << finalTime.count() << "\n";

    is_prime.assign(N+1, true);
    is_prime[0]=is_prime[1] = false;
    vec1d(int) primes;
    int SPF[N+1];

    start = std::chrono::high_resolution_clock::now();
    for (int i = 2; i < N+1; i++) {
        if(is_prime[i]){
            primes.push_back(i);
            SPF[i] = i;
        }

        for(int j = 0; j < primes.size() && i*primes[j] < N && primes[j] <= SPF[i]; j++){
            is_prime[i*primes[j]] = false;
            SPF[i*primes[j]] = primes[j];
        }
    }
    finalTime = chrono::high_resolution_clock::now() - start;
    cout << finalTime.count() << "\n";

    return 0;
}