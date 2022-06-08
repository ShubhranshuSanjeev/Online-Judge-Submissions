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

struct CompareDiff
{
  bool operator()(pii const &p1, pii const &p2)
  {
    if (p1.first != p2.first)
      return p1.first > p2.first;
    return p1.second < p2.second;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int N, K;
  set<int> disliked_digits;

  cin >> N >> K;
  FOR(i, 0, K)
  {
    int disliked_digit;
    cin >> disliked_digit;

    disliked_digits.insert(disliked_digit);
  }

  FOR(curr_n, N, 10 * N)
  {
    int tmp = curr_n;

    bool is_valid = true;
    while (tmp != 0)
    {
      if (disliked_digits.find(tmp % 10) != disliked_digits.end())
      {
        is_valid = false;
        break;
      }
      tmp /= 10;
    }

    if (is_valid)
    {
      cout << curr_n << "\n";
      break;
    }
  }

  return 0;
}