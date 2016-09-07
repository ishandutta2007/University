/*
 *  康拓展开
 *  元素个数 len
 *  元素0-9
 *  0-based count
 *  last edit : 2015/9/25
 */
int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
int cantor(int* a,int len)
{
  int ret = 0;
  for(int i = 0; i < len; i++)
  {
    int tmp = 0;
    for(int j = i+1; j < len; j++)if(a[i] > a[j]) tmp++;
    ret += tmp * fact[len-i-1];
  }
  return ret;
}

void cantorrev(int* a,int d, int len)
{
  int vis[10] = {0}, tmp, tt;
  for(int i = 0; i < len; i++)
  {
    tmp = d / fact[len-i-1];
    d %= fact[len-i-1];
    //the min
    tt = 0;
    while(tmp || vis[tt])
    {
      if(vis[tt] == 0)
        tmp--;
      tt++;
    }
    vis[tt] = 1;
    a[i] = tt;
  }
}
