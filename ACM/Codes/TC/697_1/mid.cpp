#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200002;

int tot, m;
struct Trie {
  int lc,rc,size;
}trie[maxn*30];
ll cnt[maxn], pow2[maxn];

vector<int> a;

void insert(int x)
{
  int cur = 1;
  for (int i=m-1;i>=0;i--)
  {
    int d = (x>>i)&1;
    if (d == 0)
    {
      if (!trie[cur].lc)
        trie[cur].lc = ++tot;
      cur = trie[cur].lc;
    }
    else
    {
      if (!trie[cur].rc)
        trie[cur].rc = ++tot;
      cur = trie[cur].rc;
    }
  }
}
void getcnt(int x)
{
  int cur = 1;
  for (int i = m-1;i>=0;i--)
  {
    int d=(x>>i)&1;
    if (d==0)
    {
      if (trie[cur].rc)
        cnt[i] = trie[trie[cur].rc].size;
      cur = trie[cur].lc;
    }
    else
    {
      if (trie[cur].lc)
        cnt[i] = trie[trie[cur].lc].size;
      cur = trie[cur].rc;
    }
  }
}


void calsize(int now)
{
  Trie &nd = trie[now];
  if (!nd.lc && !nd.rc)
  {
    nd.size = 1;
    return;
  }
  if (nd.lc)
  {
    calsize(nd.lc);
    nd.size += trie[nd.lc].size;
  }
  if (nd.rc)
  {
    calsize(nd.rc);
    nd.size += trie[nd.rc].size;
  }
  
  //printf("%d : %d\n", now, trie[now].size);
}

ll solve(int x)
{
  memset(cnt, 0, sizeof(cnt));
  getcnt(x);
  /*
  for (int i = 0; i < m; i++)
  {
  	printf("cnt[%d] = %lld\n", i, cnt[i]);
  }
  */
  ll ret = 0;
  for (int i = 0; i < m; i++)
  {
    ret += cnt[i]*cnt[i]*pow2[m-1];
    for (int j = 0; j < m; j++) if (i!=j)
      ret += cnt[i]*cnt[j]*pow2[m-2];
  }
  return ret;
}


class XorOrderDiv2 {
public:
  int getExpectation(int tm, int tn, int a0, int b)
  {
    pow2[0] = 1;
    for(int i = 1; i <= tm; i++)
      pow2[i] = pow2[i-1]*2;

    int n = tn;
    for (int i = 0; i < n; i++)
      a.push_back(a0 + (ll)i*b);

    tot = 1;
    m = tm;
    for (int i = 0; i < n; i++)
      insert(a[i]);
    calsize(1);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      ll tmp = solve(a[i]);
      ans ^= tmp;
      cout << tmp << " ";
    }
    return (int)ans;
  }
};
