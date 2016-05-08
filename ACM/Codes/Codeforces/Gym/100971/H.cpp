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
typedef long long ll;

const int maxN = 200020;
const int oo = 0x3f3f3f3f;

#define maxn 200200
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1


using namespace std;
struct SegTree{
    ll segmax[maxn<<2];
    ll lazy[maxn<<2];
    void clear()
    {
        memset(segmax, 0, sizeof(segmax));
        memset(lazy, 0, sizeof(lazy));
    }
    void pushup(int rt)
    {
        segmax[rt] = max(segmax[rt<<1], segmax[rt<<1|1]);
    }
    void pushdown(int rt, int m)
    {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        segmax[rt << 1] += lazy[rt];
        segmax[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
    void update(int L, int R, int c, int l, int r, int rt)
    {
        if(L <= l && r <= R)
        {
            lazy[rt] += c;
            segmax[rt] += c;
            return;
        }
        if(lazy[rt] != 0)
            pushdown(rt, r - l + 1);
        int m = (l + r) >> 1;
        if(L <= m) update(L, R, c, lson);
        if(R > m) update(L, R, c, rson);
        pushup(rt);
    }
    ll query(int L, int R, int l, int r, int rt){
        if(L <= l && R >= r) 
        {
            return segmax[rt];
        }
        if(lazy[rt] != 0)
            pushdown(rt, r - l + 1);
        int m = (l+r)>>1;
        ll tmp = 0;
        if(L <= m) tmp = query(L, R, lson);
        if(R > m) tmp = max(query(L, R, rson), tmp);
        return tmp;
    }
}segtree;



int n;
int ans[maxN];

int main()
{
  scanf("%d", &n);
  segtree.clear();
  memset(ans, -1, sizeof(ans));
  int a, b, tmp;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d%d", &a, &b);
    segtree.update(a, b, 1, 1, n, 1);
    // for (int i = 1; i <= n; i++)
    //   printf("%d ", (int)segtree.query(i, i, 1, n, 1));
    // printf("\n");
    tmp = segtree.query(a, b, 1, n, 1);
    // cout << tmp << endl;
    while(tmp > 0)
    {
      if(ans[tmp] == -1 && tmp >= a && tmp <= b && tmp == (int)segtree.query(tmp, tmp, 1, n, 1))
        ans[tmp] = i; 
      tmp--;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    printf("%d%c", ans[i], i == n? '\n':' ');
  }
  return 0;
}
