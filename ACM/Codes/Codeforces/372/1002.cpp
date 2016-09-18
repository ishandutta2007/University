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
const int maxn = 5e4+20;

char bf[maxn];
int qm;

bool solve(int s)
{
  set<char> st;
  int qm = 0;
  int vis[26] = {0};
  for (int i = 0; i < 26; i++)
  {
    if (bf[i+s] == '?')
      qm++;
    else
    {
      st.insert(bf[i+s]);
      vis[bf[i+s]-'A'] = 1;
    }
  }
  if (qm + st.size() != 26) return false;
  int p = 0;
  for (int i = 0; i < 26; i++)
  {
    if (bf[i+s] == '?')
    {
      while(vis[p]) p++;
      printf("%c", p+'A');
      p++;
    }
    else
      printf("%c", bf[i+s]);
  }
  printf("\n");
  return true;
}


int main()
{
  scanf("%s", bf);
  int len = strlen(bf);
  
  if (len < 26)
  {
    printf("-1\n");
    return 0;
  }

  for (int i = 0; i+25 < len; i++)
  {
    if (solve(i))
      return 0;
  }
  printf("-1\n");
  return 0;
}

