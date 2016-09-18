#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;


int x1[2], y1[2], x2[2], y2[2];
int n;

int ask(int a, int b, int c, int d)
{
  printf("? %d %d %d %d\n", a, b, c, d);
  //cout << '?' << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
  fflush(stdout);
  int tmp;
  //cin >> tmp;
  scanf("%d", &tmp);
  return tmp;
}

bool in(int a, int b, int c, int d)
{
  return a <= x1[0] && b <= y1[0] && c >= x2[0] && d >= y2[0];
}

void solve(int pos)
{
  int low = 1, high = n, ret = n;
  int tmp;
  while(low <= high)
  {
    int mid = (low+high)/2;
    tmp = ask(1,1,mid,n);
    if (pos == 1 && in(1,1,mid,n)) tmp--;
    if (tmp >= 1)
    {
      ret = min(ret, mid);
      high = mid-1;
    }
    else
      low = mid+1;
  }
  x2[pos] = ret;
  low = 1, high = x2[pos], ret = 0;
  while(low <= high)
  {
    int mid = (low+high)/2;
    tmp = ask(mid,1,x2[pos],n);
    if (pos == 1 && in(mid,1,x2[pos],n)) tmp--;
    if (tmp >= 1)
    {
      ret = max(ret, mid);
      low = mid+1;
    }
    else
      high = mid-1;
  }
  x1[pos] = ret;

  low = 1, high = n, ret = n;
  while(low <= high)
  {
    int mid = (low+high)/2;
    tmp = ask(x1[pos], 1, x2[pos], mid);
    if (pos == 1 && in(x1[pos],1,x2[pos],mid)) tmp--;
    if (tmp >= 1)
    {
      ret = min(ret, mid);
      high = mid-1;
    }
    else
      low = mid+1;
  }
  y2[pos] = ret;
  low = 1, high = y2[pos], ret = 0;
  while(low <= high)
  {
    int mid = (low+high)/2;
    tmp = ask(x1[pos],mid,x2[pos],y2[pos]);
    if (pos == 1 && in(x1[pos],mid,x2[pos],y2[pos])) tmp--;
    if (tmp >= 1)
    {
      ret = max(ret, mid);
      low = mid+1;
    }
    else
      high = mid-1;
  }
  y1[pos] = ret;
}


int main()
{
  scanf("%d", &n);
  solve(0);
  solve(1);
  //cout << "!";
  //cout << ' ' << x1[0] << ' ' << y1[0] << ' ' << x2[0] << ' ' << y2[0];
  //cout << ' ' << x1[1] << ' ' << y1[1] << ' ' << x2[1] << ' ' << y2[1];
  printf("! %d %d %d %d %d %d %d %d\n", x1[0], y1[0], x2[0], y2[0]
                                       ,x1[1], y1[1], x2[1], y2[1]);
  fflush(stdout);
  return 0;
}
