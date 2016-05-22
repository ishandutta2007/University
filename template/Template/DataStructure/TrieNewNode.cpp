struct Trie
{
  struct Node
  {
    bool end;
    int id;
    Node *next[26];
  };
  Node *head;
  void clear()
  {
    head = new Node();
  }

  void insert(char *s, int id)
  {
    int len = strlen(s);
    Node *now = head;
    for (int i = 0; i < len; i++)
    {
      int x = s[i] - 'a';
      if (now->next[x] == NULL)
      {
        now->next[x] = new Node();
        now->next[x]->end = false;
        memset(now->next[x]->next, 0, sizeof(now->next[x]->next));
      }
      now = now->next[x];
      if (i == len - 1)
      {
        now->end = true;
        now->id = id;
      }
    }
  }
  int query(char *s)
  {
    int len = strlen(s);
    Node *now = head;
    for (int i = 0; i < len; i++)
    {
      int x = s[i] - 'a';
      if (now->next[x] == NULL)
        return false;
      now = now->next[x];
      if (i == len - 1){
        if(now->end) return now->id;
        else return 0;
      }
    }
    return 0;
  }
};


