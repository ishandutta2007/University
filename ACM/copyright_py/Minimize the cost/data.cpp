#include <bits/stdc++.h>
using namespace std;

int n = 1000;
int s = 10001;

int main()
{
    freopen("datatmp.txt", "w", stdout);


    // printf("90\n");

    for (int i = 0; i < 45; i++)
    {
      printf("%d %d\n", 10000, 700);

      for (int j = 0; j < 700; j++)
      {
        int l = rand() % s, r = rand() % s;
        if(l > r) swap(l, r);
        if(l <= 9) l = 0;
        if(r >= 9990) r = 10000;
        printf("%d %d\n", l, r);
      }
    }

    return 0;
}