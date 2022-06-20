#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define pll pair<ll, ll>

#define FOR(i, st, ed) for (int i = int(st); i < int(ed); i++)
#define FORS(i, st, ed, step) for (int i = int(st); i != int(ed); i += step)

int main()
{
    int n, m;
    vector<vector<piii>> adj;

    cin >> n >> m;
    adj.resize(n);

    FOR(i, 0, m)
    {
        int u, v, c;
        cin >> u >> v >> c;

        adj[u - 1].emplace_back(v - 1, make_pair(c, i + 1));
        adj[v - 1].emplace_back(u - 1, make_pair(c, i + 1));
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> cost(n + 1, -1ll);
    vector<int> edge_used(n + 1, -1);

    pq.emplace(0, 0);
    cost[0] = 0;

    while (!pq.empty())
    {
        auto topEle = pq.top();
        ll c = topEle.first;
        int u = topEle.second;

        pq.pop();
        if (c != cost[u])
        {
            continue;
        }

        for (auto edge : adj[u])
        {
            int v = edge.first;
            ll tc = edge.second.first;
            int ei = edge.second.second;

            if (cost[v] == -1 || c + tc < cost[v])
            {
                cost[v] = c + tc;
                edge_used[v] = ei;

                pq.emplace(cost[v], v);
            }
        }
    }

    for (auto edge_idx : edge_used)
    {
        if (edge_idx != -1)
            cout << edge_idx << " ";
    }
    cout << "\n";

    return 0;
}
