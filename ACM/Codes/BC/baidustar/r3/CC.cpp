#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 10020;
const int maxh = 10000;
const int M = 2000000;

pii toleft[maxn], toright[maxn];
pii rians[maxn];

#define MAXN 6000000
struct BIT{
  int c[MAXN];
  int n;
  void clear(int n){
    memset(c, 0, sizeof(c));
    this->n = n;
  }
  inline int lowbit(int x){
    return x & (-x);
  }
  void add(int pos, int delta){
    while(pos < MAXN){
      c[pos] += delta;
      pos += lowbit(pos);
    }
  }
  int query(int pos){
    int ans = 0;
    while(pos > 0){
      ans += c[pos];
      pos -= lowbit(pos);
    }
    return ans;
  }
}bit;


int cntleft[maxn];
int ltot, rtot, n, ans;


pii getseg(int x, int y, int z)
{
  int dh = maxh - z;
  return pii(x - dh, y + dh);
}

bool scmp(const pii &a, const pii &b)
{
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
bool anscmp(const pii &a, const pii &b)
{
  return a.second > b.second;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    ltot = rtot = ans = 0;
    scanf("%d", &n);
    int x, y, z, d;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d%d", &x, &y, &z, &d);
      if (d == -1)
        toleft[ltot++] = getseg(x + M, y + M, z);
      else
        toright[rtot++] = getseg(x + M, y + M, z);
    }
    
    sort(toleft, toleft + ltot, scmp);
    sort(toright, toright + rtot, scmp);
    memset(cntleft, 0, sizeof(cntleft));
    
    bit.clear(MAXN - 1);
    for (int i = 0; i < ltot; i++)
      bit.add(toleft[i].second, 1);
    for (int i = 0; i < ltot; i++)
    {
      cntleft[i] = bit.query(toleft[i].first + 2*maxh);
      ans = max(ans, cntleft[i]); 
      bit.add(toleft[i].second, -1);
    }

    bit.clear(MAXN - 1);
    for (int i = 0; i < rtot; i++)
      bit.add(toright[i].second, 1);
    for (int i = 0; i < rtot; i++)
    {
      rians[i].second = bit.query(toright[i].first + 2*maxh);
      rians[i].first = toright[i].first;
      ans = max(ans, rians[i].second);
      bit.add(toright[i].second, -1);
    }
    /*
    printf("to left:\n");
    for (int i = 0; i < ltot; i++)
      printf("%d %d\n", toleft[i].first, cntleft[i]);
    printf("to right:\n");
    for (int i = 0; i < rtot; i++)
      printf("%d %d\n", toright[i].first, rians[i].second);
    */

    sort(rians, rians + rtot, anscmp);
    /*
    for (int i = 0; i < rtot; i++)
      printf("[%d %d]\n", rians[i].first, rians[i].second);
      */
    int pos = 0;
    for (int i = ltot - 1; i >= 0; i--)
    {
      while(pos < rtot && toleft[i].first < rians[pos].first) pos++;
      if (pos >= rtot) break;
      ans = max(ans, cntleft[i] + rians[pos].second);
    }
    printf("Case #%d:\n%d\n", ka, ans);
  }
  return 0;
}

