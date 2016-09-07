#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 20020;

int s[maxn];
int sa[maxn], tt[maxn], tt2[maxn], c[maxn], n;
int Rank[maxn], height[maxn];
int k;
int low[maxn][33];
vector<int> h;
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
      x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k] ? p-1 : p++;
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
  int tmp = 0;
  for (int i = 0; i < n; i++)
  {
    if (height[i] >= x) tmp++;
    else tmp = 1;
    if (tmp >= k) return true;
  }
  return false;
}

int main()
{
  int N, K;
  scanf("%d%d", &N, &K);
  k = K;
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &s[i]);
    h.push_back(s[i]);
  }
  sort(h.begin(), h.end());
  for (int i = 0; i < N; i++)
    s[i] = lower_bound(h.begin(), h.end(), s[i]) - h.begin() + 1;
  s[N] = 0;
  n = N + 1;
  build_sa(n);
  getheight();

  // int ans = 0;
  // int l = 1, r = n;
  // int mid;

  // while (l <= r)
  // {
  //   mid = (l + r)/2;
  //   if (check(mid))
  //   {
  //     ans = max(ans, mid);
  //     l = mid + 1;
  //   }
  //   else r = mid - 1;
  // }
  // printf("%d\n", ans);

  
  for (int i = 0; i < n; i++)
  {
    low[i][0] = height[i];
    // printf("%d ", low[i][0]);
  }
  // printf("\n");

  
  for (int j = 1; j <= 20; j++)
    for (int i = 0; i < n; i++) if (i + (1<<j) - 1 < n)
      low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);

  int ans = 0;

  K--;
  int tk = log2(K);
  for (int i = 0; i + K - 1 < n; i++)
  {
    ans = max(ans, min(low[i][tk], low[i+K-1 - (1<<tk) + 1][tk]));
  }

  printf("%d\n", ans);
  

  return 0;
}
