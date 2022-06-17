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

    string s;
    cin >> s;
    int N = s.length();

    bool found_unbalanced = false;
    FOR(i, 1, N)
    {
        if (s[i] == s[i - 1])
        {
            cout << i << " " << i + 1 << "\n";
            found_unbalanced = true;
            break;
        }
        if (i > 1 && s[i] == s[i - 2])
        {
            cout << i - 1 << " " << i + 1 << "\n";
            found_unbalanced = true;
            break;
        }
    }

    if (!found_unbalanced)
    {
        cout << "-1 -1\n";
    }
    return 0;
}