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

const int maxh = 10000;
const int maxn = 10002;


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
    printf("n = %d\n", n);
    while(pos < MAXN){
      c[pos] += delta;
      pos += lowbit(pos);
    }
  }
  int getsum(int pos){
    int ans = 0;
    while(pos > 0){
      ans += c[pos];
      pos -= lowbit(pos);
    }
    return ans;
  }
}bit;

struct seg
{
  int l, r;
  seg(){}
  seg(int x, int y, int z)
  {
    int dh = maxh - z;
    l = x - dh;
    r = y + dh;
  }
};

struct Node
{
  int l, cnt;
  Node(){}
  Node(int l, int cnt):l(l), cnt(cnt){}
}
bool operator < (Node a, Node b)
{
  return a.cnt < b.cnt;
}

bool leftcmp(seg a, seg b)
{
  if (a.l == b.l) return a.r > b.r;
  return a.l < b.l;
}


seg toleft[maxn], toright[maxn];
int ltot, rtot;
int n;
int toleftcnt[maxn], torighcnt[maxn];


priority_queue< Node > pq;



int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d", &n);
    int x, y, z, d;
    ltot = rtot = 0;
    for (int i = 1; i <= n; i++)
    {
      scanf("%d%d%d%d", &x, &y, &z, &d);
      if (d == -1)
      {
        toleft[ltot++] = seg(x + 2000000, y + 2000000, z);
      }
      else
      {
        toright[rtot++] = seg(x + 2000000, y + 2000000, z);
      }
    }
    
    sort(toleft, toleft + ltot, leftcmp);
    sort(toright, toright + rtot, leftcmp);

    int ans = 0;
    bit.clear();
    for (int i = 0; i < ltot; i++)
      bit.add(toleft[i].r, 1);
    for (int i = 0; i < ltot; i++)
    {
      toleftcnt[i] = bit.query(toleft[i].l + 2*2000000);
      ans = max(ans, toleftcnt[i]);
      bit.add(toleft[i].r, -1);
    }

    bit.clear();
    while(!pq.empty()) pq.pop();
    for (int i = 0; i < rtot; i++)
      bit.add(toright[i].r, 1);
    for (int i = 0; i < rtot; i++)
    {
      torightcnt[i] = bit.query(toright[i].l + 2*2000000);
      ans = max(ans, torightcnt[i]);
      pq.push(Node(toright[i].l, torightcnt[i]));
      bit.add(toright[i].r, -1);
    }
    Node now = pq.top();
    pq.pop();
    for (int i = 0; i < n; i++)
    {
      while(toleft[i].l < now.l)
      {
        now = pq.top();
        pq.pop();
      }
      ans = max(ans, toleftcnt[i] + now.cnt);
    }
    printf("%d\n", ans);
  }
  return 0;
}

