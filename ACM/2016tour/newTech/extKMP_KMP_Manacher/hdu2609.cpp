#include <bits/stdc++.h>
#define X first
#define Y second
#define next Nnext
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 100000;
const int maxm = 400;

set<string> st;
char bf[maxm];


pii minstr(char *s)
{
  int l = strlen(s);
  for (int i = 0; i < l; i++) s[i+l] = s[i];
  s[2*l] = 0;
  int i = 0, j = 1;
  while(i < l && j < l)
  {
    int k = 0;
    while(s[i+k] == s[j+k] && k < l) k++;
    if (k == l)
      return pii(min(i, j), l/(abs(i-j)));
    else if(s[i+k] > s[j+k]) i = max(i+k+1, j+1);
    else j = max(j+k+1, i+1);
  }
  return pii(min(i, j), 1);
}

pii maxstr(char *s)
{
  int l = strlen(s);
  for (int i = 0; i < l; i++) s[i+l] = s[i];
  s[2*l] = 0;
  int i = 0, j = 1;
  while(i < l && j < l)
  {
    int k = 0;
    while(s[i+k] == s[j+k] && k < l) k++;
    if (k == l)
      return pii(min(i, j), l/(abs(i-j)));
    else if(s[i+k] < s[j+k]) i = max(i+k+1, j+1);
    else j = max(j+k+1, i+1);
  }
  return pii(min(i, j), 1);
}


int main()
{
  //freopen("data.in", "r", stdin);
  int n;
  while(scanf("%d", &n)!=EOF)
  {
    st.clear();
    for (int i = 0; i < n; i++)
    {
      scanf("%s", bf);
      int len = strlen(bf);
      int pos = minstr(bf).X;
      string tmp;
      for (int i = 0; i < len; i++)
        tmp.push_back(bf[pos+i]);
      st.insert(tmp);
    }
    cout << st.size() << endl;
  }
  return 0;
}
