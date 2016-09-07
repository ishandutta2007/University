#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int cnt[100];

class MakingPairs
{
public:

  int solve(int sum)
  {
    int ret = 0;
    for (int i = 0; i <= sum; i++)
    {
      ret += min(cnt[i], cnt[sum-i]);
    }
    return ret / 2;
  }

  int get(vector <int> card)
  {
    int ret = 0, n = card.size();
    for (int i = 0; i < n; i++)
      cnt[i] = card[i];
    for (int s = 0; s <= 100; s++)
    {
      ret = max(ret, solve(s));
    }
    return ret;
  }
};
