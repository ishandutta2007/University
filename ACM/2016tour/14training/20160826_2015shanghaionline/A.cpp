#include <bits/stdc++.h>

using namespace std;

const int maxn = 100020;

// 非递归
int gcd(int a,int b)
{
  if (a < b) swap(a, b);
  int Rem;
  while(b > 0)
  {
    Rem = a % b;
    a = b;
    b = Rem;
  }
  return a;
}

void solve()
{
  

}



int main()
{
  int T;
  scanf("%d", &T);

  for (int ka = 1; ka <= T; ka++)
  {
    printf("Case #%d:\n", ka);

    int n, q;
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    
    solve();
    
    char cmd[10], p1, p2;
    while(q--)
    {
      scanf("%s%d%d", cmd, &p1, &p2);

      

    }


  }
  return 0;
}
