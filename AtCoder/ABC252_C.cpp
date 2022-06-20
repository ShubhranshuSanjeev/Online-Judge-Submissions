#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>

#define FOR(i, st, ed) for (int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for (int i = int(st); i != int(ed); i += step)

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> dig_pos(10);
    FOR(i, 0, N)
    {
        string s;
        cin >> s;
        FOR(j, 0, 10)
        {
            int dig = s[j] - '0';
            dig_pos[dig].push_back(j);
        }
    }

    int ans = 1e9;
    FOR(i, 0, 10)
    {
        sort(dig_pos[i].begin(), dig_pos[i].end());

        int cons_cost = 0, prev = -1;
        int tcost = 0, mcost = 0;
        for (int pos : dig_pos[i])
        {
            if (pos == prev)
            {
                cons_cost += 10;
            }
            else
            {
                cons_cost = 0;
            }

            tcost = cons_cost + pos;
            mcost = max(mcost, tcost);
            prev = pos;
        }
        ans = min(ans, mcost);
    }

    cout << ans << "\n";

    return 0;
}