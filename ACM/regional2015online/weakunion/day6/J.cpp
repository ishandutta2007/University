#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;



char mp[1020][1020];
int n, m;
int dp[1020][1020];



int calline1()
{
	int ret = 0;

	int L = 0, R = m;
	int l, r, nowl, nowr;
	while(mp[0][L] != '#') L++;
	while(mp[0][R] != '#') R--;
	l = L, r = R;

	for(int i = 1; i < n; i++)
	{

		// cout << L << ' ' << l << ' ' << r << ' ' << R << endl;

		nowl = 0, nowr = m;
		while(mp[i][nowl] != '#') nowl++;
		while(mp[i][nowr] != '#') nowr--;

		if(nowl >= l && nowr <= r)
		{
			L = l = nowl;
			R = r = nowr;
		}

		else if(nowl > r)
		{
			ret += 2;
			r = R;
			l = nowl;
			R = nowr;
			L = nowl;
		}
		else if(nowr < l)
		{
			ret += 2;
			l = L;
			r = nowr;
			R = nowr;
			L = nowl;
		}
		else
		{
			ret ++;
			r = min(R, nowr);
			l = max(L, nowl);
			L = nowl;
			R = nowr;
		}
	}
	cout << "ret = " << ret << endl;
	return ret;
}




int calline2()
{
	int ret = 0;

	int L = 0, R = m;
	int l, r, nowl, nowr;
	while(mp[n-1][L] != '#') L++;
	while(mp[n-1][R] != '#') R--;
	l = L, r = R;

	for(int i = n-2; i >= 0; i--)
	{

		cout << L << ' ' << l << ' ' << r << ' ' << R << ' ' << ret << endl;

		nowl = 0, nowr = m;
		while(mp[i][nowl] != '#') nowl++;
		while(mp[i][nowr] != '#') nowr--;

		if(nowl >= l && nowr <= r)
		{
			L = l = nowl;
			R = r = nowr;
		}

		else if(nowl > r)
		{
			ret += 2;
			r = R;
			l = nowl;
			R = nowr;
			L = nowl;
		}
		else if(nowr < l)
		{
			ret += 2;
			l = L;
			r = nowr;
			R = nowr;
			L = nowl;
		}
		else
		{
			ret ++;
			r = min(R, nowr);
			l = max(L, nowl);
			L = nowl;
			R = nowr;
		}
	}
	cout << "ret = " << ret << endl;
	return ret;
}
int calcow1()
{
	int ret = 0;

	int L = 0, R = n;
	int l, r, nowl, nowr;
	while(mp[L][0] != '#') L++;
	while(mp[R][0] != '#') R--;
	l = L, r = R;

	for(int i = 1; i < m; i++)
	{

		// cout << L << ' ' << l << ' ' << r << ' ' << R << endl;

		nowl = 0, nowr = m;
		while(mp[nowl][i] != '#') nowl++;
		while(mp[nowr][i] != '#') nowr--;

		if(nowl >= l && nowr <= r)
		{
			L = l = nowl;
			R = r = nowr;
		}

		else if(nowl > r)
		{
			ret += 2;
			r = R;
			l = nowl;
			R = nowr;
			L = nowl;
		}
		else if(nowr < l)
		{
			ret += 2;
			l = L;
			r = nowr;
			R = nowr;
			L = nowl;
		}
		else
		{
			ret ++;
			r = min(R, nowr);
			l = max(L, nowl);
			L = nowl;
			R = nowr;
		}
	}
	cout << "ret = " << ret << endl;
	return ret;
}

int calcow2()
{
	int ret = 0;

	int L = 0, R = n;
	int l, r, nowl, nowr;
	while(mp[L][m-1] != '#') L++;
	while(mp[R][m-1] != '#') R--;
	l = L, r = R;

	for(int i = m-2; i >= 0; i--)
	{

		// cout << L << ' ' << l << ' ' << r << ' ' << R << endl;

		nowl = 0, nowr = m;
		while(mp[nowl][i] != '#') nowl++;
		while(mp[nowr][i] != '#') nowr--;

		if(nowl >= l && nowr <= r)
		{
			L = l = nowl;
			R = r = nowr;
		}

		else if(nowl > r)
		{
			ret += 2;
			r = R;
			l = nowl;
			R = nowr;
			L = nowl;
		}
		else if(nowr < l)
		{
			ret += 2;
			l = L;
			r = nowr;
			R = nowr;
			L = nowl;
		}
		else
		{
			ret ++;
			r = min(R, nowr);
			l = max(L, nowl);
			L = nowl;
			R = nowr;
		}
	}
	cout << "ret = " << ret << endl;
	return ret;
}
// int calcow()
// {
// 	int ret = 0;
// 	return ret;
// }



int main()
{


	freopen("jinxiety.in", "r", stdin);
	// freopen("jinxiety.out", "w", stdout);

	while(scanf("%d%d",&n,&m) != EOF)
	{

		if(n == 0 && m == 0) break;

		memset(mp, 0, sizeof(mp));

		for(int i = 0; i < n; i++)
			scanf("%s", mp[i]);



		int tmp1 = min(calline1(), calline2());
		int tmp2 = min(calcow1(), calcow2());



		printf("%d\n", max(tmp1, tmp2));
	}
	return 0;
}