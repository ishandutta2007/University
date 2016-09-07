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

#define X first
#define Y second

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxN = 1000020;
const int oo = 0x3f3f3f3f;

int main()
{
  
  int n;
  scanf("%d", &n);
  if (n == 1 || n == 2) printf("0\n");
  else if (n == 3 || n == 4) printf("1\n");
  else if (n == 5) printf("2\n");

  else printf("%d\n", (n-1) / 2);

  return 0;
}
