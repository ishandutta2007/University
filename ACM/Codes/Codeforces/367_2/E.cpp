#include <bits/stdc++.h>
#define X first
#define Y second
#define left leftz
#define right rightz

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1020;
const pii nul = pii(-1,-1);

pii right[maxn][maxn], down[maxn][maxn];
int data[maxn][maxn];
int n, m;
int a, b, c, d, h, w;

void init()
{
  for (int x = 0; x <= n+1; x++)
    for (int y = 0; y <= m+1; y++)
    {
      if (y == m+1) right[x][y] = nul;
      else right[x][y] = pii(x, y+1);
      if (x == n+1) down[x][y] = nul;
      else down[x][y] = pii(x+1, y);
    }
}
void output_line(int x)
{
  pii tmp;
  tmp = right[x][0];
  while(right[tmp.X][tmp.Y] != nul)
  {
    printf("%d ", data[tmp.X][tmp.Y]);
    tmp = right[tmp.X][tmp.Y];
  }
  printf("\n");
}

pii findpos(int x, int y)
{
  pii tmp = pii(0,0);
  for (int i = 0; i < y; i++)
    tmp = right[tmp.X][tmp.Y];
  for (int i = 0; i < x; i++)
    tmp = down[tmp.X][tmp.Y];
  return tmp;
}

void change()
{
  pii pos1, pos2, tp1, tp2;
  tp1 = pos1 = findpos(a-1,b-1);
  tp2 = pos2 = findpos(c-1,d-1);

  for (int i = 0; i < w; i++)
  {
    tp1 = right[tp1.X][tp1.Y];
    tp2 = right[tp2.X][tp2.Y];
    swap(down[tp1.X][tp1.Y], down[tp2.X][tp2.Y]);
  }
  
  for (int i = 0; i < h; i++)
  {
    tp1 = down[tp1.X][tp1.Y];
    tp2 = down[tp2.X][tp2.Y];
    swap(right[tp1.X][tp1.Y], right[tp2.X][tp2.Y]);
  }
  tp1 = pos1;tp2 = pos2;
  for (int i = 0; i < h; i++)
  {
    tp1 = down[tp1.X][tp1.Y];
    tp2 = down[tp2.X][tp2.Y];
    swap(right[tp1.X][tp1.Y], right[tp2.X][tp2.Y]);
  }
  for (int i = 0; i < w; i++)
  {
    tp1 = right[tp1.X][tp1.Y];
    tp2 = right[tp2.X][tp2.Y];
    swap(down[tp1.X][tp1.Y], down[tp2.X][tp2.Y]);
  }
}
int main()
{
  int Q;
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &data[i][j]);
  init();
  while(Q--)
  {
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &h, &w);
    change();
  }
  for (int i = 1; i <= n; i++)
    output_line(i);
  return 0;
}
