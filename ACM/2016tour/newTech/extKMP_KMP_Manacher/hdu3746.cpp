#include <bits/stdc++.h>

using namespace std;
const int maxn = 100020;
char src[maxn];
int nxt[maxn];

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
void getnext1(const char *p) //前缀函数(滑步函数)  
{  
    int i = 0, j = -1;  
    nxt[0] = -1;  
    int  len = strlen(p);
    while(i != len)  
    {  
        if(j == -1 || p[i] == p[j]) //(全部不相等从新匹配 || 相等继续下次匹配)  
        {  
            ++i, ++j;  
            if(p[i] != p[j]) //abcdabce  
                nxt[i] = j;  
            else //abcabca  
                nxt[i] = nxt[j];  
        }  
        else  
            j = nxt[j]; //子串移动到第nxt[j]个字符和主串相应字符比较  
    }  
}  
void getnext2(const char *s)  
{  
    int i = 0, j = -1;  
    nxt[0] = -1;  
    int len = strlen(s);
    while(i != len)  
    {  
        if(j == -1 || s[i] == s[j])  
            nxt[++i] = ++j;  
        else  
            j = nxt[j];  
    }  
}  

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%s", src);
    memset(nxt, 0, sizeof(nxt));
    get_nxt(src);
    for (int i = 0, len = strlen(src); i < len; i++)
      printf("%d ", nxt[i]);
    printf("\n");
    memset(nxt, 0, sizeof(nxt));
    getnext1(src);
    for (int i = 0, len = strlen(src); i < len; i++)
      printf("%d ", nxt[i]);
    printf("\n");
    memset(nxt, 0, sizeof(nxt));
    getnext2(src);
    for (int i = 0, len = strlen(src); i < len; i++)
      printf("%d ", nxt[i]);
    printf("\n");
  }
  return 0;
}
