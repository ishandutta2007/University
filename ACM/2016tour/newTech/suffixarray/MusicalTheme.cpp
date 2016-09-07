#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 20020;

int s[maxn], t[maxn];
int sa[maxn], tt[maxn], tt2[maxn], c[maxn], n;
int Rank[maxn], height[maxn];
// 构造字符串 s 的后缀数组。每个字符值必须是 0 ~ m-1
void build_sa(int m)
{
  int i, *x = tt, *y = tt2;
  // 基数排序
  for (i = 0; i < m; i++) c[i] = 0;
  for (i = 0; i < n; i++) c[x[i] = s[i]]++;
  for (i = 1; i < m; i++) c[i] += c[i-1];
  for (i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
  for (int k = 1; k <= n; k <<= 1)
  {
    int p = 0;
    // 直接利用 sa 数组排序第二关键字
    for (i = n-k; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i]-k;
    // 基数排序第一关键字
    for (i = 0; i < m; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[x[y[i]]]++;
    for (i = 0; i < m; i++) c[i] += c[i-1];
    for (i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
    // 根据 sa 和 y 数组计算新的 x 数组
    swap(x, y);
    p = 1; x[sa[0]] = 0;
    for (i = 1; i < n; i++)
      x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k] ? p-1:p++;
    if (p >= n) break;
    m = p;
  }
}
void getheight()
{
  int i, j, k = 0;
  for (i = 0; i < n; i++) Rank[sa[i]] = i;
  for (i = 0; i < n; i++)
  {
    if (k) k--;
    int j = sa[Rank[i]-1];
    while (s[i+k] == s[j+k]) k++;
    height[Rank[i]] = k;
  }
}
bool check(int x)
{
  int mmin = 0, mmax = 0;
  for (int i = 0; i < n; i++)
  {
    if (height[i] >= x) 
    {
      mmin = min(mmin, sa[i]);
      mmax = max(mmax, sa[i]);
    }
    else
    {
      // cout << mmax << "   " << mmin << endl;
      mmin = mmax = sa[i];
    }
    if (mmax - mmin >= x + 1) return true;
  }
  return false;
}

int main()
{
  while(scanf("%d", &n) != EOF)
  {
    if (n == 0) break;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &t[i]);
      s[i] = (i==0? 1:t[i] - t[i-1] + 89);
    }

    s[n++] = 0;

    // for (int i = 0; i < n; i++)
    //   printf("%d ", s[i]);
    // printf("\n");


    build_sa(200);
    getheight();


    // for (int i = 0; i < n; i++)
    //   printf("%d %d\n", sa[i], height[i]);


    int ans = 0;
    int l = 1, r = n;
    int mid;

    // cout << "hello" << endl;
    // cout << check(4) << endl;
    // cout << "hello" << endl;
    while (l <= r)
    {
      mid = (l + r)/2;
      if (check(mid))
      {
        ans = max(ans, mid);
        l = mid + 1;
      }
      else r = mid - 1;
    }

    if (ans < 4) printf("0\n");
    else printf("%d\n", ans + 1);
  }
  return 0;
}

