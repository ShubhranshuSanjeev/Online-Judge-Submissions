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

const ll mod = 1e9 + 7;
const int MAX = 1e6 + 7;

ll inv[MAX];
ll fact[MAX];

ll modpow(ll a, ll b)
{
  ll res = 1;
  while (b)
  {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

ll nCr(int n, int r)
{
  if (r == 0 || n == r)
    return 1;
  return fact[n] * inv[r] % mod * inv[n - r] % mod;
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

  int H, W, A, B;

  cin >> H >> W >> A >> B;

  fact[0] = 1;
  FOR(i, 1, MAX + 2)
  {
    fact[i] = fact[i - 1] * i % mod;
    inv[i] = modpow(fact[i], mod - 2);
  }

  vector<ll> a;
  vector<ll> b;
  FOR(i, B + 1, W + 1)
  {
    int n = H - A + i - 2;
    int r = i - 1;

    a.push_back(nCr(n, r));
  }
  FORS(i, W - B, 0, -1)
  {
    int n = A + i - 2;
    int r = i - 1;

    b.push_back(nCr(n, r));
  }

  ll total_paths = 0;
  FOR(i, 0, a.size())
  {
    total_paths = (total_paths + a[i] * b[i] % mod) % mod;
  }

  cout << (total_paths % mod) << "\n";

  return 0;
}
