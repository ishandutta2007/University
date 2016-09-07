#include <bits/stdc++.h>
#define first X
#define second Y


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;

struct Node
{
  int id, m, cnt;
  Node(){}
  Node(int id, int m):id(id), m(m){}
  void show()
  {
    printf("%d %.02f\n", id, m*1.0/100);
  }
}p[10020];

bool operator < (Node &a, Node &b)
{
  if (a.m != b.m) return a.m > b.m;
  if (a.cnt != b.cnt) return a.cnt > b.cnt;
  return a.id < b.id;
}


int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    p[i].id = i,p[i].m = 0, p[i].cnt = 0;
  
  int id, x, k;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &k);
    for (int j = 0; j < k; j++)
    {
      scanf("%d%d", &id, &x);
      p[i].m -= x;
      p[id].m += x;
      p[id].cnt++;
    }
  }

  sort(p + 1, p + n + 1);
  
  for (int i = 1; i <= n; i++)
    p[i].show();


  return 0;
}
