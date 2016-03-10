#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#define maxn 1020
#define INF 0x7f7f7f7f

using namespace std;

int Wa[maxn],Wb[maxn],Wv[maxn],Ws[maxn];
int Rank[maxn], Height[maxn];



int cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b]&&r[a+l]==r[b+l];
}
void da(int *r, int *sa, int n, int m)
{
	int i, j, p, *x = Wa, *y = Wb, *t;
	for(i = 0; i < m; i++) Ws[i] = 0;
	for(i = 0; i < n; i++) Ws[x[i]=r[i]]++;
	for(i = 1; i < m; i++) Ws[i] += Ws[i-1];
	for(i = n-1; i >= 0; i--) sa[--Ws[x[i]]] = i;

	for(j = 1, p = 1; p < n; j*=2, m = p)
	{
		for(p = 0,i = n - j; i < n;i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < n; i++) Wv[i] = x[y[i]];
		for(i = 0; i < m; i++) Ws[i] = 0;
		for(i = 0; i < n; i++) Ws[Wv[i]]++;
		for(i = 1; i < m; i++) Ws[i] += Ws[i-1];
		for(i = n-1; i >= 0; i--) sa[--Ws[Wv[i]]] = y[i];
		for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
			x[sa[i]] =  cmp(y,sa[i-1], sa[i], j)? p-1:p++;
	}
	return;
}
void calheight(int *r, int *sa, int n)
{
	int i, j, k = 0;
	for(i = 1; i <= n; i++) Rank[sa[i]] = i;
	for(i = 0; i < n; Height[Rank[i++]] = k)
	for(k?k--:0,j = sa[Rank[i]-1]; r[i+k] == r[j+k];k++);
	return;
}



int main()
{






	return 0;
}