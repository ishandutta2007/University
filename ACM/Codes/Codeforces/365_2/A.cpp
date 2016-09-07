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
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1000020;
const int oo = 1e9+7;

int main()
{
  int n;
  scanf("%d", &n);
  int a, b;
  int ta = 0, tb = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &a, &b);
    if (a > b) ta++;
    if (a < b) tb++;
  }
  
  if (ta == tb) printf("Friendship is magic!^^\n");
  if (ta > tb) printf("Mishka\n");
  if (ta < tb) printf("Chris\n");

  return 0;
}
