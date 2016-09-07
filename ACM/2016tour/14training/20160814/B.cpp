#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000020;

unsigned short m1[maxn], m2[maxn];
unsigned short M1 = 73, M2 = 137;
char str[maxn];


int main()
{

//  cout << sizeof(m1)/1024 * 2 + sizeof(str)/1024 << endl;


  m1[0] = m2[0] = 1;
  
  for (int i = 1; i < maxn; i++)
  {
    m1[i] = m1[i-1]*10 % M1;
    m2[i] = m2[i-1]*10 % M2;
  }

  int ka = 0;
  while(scanf("%s", str) != EOF)
  {
    ka++;
    int n = strlen(str);
    printf("Case #%d: ", ka);
      
    int r1 = 0, r2 = 0;

    for (int i = 0; i < n; i++)
    {
      r1 = (r1+ m1[n-i-1]*(str[i]-'0') )% M1;
      r2 = (r2+ m2[n-i-1]*(str[i]-'0') )% M2;
    }
    
    if (r1 == 0 || r2 == 0)
    {
      printf("YES\n");
    }
    else
      printf("NO\n");
  }



  return 0;
}
