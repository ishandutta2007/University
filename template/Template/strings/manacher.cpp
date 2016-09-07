/*
 *  求最长回文字串
 *  O(n);
 *  Ma 为增加了分隔符之后的字符串
 *  Mp[i] 表示以i为中心的回文串的半径(包括自身)
 */
char Ma[maxn*2];
int Mp[maxn*2];
void manacher(char *s, int *Mp)
{
  int l = 0, len = strlen(s);
  Ma[l++] = '$';
  Ma[l++] = '#';
  for(int i = 0; i < len; i++)
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
