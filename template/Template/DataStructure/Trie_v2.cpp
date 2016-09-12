struct Trie{
  int next[26], cnt;
  void clear() {
    memset(next,0,sizeof(next));
  }
}trie[maxn];
int tot;
void insert(char *s)
{
  int cur = 1;
  for(int i = 0; s[i]; i++)
  {
    if(!trie[cur].next[s[i]-'a']) {
      trie[cur].next[s[i]-'a'] = ++tot;
      trie[tot].clear();
    }
    cur = trie[cur].next[s[i]-'a'];
  }
  trie[cur].cnt++;
}
int query(char *s) {
  int cur = 1;
  for (int i=0;s[i];i++) {
    if (trie[cur].next[s[i]-'a'])
      cur = trie[cur].next[s[i]-'a'];
    else
      return 0;
  }
  return trie[cur].cnt;
}
