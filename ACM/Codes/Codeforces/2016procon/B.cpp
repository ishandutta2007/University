#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;

int b[maxn*2], n;
int pre[maxn];
int ans[maxn];
set<int> st;
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &b[i]);
    st.insert(b[i]);
    b[i+n] = b[i];
  }

  for (int i = 0; i < 2*n; i++)
  {
    int x = b[i];
    ans[x] = max(ans[x], i-pre[x]);
    pre[x] = i;
  }
  int tmp = 1e9;
  for(int x: st)
  {
    tmp = min(tmp, ans[x]);
  }
  
  printf("%d\n", tmp + n -1 );

  return 0;
}
