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

    int N, Q;
    cin >> N;

    vector<ll> arr(N);
    vector<ll> updated_till(N, -1);
    FOR(i, 0, N)
    {
        cin >> arr[i];
    }

    cin >> Q;

    ll new_val = -1;
    ll T, a, b, latest_update = -1;
    FOR(i, 0, Q)
    {
        cin >> T;

        if (T == 1)
        {
            cin >> a;
            new_val = a;
            latest_update = i;
        }
        else if (T == 2)
        {
            cin >> a >> b;
            if (new_val != -1 && updated_till[a - 1] < latest_update)
            {
                arr[a - 1] = new_val + b;
                updated_till[a - 1] = latest_update;
            }
            else
            {
                arr[a - 1] += b;
            }
        }
        else
        {
            cin >> a;
            if (updated_till[a - 1] < latest_update)
            {
                cout << new_val << "\n";
                arr[a - 1] = new_val;
            }
            else
            {
                cout << arr[a - 1] << "\n";
            }
        }
    }

    return 0;
}