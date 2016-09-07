#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;

const int maxn = 6666666;
const int MAXC = 2;
int tot;

struct Trie {
  int next[MAXC], cnt;
}trie[maxn];
int new_node()
{
  tot++;
  for (int i = 0; i < MAXC; i++)
    trie[tot].next[i] = 0;
  trie[tot].cnt = 0;
  return tot;
}
void clear() {
  tot = 0;
  new_node();
}
void insert(int d, int x) {
  int cur = 1;
  for (int i = 30; i >= 0; i--) {
    int tmp = (d>>i)&1;
    if (!trie[cur].next[tmp])
      trie[cur].next[tmp] = new_node();
    trie[cur].cnt += x;
    cur = trie[cur].next[tmp];
  }
  trie[cur].cnt+= x;
}

int query(int d) {
  int ans = 0, cur = 1, tmp, rtmp;
  for (int i = 30; i >= 0; i--) {
    tmp = (d>>i)&1;
    rtmp = tmp ^ 1;
    if (trie[trie[cur].next[rtmp]].cnt > 0)
    {
      ans += (1<<i);
      cur = trie[cur].next[rtmp];
    }
    else
    {
      cur = trie[cur].next[tmp];
    }
  }
  return ans;
}
int main()
{
  int Q, x;
  scanf("%d", &Q);
  clear();
  insert(0, 1);
  char cmd[5];
  while (Q--)
  {
    scanf("%s%d", cmd, &x);
    if (cmd[0] == '+')
      insert(x, 1);
    else if (cmd[0] == '-' && x != 0)
      insert(x, -1);
    else
      printf("%d\n", query(x));
  }
  return 0;
}
