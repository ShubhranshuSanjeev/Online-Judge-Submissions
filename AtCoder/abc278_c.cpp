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
    cin >> N >> Q;

    unordered_map<int, unordered_set<int>> edges;
    FOR(i, 0, Q)
    {
        int T, A, B;
        cin >> T >> A >> B;

        if (T == 1)
        {
            edges[A].insert(B);
        }
        else if (T == 2)
        {
            edges[A].erase(B);
        }
        else
        {
            if (edges[A].find(B) != edges[A].end() && edges[B].find(A) != edges[B].end())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}