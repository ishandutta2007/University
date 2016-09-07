#include <bits/stdc++.h>
#define next Nnext
using namespace std;
const int maxn = 666666;
const int MAXC = 26;
// MAC 注意 - 'a';

struct ACAuto {
  struct Trie {
    // MAXC 字符出现范围
    // cnt 节点计数
    int fail, next[MAXC], cnt;
  }trie[maxn];
  // tot 节点总数
  int tot;
  void clear() {
    tot = 0;
    new_node();
  }
  int new_node()
  {
    tot++;
    for (int i = 0; i < MAXC; i++)
      trie[tot].next[i] = 0;
    trie[tot].fail = trie[tot].cnt = 0;
    return tot;
  }
  void insert(char *s) {
    int cur = 1;
    for (int i = 0; s[i]; i++) {
      if (!trie[cur].next[s[i]-'a'])
        trie[cur].next[s[i]-'a'] = new_node();
      cur = trie[cur].next[s[i]-'a'];
    }
    trie[cur].cnt++;
  }
  void build() {
    deque<int> q;
    q.push_back(1);
    trie[1].fail = 1;
    while(!q.empty()) {
      int cur = q.front();q.pop_front();
      for (int i = 0; i < MAXC; i++) if (trie[cur].next[i]) {
        int next = trie[cur].next[i];
        if (cur == 1) trie[next].fail = 1;
        else {
          int tmp = trie[cur].fail;
          while(tmp != 1 && trie[tmp].next[i] == 0) tmp = trie[tmp].fail;
          if (trie[tmp].next[i])
            trie[next].fail = trie[tmp].next[i];
          else
            trie[next].fail = 1;
        }
        q.push_back(next);
      }
    }
  }
  int query(char *s) {
    int ans = 0, cur = 1, tmp;
    for (int i = 0; s[i]; i++) {
      if (trie[cur].next[s[i]-'a']) cur = trie[cur].next[s[i]-'a'];
      else {
        while(cur != 1 && trie[cur].next[s[i]-'a'] == 0) cur = trie[cur].fail;
        if (trie[cur].next[s[i]-'a']) cur = trie[cur].next[s[i]-'a'];
      }
      tmp = cur;
      while(tmp != 1 && trie[tmp].cnt != -1) {
        ans += trie[tmp].cnt;
        // trie[tmp].cnt = -1;
        tmp = trie[tmp].fail;
      }
    }
    return ans;
  }
}acat;

char ss[1000001];
int main()
{
  // printf("%d\n", sizeof(trie) / 1024);
  int t;
  scanf("%d", &t);
  char s[60];
  while(t--)
  {
    acat.clear();
    int n;
    scanf("%d", &n);
    while(n--)
    {
      scanf("%s", s);
      acat.insert(s);
    }
    acat.build();
    scanf("%s", ss);
    printf("%d\n", acat.query(ss));
  }
  return 0;
}

