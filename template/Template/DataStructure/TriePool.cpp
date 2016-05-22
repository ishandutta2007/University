const int maxm = 10000000;
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
  }
  void insert(char *s, int id)
  {
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
      }
      nowid = now.next[x];
      if (i == len - 1)
      {
        node[nowid].end = true;
        node[nowid].id = id;
      }
    }
  }
  int query(char *s)
  {
    int len = strlen(s);
    int nowid = head;
    for (int i = 0; i < len; i++)
    {
      Node& now = node[nowid];
      int x = s[i] - 'a';
      if (now.next[x] == -1)
        return false;
      nowid = now.next[x];
      if (i == len - 1){
        if(node[nowid].end) return node[nowid].id;
        else return 0;
      }
    }
    return 0;
  }
};
