#include <bits/stdc++.h>

using namespace std;

const int maxn = 1020;
const int oo = 1e9+7;

typedef long long ll;

set<char> st;
char str[maxn];

int main()
{

  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%s", str);
    int n = strlen(str);
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
      st.clear();
      for (int d = -1; d <= 1; d++)
      {
        if (i+d >= 0 && i+d < n)
          st.insert(str[i+d]);
      }
      ans = ans*st.size()%oo;
    }
    printf("Case #%d: %d\n", ka, (int)ans);


  }
  return 0;
}
