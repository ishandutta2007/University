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

int main() {
  freopen("data2.in", "w", stdout);
  
  srand(time(NULL));

  int t = 10;
  int n = 10000;
  int rg1 = 2;
  printf("%d\n", t);
  for (int i = 1; i <= t; i++) {
    printf("%d %d %d %d\n", n, n, 1, n);
    for (int i = 1; i <= n; i++) {
      printf("%d %d %d\n", rand()%n+1, rand()%n+1, rand()%rg1);
    }
  }

  return 0;
}

