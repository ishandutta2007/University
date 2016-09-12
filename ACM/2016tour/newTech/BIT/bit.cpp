struct bit
{
  int s[maxn];
  int num;
  void add(int x, int z)
  {
    for (int i=x;i<=num;i+=(i&-i)) s[i]+=z;
  }
  int ask(int x)
  {
    int tmp=0;
    for (int i=x;i;i-=(i&-i)) tmp+=s[i];
    return tmp;
  }
  void clear(int n)
  {
    num=n;
    memset(s,0,sizeof(s));
  }
}bit;
