#include <bits/stdc++.h>

using namespace std;

char bf[10];


int main()
{
  int n, m;
  scanf("%d%d", &n, &m);


  int ok = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      scanf("%s", bf);
      if (bf[0] != 'B' && bf[0] != 'W' && bf[0] != 'G')
        ok = false;
    }
  printf("%s\n", ok? "#Black&White" : "#Color");
  
  return 0;
}
