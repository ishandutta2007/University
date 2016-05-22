#include <bits/stdc++.h>
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
int R[10020];
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
	scanf("%d%d", &n, &m);
	int u, v, c;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u,&n,&c);
		ve.push_back(Edge(u,n,c));
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
	return 0;
}
