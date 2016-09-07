#include <bits/stdc++.h>

using namespace std;

// 1. 如果a,b都是偶数, 则gcd(a, b) = gcd(a/2, b/2)  
// 2. 如果a是奇数, b是偶数,  则gcd(a, b) =  gcd(a, b/2)  
// 3. 如果a,b都是奇数, 则gcd(a, b) = gcd((a-b)/2, b)  

const int maxn = 1020;

string Zero = "0";
char bfa[maxn], bfb[maxn];
char a[maxn], b[maxn];


int sub(char* &a, char *b, int la, int lb)
{
  int c = 0;
  int d1, d2, d;
  for (int i = 0; i < la; i++)
  {
    d1 = a[la-i-1];
    if (lb-i-1>=0)
      d2 = b[lb-i-1];
    else
      d2 = 0;
    d2 += c;
    c = 0;
    if (d1 < d2)
    {
      d1 +=2;
      c = 1;
    }
    d = d1-d2;
    a[la-i-1] = d;
  }
  while(a[0] == 0)
  {
    la--;
    a++;
  }
  return la;
}

int gcd()
{
  unsigned k = 0;
  int *as = a, *bs = b;
  int la = lena, lb = lenb;
  while(as[0] == 0 && bs[0] == 0)
  {
    as++;la--;
    bs++;lb--;
    k++;
  }
  while(as[0] == 0)
  {
    as++;
    la--;
  }
  while(lb > 0)
  {
    while(bs[0] == 0)
    {
      bs++;
      lb--;
    }
    strncpy(tmp, bs, lb);
    lt = lb;
    if (scmp(bs, as) < 0)
    {
      swap(bs, as);
      swap(la, lb);
    }
    lb = sub(bs, as, lb, la);
    strncpy(as, tmp, lt);
    la = lt;
  }
  for (int i = 0; i < k; i++)
  {
    as--;
    as[0] = 0;
    la++;
  }
  return la;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%s%s", bfa, bfb);
    lena = strlen(bfa);
    lenb = strlen(bfb);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int pos = 1000;
    
    for (int i = 0; i < lena; i++)
      a[i] = bfa[lena-i-1] - '0';
    for (int i = 0; i < lenb; i++)
      b[i] = bfb[lenb-i-1] - '0';
    int len = gcd();
    printf("Case #%d: ", ka);
    for (int i = len-1; i >= 0; i--)
      printf("%d", a[i]);
    printf("\n");
  }
  return 0;
}

