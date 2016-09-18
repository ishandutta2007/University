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
const int maxn = 1e5+20;

int a[maxn];
int n,c;

int main()
{
  scanf("%d%d", &n,&c);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  
  int ans = 1;
  for (int i = n-1; i >= 1; i--)
  {
    if (a[i+1]-a[i] <= c)
      ans++;
    else
      break;
  }
  
  printf("%d\n", ans);

  return 0;
}

