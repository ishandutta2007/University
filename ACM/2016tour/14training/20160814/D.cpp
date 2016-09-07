#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int maxn = 20;

typedef pair<int,int> pii;
priority_queue<pii> pq;
int n;
int a[maxn];
pii top1, top2, top3;

int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d", &n);
    int ans = 0, tot = 0;
    while(!pq.empty()) pq.pop();
    for (int i = 0; i <= n; i++)
    {
      scanf("%d", &a[i]);
      tot += a[i];
      pq.push_back(pii(a[i], i));
    }
    while(!pq.empty())
    {
      top1 = pq.top();
      pq.pop();
      if (pq.empty())
      {
        ans++;
        break;
      }
      top2 = pq.top();
      pq.pop();
      
      if (pq.empty())
      {
        ans += 
      }

    }

    printf("Case #%d: %d\n", min(ans, tot/2));

  }
}
