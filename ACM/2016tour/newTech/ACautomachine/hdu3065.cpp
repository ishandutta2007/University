#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <queue>
#define X first
#define Y second
#define next Nnext
using namespace std;
const int maxn = 30*1020;

struct ACAuto {
  struct Trie {
    // 26 字符出现范围
    // cnt 节点计数
    int fail, next[26], id;
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
    for (int i = 0; i < 26; i++)
      trie[tot].next[i] = 0;
    trie[tot].fail = trie[tot].id = 0;
    return tot;
  }
  void insert(char *s, int id) {
    int cur = 1;
    for (int i = 0; s[i]; i++) {
      if (!trie[cur].next[s[i]-'A'])
        trie[cur].next[s[i]-'A'] = new_node();
      cur = trie[cur].next[s[i]-'A'];
    }
    trie[cur].id = id;
  }
  void build() {
    deque<int> q;
    q.push_back(1);
    trie[1].fail = 1;
    while(!q.empty()) {
      int cur = q.front();q.pop_front();
      for (int i = 0; i < 26; i++) if (trie[cur].next[i]) {
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
  map<int,int> query(char *s) {
    int cur = 1, tmp;
    map<int,int> ret;
    for (int i = 0; s[i]; i++) {
      if (s[i] < 'A' || s[i] > 'Z')
      {
        cur = 1;
        continue;
      }
      if (trie[cur].next[s[i]-'A']) cur = trie[cur].next[s[i]-'A'];
      else {
        while(cur != 1 && trie[cur].next[s[i]-'A'] == 0) cur = trie[cur].fail;
        if (trie[cur].next[s[i]-'A']) cur = trie[cur].next[s[i]-'A'];
      }
      tmp = cur;
      while(tmp != 1 && trie[tmp].id != 0) {
        if (!ret.count(trie[tmp].id)) ret[trie[tmp].id] = 0;
        ret[trie[tmp].id]++;
        tmp = trie[tmp].fail;
      }
    }
    return ret;
  }
}acat;

char ss[2200001];
char src[1020][55];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif
  // printf("%d\n", sizeof(trie) / 1024);
  char s[60];
  int n;
  while(scanf("%d", &n) == 1)
  {
    acat.clear();
    for (int i = 1; i <= n; i++)
    {
      scanf("%s", src[i]);
      acat.insert(src[i], i);
    }
    acat.build();
    scanf("%s", ss);
    map<int, int> tmp;
    tmp = acat.query(ss);
    for (auto x : tmp)
      printf("%s: %d\n", src[x.X], x.Y);
  }
  return 0;
}

