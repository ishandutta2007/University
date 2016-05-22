#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

const int maxm = 12000000;
struct Trie
{
  struct Node
  {
    bool end;
    int id;
    int next[26];
  }node[maxm];
  int head, tot;
  void clear()
  {
    head = 0;
    memset(node[head].next, -1, sizeof(node[head].next));
    tot = 0;
    node[head].id = 1000000000;
  }
  void insert(char *s, int id)
  {
//    printf("insert %s : %d\n", s, id);
    int len = strlen(s);
    int nowid = head;
    for (int i = 0; i < len; i++)
    {
      Node& now = node[nowid];
      int x = s[i] - 'a';
      if (now.next[x] == -1)
      {
        now.next[x] = ++tot;
        node[tot].end = false;
        memset(node[tot].next, -1, sizeof(node[tot].next));
        node[tot].id = 0;
      }
      nowid = now.next[x];
      node[nowid].id += id;
      if (node[nowid].id <= 0)
      {
        node[nowid].id = 0;
        memset(node[nowid].next, -1, sizeof(node[nowid].next));
      }
    }
  }
  int query(char *s)
  {
    int len = strlen(s);
    int nowid = head;
    int mm = 100000000;
    for (int i = 0; i < len; i++)
    {
      Node& now = node[nowid];
      if (now.id <= 0) return 0;
      mm = min(mm, now.id);
      int x = s[i] - 'a';
      if (now.next[x] == -1)
        return 0;
      nowid = now.next[x];
      if (i == len - 1){
//        if(node[nowid].id > 0) return 1;
//        else return 0;
        return min(mm, node[nowid].id);
      }
    }
    return 0;
  }
}trie;

int n;
char cmd[10], str[40];


int main()
{
  scanf("%d", &n);
  trie.clear();
  while (n--)
  {
    scanf("%s %s", cmd, str);
    if (cmd[0] == 'i')
    {
      trie.insert(str, 1);
    }
    else if (cmd[0] == 's')
    {
      if (trie.query(str) > 0) printf("Yes\n");
      else printf("No\n");
    }
    else
    {
      int tmp = trie.query(str);
//      cout << "tmp : " << tmp << endl;
      if (tmp > 0) trie.insert(str, -tmp);
    }
  }


  return 0;
}

