/*
 *  求最长回文字串
 *  O(n);
 */
const int maxn = 2100000;
char Ma[maxn*2];
int Mp[maxn*2];
char s[maxn];
void manacher(int len)
{
  int l = 0;
  Ma[l++] = '$';
  Ma[l++] = '#';
  for(int i = 0; i <len; i++)
  {
    Ma[l++] = s[i];
    Ma[l++] = '#';
  }
  Ma[l] = 0;
  int mx = 0, id = 0;
  for(int i = 0; i < l; i++)
  {
    Mp[i] = mx>i? min(Mp[2*id-i],mx-i):1;
    while(Ma[i+Mp[i]] == Ma[i-Mp[i]]) Mp[i]++;
    if(i+Mp[i]>mx)
    {
      mx = i + Mp[i];
      id = i;
    }
  }
}
int main()
{
  while(scanf("%s", s) != EOF)
  {
    scanf("%s", s);

    int len = strlen(s);
    manacher(len);
    int ans = 0;
    for(int i = 0; i < len*2+2; i++)
    {
      ans = max(ans, Mp[i]-1);
      // printf("%d ", Mp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
