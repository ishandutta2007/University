#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct Edge
{
	int u, v, c;
	Edge(){}
	Edge(int u, int v, int c):u(u),v(v),c(c){}
	bool operator < (const Edge &e) const {
		return c < e.c;
	}
};
vector<Edge> ve;
int n, m;
int R[100200];
// int root(int x)
// {
// 	while(R[x] != x)
// 		x = R[x] = R[R[x]];
// 	return R[x];
// }
int root(int x)
{
	if(R[x] == -1) return x;
	if(R[x] != -1) R[x] = root(R[x]);
	return R[x];
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ve.clear();
		scanf("%d%d", &n, &m);
		int tot = n*m;
		int tmp;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &tmp);
				if(i == 0)
					ve.push_back(Edge(tot, i*m+j, tmp));
				else
					ve.push_back(Edge(i*m+j, i*m+j-m, tmp));
			}

		for (int i = 0; i < m; i++)
		{
			scanf("%d", &tmp);
			ve.push_back(Edge(tot, n*m-m+i, tmp));
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &tmp);
				if(j == 0)
					ve.push_back(Edge(tot, i*m+j, tmp));
				else
					ve.push_back(Edge(i*m+j, i*m+j-1, tmp));
			}
			scanf("%d", &tmp);
			ve.push_back(Edge(i*m+m-1, tot, tmp));
		}
		// for (int i = 1; i <= n; i++)
			// R[i] = i;
		memset(R, -1, sizeof(R));
		sort(ve.begin(), ve.end());
		int ans = 0;
		int Ru, Rv;
		for (int i = 0, len = ve.size(); i < len; i++)
		{
			Edge &now = ve[i];
			Ru = root(now.u);
			Rv = root(now.v);
			if(Ru != Rv)
			{
				ans += now.c;
				R[Ru] = Rv;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}