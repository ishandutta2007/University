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

int main()
{
  freopen("data2.in", "w", stdout);
  printf("1\n");
  int n=100000;
  printf("%d\n", n);
  for (int j = 1; j <= n; j++) {
    printf("%d %d\n", 900000000+j, 1);
  }
  return 0;
}

