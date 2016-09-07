#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 40020;
const ull xxx = 123;

map<ull, int> mp;
ull H[maxn], ha[maxn];
ull xl[maxn];
int m, len, Rank[maxn];
char str[maxn];
pii ans;

void calxl()
{
  xl[0] = 1;
  for (int i = 1; i < maxn; i++)
    xl[i] = xl[i-1]*xxx;
}
void calH()
{
  for (int i = len-1; i >= 0; i--)
    H[i] = H[i+1]*xxx + str[i];
}

bool cmp(const int &a, const int &b)
{
  return (ha[a] < ha[b]) || (ha[a] == ha[b] && a < b);
}

bool check(int x)
{
  // mp.clear();
  int c = 0, f = 0;
  for (int i = 0; i + x <= len; i++)
  {
    Rank[i] = i;
    ha[i] = H[i] - H[i+x]*xl[x];
  }
  sort(Rank, Rank+len-x+1, cmp);


  // if (x == 4)
  // {
  //   for (int i = 0; i < len; i++)
  //     cout << ha[i] << ' ' << Rank[i] << endl;
  // }
  // if (x == 4)
  //   cout << '[' << pos << ']' << endl;
  for (int i = 0; i + x <= len; i++)
  {
    if (i == 0 || ha[Rank[i]] != ha[Rank[i-1]]) c = 0;
    if (++c >= m) ans = max(ans, pii(x, Rank[i])), f = 1;
  }

  // if (x == 4)
  //   cout << '[' << pos << ']' << endl;

  return f;
}

int main()
{
  calxl();
  while(scanf("%d", &m) != EOF)
  {
    if (m == 0) break;
    scanf("%s", str);
    len = strlen(str);
    calH();
    int mid, l, r;
    ans = pii(0,0);
    l = 1, r = len;

    // cout << check(4, pos) << endl;

    while(l <= r)
    {
      // cout << l << " " << r << endl;
      mid = (l+r)/2;
      if(check(mid))
      {
        l = mid + 1;
      }
      else
        r = mid - 1;
    }
    if (ans.first == 0) printf("none\n");
    else printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}
