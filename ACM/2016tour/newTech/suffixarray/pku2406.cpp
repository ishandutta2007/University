// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 1000200;

char s[maxn];
int sa[maxn], tt[maxn], tt2[maxn], c[maxn], n; // n 应为长度 + 1
int Rank[maxn], height[maxn];
int low[maxn];
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



int main()
{
  // cout << sizeof(low)/1024 << endl;
  while (scanf("%s",s)!=EOF && !(s[0]=='.' && strlen(s)==1))  
  {
    n = strlen(s);
    if (n == 1 && s[0] == '.') break;
    s[n++] = 0;

    build_sa(128);
    getheight();
  /*  
    for (int i = 0; i < n; i++)
      printf("%d %d %d\n", sa[i], Rank[i], height[i]);
    
  */

    int st = Rank[0];
    low[st] = n-1;
/*
    printf("{%d}\n", st);
*/
    for (int i = st + 1; i < n; i++)
      low[i] = min(low[i-1], height[i]);
    for (int i = st - 1; i >= 0; i--)
      low[i] = min(low[i+1], height[i+1]);
/*
    for (int i = 0; i < n; i++)
      printf("%d ", low[i]);
    printf("\n");
*/

    int flag = 0;
    for (int i = 1; i <= n/2; i++)
    {
      if ((n-1)%i) continue;
      // printf("[%d]\n", i);
      int r = Rank[i];
      //cout << l << " " << r << endl;
      if (low[r] == n - 1 - i)
      {
        printf("%d\n", (n-1) / i);
        flag = 1;
        break;
      }
    }

    if (flag == 0) printf("%d\n", n-1);

  }

  return 0;
}
