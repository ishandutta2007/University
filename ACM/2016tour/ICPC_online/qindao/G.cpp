/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template <class T>
inline void RD(T &x) {
  char c=getchar(); 
  x=0;
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){ 
    x=x*10+c-'0';
    c=getchar(); 
  }
}
const int oo = 1e9+7;
const int maxn = 1e4+20;

int a[60], n;

map<ll, string> mp;

void pre()
{
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
      for (int k = j; k < n; k++)
      {

      }
}



int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    mp.clear();
    pre();
    int Q;
    scanf("%d", &Q);
    int p1, p2, p3;
    while(Q--)
    {
      scanf("%d%d%d", &p1,&p2,&p3);
      p1--;p2--;p3--;
      if (check(p1,p2,p3))
        puts("Yes");
      else
        puts("No");
    }
  }
  return 0;
}

