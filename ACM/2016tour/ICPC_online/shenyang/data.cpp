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
  freopen("data.in", "w", stdout);

  printf("10\n");

  for (int i = 0; i < 10; i++)
  {
    printf("300\n");
    for (int i = 1; i <= 300; i++)
      printf("2 ");
    printf("\n");
    for (int i = 1; i <= 300; i++)
      printf("2 ");
    printf("\n");  
  }
  return 0;
}

