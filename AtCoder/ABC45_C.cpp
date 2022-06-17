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

vector<ll> digits;
int len;

ll find_solution(int idx, int last_split, vector<ll> nums)
{
    if (idx == len - 1)
    {
        ll sum = 0;
        FOR(i, last_split + 1, idx + 1)
        {
            sum = sum * 10 + digits[i];
        }
        for (ll _num : nums)
            sum += _num;

        return sum;
    }

    ll a = find_solution(idx + 1, last_split, nums);

    ll num = 0;
    FOR(i, last_split + 1, idx + 1)
    {
        num = num * 10 + digits[i];
    }

    nums.push_back(num);
    ll b = find_solution(idx + 1, idx, nums);
    nums.pop_back();

    return a + b;
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

    string s;
    cin >> s;

    len = s.size();
    for (char ch : s)
    {
        digits.push_back(ch - '0');
    }

    vector<ll> nums;
    cout << find_solution(0, -1, nums);
    return 0;
}