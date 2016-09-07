/*
#include <bits/stdc++.h>
#define next Nnext
using namespace std;
const int maxn = 10022;

struct ACAuto {
  struct Trie {
    // 26 字符出现范围
    int fail, next[129], id;
  }trie[500*210];
  // tot 节点总数
  int tot;
  void clear() {
    //memset(trie, 0, sizeof(trie));
    memset(trie[1].next, 0, sizeof(trie[1].next));
    tot = 1;
  }
  void insert(char *s, int id) {
    int cur = 1;
    for (int i = 0; s[i]; i++) {
      if (!trie[cur].next[s[i]])
        trie[cur].next[s[i]] = ++tot;
      cur = trie[cur].next[s[i]];
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
  set<int> query(char *s) {
    set<int> st;
    int ans = 0, cur = 1, tmp;
    for (int i = 0; s[i]; i++) {
      if (trie[cur].next[s[i]]) cur = trie[cur].next[s[i]];
      else {
        while(cur != 1 && trie[cur].next[s[i]] == 0) cur = trie[cur].fail;
        if (trie[cur].next[s[i]]) cur = trie[cur].next[s[i]];
      }
      tmp = cur;
      while(tmp != 1 && trie[tmp].id != 0) {
        st.insert(trie[tmp].id);
        tmp = trie[tmp].fail;
      }
    }
    return st;
  }
};

char ss[10001];
ACAuto acat;
int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif
  printf("%d\n", sizeof(acat) / 1024);
  int t;
  int n;
  while(scanf("%d", &n) != EOF)
  {
    int ans = 0;
    acat.clear();
    for (int i = 1; i <= n; i++)
    {
      scanf("%s", ss);
      acat.insert(ss, i);
    }
    acat.build();
    cout << "!!!" << endl;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
      scanf("%s", ss);
      set<int> tmp = acat.query(ss);
      if (tmp.size())
      {
        printf("web %d:", i);
        for (auto x : tmp)
          printf(" %d", x);
        printf("\n");
        ans++;
      }
      printf("[%s]\n", ss);
    }
    printf("total: %d\n", ans);
  }
  return 0;
}
*/
#include <bits/stdc++.h>
#define next Nnext
using namespace std;
const int maxn = 100022;

struct ACAuto {
  struct Trie {
    // 26 字符出现范围
    // cnt 节点计数
    int fail, next[129], cnt, id;
  }trie[maxn];
  // tot 节点总数
  int tot;
  void clear() {
    tot = 1;
  }
  int new_node(int x) {
    memset(trie[x].next, 0, sizeof(trie[x].next));
    trie[x].fail = trie[x].cnt = trie[x].id = 0;
    return x;
  }
  void insert(char *s, int id) {
    int cur = 1;
    for (int i = 0; s[i]; i++) {
      if (!trie[cur].next[s[i]])
        trie[cur].next[s[i]] = new_node(++tot);
      cur = trie[cur].next[s[i]];
    }
    trie[cur].cnt++;
    trie[cur].id = id;
  }
  void build() {
    deque<int> q;
    q.push_back(1);
    trie[1].fail = 1;
    while(!q.empty()) {
      int cur = q.front();q.pop_front();
      for (int i = 0; i < 128; i++) if (trie[cur].next[i]) {
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
  set<int> query(char *s) {
    set<int> st;
    int ans = 0, cur = 1, tmp;
    for (int i = 0; s[i]; i++) {
      if (trie[cur].next[s[i]]) cur = trie[cur].next[s[i]];
      else {
        while(cur != 1 && trie[cur].next[s[i]] == 0) cur = trie[cur].fail;
        if (trie[cur].next[s[i]]) cur = trie[cur].next[s[i]];
      }
      tmp = cur;
      while(tmp != 1 && trie[tmp].id != 0) {
        st.insert(trie[tmp].id);
        //ans += trie[tmp].cnt;
        // trie[tmp].cnt = -1;
        tmp = trie[tmp].fail;
      }
    }
    return st;
  }
}acat;

char ss[10001];
int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif
  //printf("%d\n", sizeof(acat) / 1024);
  int t;
  char s[60];
  int n;
  while(scanf("%d", &n) != EOF)
  {
    int ans = 0;
    acat.clear();
    for (int i = 1; i <= n; i++)
    {
      scanf("%s", s);
      acat.insert(s, i);
    }
    acat.build();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
      scanf("%s", ss);
      set<int> tmp = acat.query(ss);
      if (tmp.size())
      {
        printf("web %d:", i);
        for (auto x : tmp)
          printf(" %d", x);
        printf("\n");
        ans++;
      }
    }
    printf("total: %d\n", ans);
  }
  return 0;
}
