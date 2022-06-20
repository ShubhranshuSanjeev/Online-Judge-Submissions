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

    multiset<int> ms;
    int Q;
    cin >> Q;

    FOR(i, 0, Q)
    {
        int t, x, c;
        cin >> t;

        if (t == 1)
        {
            cin >> x;
            ms.insert(x);
        }
        else if (t == 2)
        {
            cin >> x >> c;
            FOR(j, 0, c)
            {
                auto pos = ms.find(x);
                if (pos == ms.end())
                {
                    break;
                }
                else
                {
                    ms.erase(pos);
                }
            }
        }
        else
        {
            int min_v = *(ms.begin());
            int max_v = *(--ms.end());
            cout << max_v - min_v << "\n";
        }
    }

    return 0;
}