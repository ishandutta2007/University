#include <bits/stdc++.h>
#define next Nnext
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1000000;
const int maxm = 1000000;
int next[maxn], ex[maxn];
char s[maxn] = "aaaaabbb", t[maxn] = "aaaaac";

void getExtNext(const char *t, int *next)
{
  int lt = strlen(t);
  next[0] = lt;
  for (int i = 1, j = -1, a, p; i < lt; i++, j--) 
    if (j < 0 || i + next[i-a] >= p)
    {
      if (j < 0) j = 0, p = i;
      while(p < lt && t[j] == t[p]) j++, p++;
      next[i] = j, a = i;
    }
    else next[i] = next[i-a];
}
void getExtend(const char *s, const char *t, int *extend)
{
  int ls = strlen(s), lt = strlen(t);
  getExtNext(t, next);
  // a : 最长匹配的下标
  // p : s中最长匹配的位置+1
  for (int i = 0, j = -1, a, p; i < ls; i++, j--)
    if (j < 0 || i + next[i-a] >= p)
    {
      if (j < 0) j = 0, p = i;
      while(p < ls && j < lt && s[p] == t[j]) j++, p++;
      extend[i] = j, a = i;
    }
    else
      extend[i] = next[i-a];
}
/*
void pre_exkmp(const char *P)  
{  
  int m=strlen(P);  
  next[0]=m;  
  int j=0,k=1;  
  while(j+1<m&&P[j]==P[j+1]) j++;  
  next[1]=j;  
  for(int i=2;i<m;i++)  
  {  
    int p=next[k]+k-1;  
    int L=next[i-k];  
    if(i+L<p+1) next[i]=L;  
    else  
    {  
      j=max(0,p-i+1);  
      while(i+j<m&&P[i+j]==P[j]) j++;  
      next[i]=j; k=i;  
    }  
  }  
}  
void exkmp(const char *T,const char *P)  
{  
  int m=strlen(P),n=strlen(T);  
  pre_exkmp(P);  
  int j=0,k=0;  
  while(j<n&&j<m&&P[j]==T[j]) j++;  
  ex[0]=j;  
  for(int i=1;i<n;i++)  
  {  
    int p=ex[k]+k-1;  
    int L=next[i-k];  
    if(i+L<p+1) ex[i]=L;  
    else  
    {  
      j=max(0,p-i+1);  
      while(i+j<n&&j<m&&T[i+j]==P[j]) j++;  
      ex[i]=j; k=i;  
    }  
  }  
}
*/
int main()
{
  getExtend(s, t, ex);
//  exkmp(s, t);
  for (int i = 0, len = strlen(s); i < len; i++)
    printf("%d ", ex[i]);
  printf("\n");

  for (int i = 0, len = strlen(t); i < len; i++)
    printf("%d ", next[i]);
  printf("\n");

  return 0;
}
