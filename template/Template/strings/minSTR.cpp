/*
 * minstr/maxstr(char *s)
 * 返回一个pair<int,int> 
 * first 表示最小/最大表示的起始下表
 * second 表示出现的次数
 */
typedef pair<int,int> pii;
pii minstr(char *s)
{
  int l = strlen(s);
  for (int i = 0; i < l; i++) s[i+l] = s[i];
  s[2*l] = 0;
  int i = 0, j = 1;
  while(i < l && j < l)
  {
    int k = 0;
    while(s[i+k] == s[j+k] && k < l) k++;
    if (k == l)
      return pii(min(i, j), l/(abs(i-j)));
    else if(s[i+k] > s[j+k]) i = max(i+k+1, j+1);
    else j = max(j+k+1, i+1);
  }
  return pii(min(i, j), 1);
}
pii maxstr(char *s)
{
  int l = strlen(s);
  for (int i = 0; i < l; i++) s[i+l] = s[i];
  s[2*l] = 0;
  int i = 0, j = 1;
  while(i < l && j < l)
  {
    int k = 0;
    while(s[i+k] == s[j+k] && k < l) k++;
    if (k == l)
      return pii(min(i, j), l/(abs(i-j)));
    else if(s[i+k] < s[j+k]) i = max(i+k+1, j+1);
    else j = max(j+k+1, i+1);
  }
  return pii(min(i, j), 1);
}
