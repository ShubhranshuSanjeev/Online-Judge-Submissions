#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>

#define FOR(i, st, ed) for (int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for (int i = int(st); i != int(ed); i += step)

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    unordered_set<int> indxs;

    int max_tastiness = 0;
    FOR(i, 0, N)
    {
        cin >> A[i];
        max_tastiness = max(A[i], max_tastiness);
    }
    FOR(i, 0, N)
    {
        if (A[i] == max_tastiness)
        {
            indxs.insert(i + 1);
        }
    }

    bool ans = false;
    FOR(i, 0, K)
    {
        int bi;
        cin >> bi;

        if (indxs.find(bi) != indxs.end())
        {
            ans = true;
        }
    }

    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}