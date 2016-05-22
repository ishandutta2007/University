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
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxN = 2000000;
const int oo = 0x3f3f3f3f;


int a[maxN + 20];
deque<int> vi;
int n, p;

int main()
{
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
    if(a[i] == i) vi.push_back(i);
    else p = i;
  }


  if(vi.size() % 2 == 0)
  {
    printf("%d\n", vi.size() / 2);
    for (int i = 0, len = vi.size()/2; i < len ;i++)
    {
      printf("%d %d\n", vi[i*2], vi[i*2+1]);
    }
  }
  else
  {
    if(vi.size() == 1)
    {
      printf("1\n");
      printf("%d %d\n", vi[0], p);
      return 0;
    }


    printf("%d\n", (vi.size() + 1) / 2);
    while(vi.size() > 3)
    {
      printf("%d %d\n", vi[0], vi[1]);
      vi.pop_front();
      vi.pop_front();
    }
    printf("%d %d\n",vi[0], vi[1]);
    printf("%d %d\n",vi[0], vi[2]);
  }
  return 0;
}