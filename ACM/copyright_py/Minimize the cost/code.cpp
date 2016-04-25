#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

PII pii[1020], p[1020];
int S, n;
bool cmpls(PII a, PII b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main()
{
    int T;
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
      scanf("%d%d", &S, &n);
      for (int i = 0; i < n; i++)
        scanf("%d%d", &pii[i].first, &pii[i].second);
      sort(pii, pii + n, cmpls);
      int tmpn = 1;
      p[0] = pii[0];
      for (int i = 1; i < n; i++)
        if(pii[i].second > p[tmpn-1].second)
          p[tmpn++] = pii[i];
      n = tmpn;
      int now = 0;
      int ans = 0;
      int pos = 0;
      while(now < S)
      {
        while(pos + 1 < n && p[pos+1].first <= now)
          pos++;
        if(p[pos].first > now || pos >= n)
        {
          ans = -1;
          break;
        }
        else
        {
          ans++;
          now = p[pos].second;
          pos ++;
        }
      }
      printf("%d\n", ans);
    }
    return 0;
}