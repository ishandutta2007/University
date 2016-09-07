#include <bits/stdc++.h>
using namespace std;

int a[20] = {2,4,3,9,5,25,7,49,11,13,17,19,23,29,31,37,41,43,47,53};


int main()
{
  int pos = 0;
  string cmd;
  int cnt = 0;
  while(pos < 20)
  {
    printf("%d\n", a[pos++]);
    fflush(stdout);
    cin >> cmd;
    if (cmd == "yes")
    {
      cnt++;
    }
  }
  if (cnt <= 1)printf("prime\n");
  else printf("composite\n");
  fflush(stdout);
  return 0;
}
