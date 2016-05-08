#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxN = 1000020;
const int oo = 0x3f3f3f3f;

int main()
{
  int T;
  scanf("%d", &T);
  int a, b;
  while(T--)
  {
    scanf("%d%d", &a, &b);
    printf("%s\n", a == b? "Square" : "Rectangle");
  }

  return 0;
}