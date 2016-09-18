#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int oo = 1e9+7;
const int maxn = 5e6+20;
struct Trie{
  int next[5], cnt;
  void clear() {
    cnt = 0;
    memset(next,0,sizeof(next));
  }
}trie[maxn];
int tot;
void insert(char *s, int d)
{
  int cur = 1;
  for(int i = 0; s[i]; i++)
  {
    if(!trie[cur].next[s[i]-'0']) {
      trie[cur].next[s[i]-'0'] = ++tot;
      trie[tot].clear();
    }
    cur = trie[cur].next[s[i]-'0'];
  }
  trie[cur].cnt+=d;
}
int query(char *s) {
  int cur = 1;
  for (int i=0;s[i];i++) {
    if (trie[cur].next[s[i]-'0'])
      cur = trie[cur].next[s[i]-'0'];
    else
      return 0;
  }
  return trie[cur].cnt;
}

int main()
{
  tot = 1;
  trie[tot].clear();
  int Q;
  scanf("%d", &Q);
  char cmd[10], bf[30];
  char tmp[30];
  memset(tmp, 0, sizeof(tmp));
  while(Q--)
  {
    scanf("%s%s", cmd, bf);
    int len = strlen(bf)-1;
    for (int i = 17; i >= 0; i--)
    {
      if (len >= 0)
      {
        if ((bf[len]-'0')%2==0) tmp[i] = '0';
        else tmp[i] = '1';
        len--;
      }
      else
        tmp[i] = '0';
    }
    //printf("%s\n", tmp);
    if (cmd[0] == '+')
      insert(tmp, 1);
    else if (cmd[0] == '-')
      insert(tmp, -1);
    else
    {
      int d = query(tmp);
      printf("%d\n", d);
    }
  }
  return 0;
}
