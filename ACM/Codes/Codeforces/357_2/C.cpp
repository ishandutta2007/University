#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll oo = 1e9+7;
const int maxn = 100020;

int n;

priority_queue<int, vector<int> , greater<int> > pq;


char str[3][20] = {"insert", "getMin", "removeMin"};
char cmd[20];
vector<pii> vp;


int main()
{
  scanf("%d", &n);
  int x;
  while(n--)
  {
    scanf("%s", cmd);
    if (cmd[0] == 'i')
    {
      scanf("%d", &x);
      vp.push_back(pii(0, x));
      pq.push(x);
      // printf("%s %d\n",str[0], x);
    }

    else if(cmd[0] == 'g')
    {
      scanf("%d", &x);
      if (pq.empty())
      {
        vp.push_back(pii(0, x));
        // printf("%s %d\n", str[0], x);
        pq.push(x);
      }
      int tmp = pq.top();
      if (tmp < x)
      {
        while(!pq.empty() && pq.top() < x)
        {
          vp.push_back(pii(2, x));
          // printf("%s\n", str[2]);
          pq.pop();
        }
        if (pq.empty() || pq.top() > x)
        {
          vp.push_back(pii(0, x));
          // printf("%s %d\n", str[0], x);
          pq.push(x);
        }
      }
      else if(tmp > x)
      {
        vp.push_back(pii(0, x));
        // printf("%s %d\n", str[0], x);
        pq.push(x);
      }
      vp.push_back(pii(1, x));
      // printf("%s %d\n", str[1], x);
    }

    else
    {
      if (pq.empty())
      {
        vp.push_back(pii(0, 1));
        pq.push(1);
        // printf("%s %d\n", str[0], 1);
      }
      vp.push_back(pii(2, 1));
      pq.pop();
      // printf("%s\n", str[2]);
    }
  }

  int ans = vp.size();
  printf("%d\n", ans);

  for (int i = 0; i < ans ; i++)
  {
    if (vp[i].first == 2)
    {
      printf("%s\n", str[vp[i].first]);
    }
    else printf("%s %d\n", str[vp[i].first], vp[i].second);
  }

  return 0;
}
