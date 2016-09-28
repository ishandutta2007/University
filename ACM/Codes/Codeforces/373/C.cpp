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
const int maxn = 2e5+20;

char str[maxn];
int n, t;

int main() {
  
  scanf("%d%d", &n, &t);
  scanf("%s", str);
  
  int pos = -1;

  for (int i = 0; i < n; i++) {
    if (str[i] == '.') pos = i;
  }
  
  
  int pos5 = -1;

  for (int i = 0; i < n; i++) {
    if (str[i] != '.' && str[i] >= '5') {
      pos5 = i;
      break;
    }
  }

  if (pos5 == -1) {
    printf("%s\n", str);
    return 0;
  }
  
  for (int i = pos5+1; i < n; i++) {
    if (str[i] != '.') 
      str[i] = '0';
  }
  
  int R = 0;
  int len = pos5+1;

  for (int i = pos5; i>0 && t; i--) if(str[i] != '.') {
    if (str[i] >= '5') {
      str[i] = '0';
      t--;
      int pre = i-1;
      if (str[i-1] == '.') pre--;
      str[pre]++;
      len --;
    }
    else break;
  }

  if (str[0] >= '5' && t) {
    printf("1");
    str[0] = '0';
  }

  if (pos == -1) {
    printf("%s\n", str);
    return 0;
  }
  
  int r = n-1;
  while (str[r] == '0') r--;
  if(str[r] == '.') r--;
  str[r+1] = 0;
  printf("%s\n", str); 

  return 0;
}

