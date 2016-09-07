#include <bits/stdc++.h>
#define next Nnext
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 80000;
int next[maxn], ex[maxn];
char s[maxn], t[maxn];


void get_next(char* substring)
{
  int substring_len = strlen(substring);
  memset(next, 0, sizeof(next));
  next[0] = -1;
  int j = -1;
  for(int i = 1; i < substring_len; i++)
  {
    while(j > -1 && substring[i] != substring[j + 1])
      j = next[j];
    if(substring[j+1] == substring[i])
      j = j + 1;
    next[i] = j;
  }
}
//process src & substring to get the position
int kmp(char* src, char* substring)
{
  int j = -1;
  int substring_len = strlen(substring);
  int src_len = strlen(src);
  get_next(substring);
  for(int i = 0; i < src_len; i++)
  {
    while(j > -1 && src[i] != substring[j + 1])
      j = next[j];
    if(src[i] == substring[j + 1])
      j++;
    if(i == src_len -1)
    {
      return j;
    }
  }
  return -1;
}

int main()
{
  while(scanf("%s%s", t, s) != EOF)
  {
    int pos = kmp(s, t), len = strlen(s);
    if (pos == -1)
      printf("0\n");
    else
    {
      for (int i = 0; i <= pos; i++)
        printf("%c", t[i]);
      printf(" %d\n", pos + 1);
    }
  }
  return 0;
}

