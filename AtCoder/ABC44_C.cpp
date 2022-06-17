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

const int MAX_SUM = 50 * 50 + 1;

int N, A, cards[53];
ll memo[53][53][MAX_SUM];

ll get_solution(int idx, int l, int sum)
{
    if (idx == N || sum >= MAX_SUM)
        return 0;
    if (memo[idx][l][sum] != -1)
        return memo[idx][l][sum];

    ll total_cnt = 0;

    double _sum = sum + cards[idx] * 1.0;
    int _l = l + 1;
    if (_sum / _l == A * 1.0)
        total_cnt += 1;

    ll a = get_solution(idx + 1, l, sum);
    ll b = get_solution(idx + 1, l + 1, sum + cards[idx]);
    total_cnt += max(a, 0ll) + max(b, 0ll);

    memo[idx][l][sum] = total_cnt;
    return memo[idx][l][sum];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> N >> A;
    FOR(i, 0, N)
    {
        cin >> cards[i];
    }

    memset(memo, -1, sizeof(memo));
    cout << get_solution(0, 0, 0);

    return 0;
}
