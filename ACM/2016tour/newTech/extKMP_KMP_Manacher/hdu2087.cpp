#include <bits/stdc++.h>

using namespace std;
const int maxn = 1020;
char src[maxn],substring[maxn];
int nxt[maxn];
vector<int> ans;

void get_nxt(char* substring)
{
  int substring_len = strlen(substring);
  memset(nxt, 0, sizeof(nxt));
  nxt[0] = -1;
  int j = -1;
  for(int i = 1; i < substring_len; i++)
  {
    while(j > -1 && substring[i] != substring[j + 1])
      j = nxt[j];
    if(substring[j+1] == substring[i])
      j = j + 1;
    nxt[i] = j;
  }
}
//process src & substring to get the position
void kmp(char* src, char* substring)
{
  int j = -1;
  int substring_len = strlen(substring);
  int src_len = strlen(src);
  for(int i = 0; i < src_len; i++)
  {
    while(j > -1 && src[i] != substring[j + 1])
      j = nxt[j];
    if(src[i] == substring[j + 1])
      j++;
    if(j == substring_len -1)
    {
      ans.push_back(i+1);
      //ans ++;
      //    printf("From position %d to position %d\n", i + 2 - substring_len, i+1);
      j = nxt[j];
    }
  }
}


int main()
{
  while(scanf("%s", src) != EOF)
  {
    if (strlen(src) == 1 && src[0] == '#')
      break;
    scanf("%s", substring);
    ans.clear();
    get_nxt(substring);
    kmp(src, substring);
    
    if (ans.size() == 0)
    {
      printf("0\n");
      continue;
    }
    int tans = 0, substring_len = strlen(substring);
    int pre = -1;
    for (int i = 0, len = ans.size(); i < len; i++)
      if (pre == -1 || ans[i] - ans[pre] >= substring_len) tans++, pre = i;

    printf("%d\n", tans);
  }

  return 0;
}



