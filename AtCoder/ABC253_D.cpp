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
#define pii pair<int, int>
#define pll pair<ll, ll>

#define FOR(i, st, ed) for (int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for (int i = int(st); i != int(ed); i += step)
#define FOREACH(it, ds) for (auto it = ds.begin(); it != ds.end(); ++it)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll N, A, B;
    cin >> N >> A >> B;

    ll tt = (N * (N + 1)) / 2;

    ll x = N / A;
    ll y = N / B;
    ll z = N / ((A * B) / __gcd(A, B));

    tt -= ((x * (x + 1)) / 2) * A;
    tt -= ((y * (y + 1)) / 2) * B;
    tt += ((z * (z + 1)) / 2) * ((A * B) / __gcd(A, B));

    cout << tt << "\n";

    return 0;
}