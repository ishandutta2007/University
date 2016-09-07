#include <bits/stdc++.h>

using namespace std;

const int maxn = 100020;
char str[maxn];
int a[maxn], vis[maxn];
int n;

vector<int> ans;

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    scanf("%d", &n);
    scanf("%s", str+1);
    for (int i = 1; i <= n; i++)
    {
      if (str[i] == 'B') a[i] = 0;
      else a[i] = 1;
    }


    bool flag = 1;
    ans.clear();
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n && flag; i++) if (!vis[i])
    {
      if (a[i] == 1)
      {
        ans.push_back(i);
        a[i+1]^=1;
        vis[i] = 1;
      }
      else
      {
        int p = i;
        while(a[p] == 0 && p <= n)
          p++;
        a[p+1] ^= 1;
        if (p>n) flag = 0;
        for (int j = p; j >= i; j--)
        {
          ans.push_back(j);
          vis[j] = 1;
        }
      }
    }

    if (flag)
    {
      printf("Y\n");
      for (int i = 0;i < n; i++)
        printf("%d%c", ans[i], i==n-1? '\n':' ');
    }
    else
      printf("N\n");
  }
  return 0;
}
