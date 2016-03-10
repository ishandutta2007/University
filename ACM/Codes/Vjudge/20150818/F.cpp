#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string.h>

#define ll long long
#define maxn 2020
// #define OJ
using namespace std;

int G[maxn][maxn], layer[maxn];
int m, n;
bool vis[maxn];
char pos[40][40];
char mp[40][40];
int cnt;

bool countLayer()
{
	queue<int>q;
	memset(layer, 0xff, sizeof(layer));
	layer[1] = 0;q.push(1);

	while(!q.empty())
	{
		int v = q.front();q.pop();
		for(int j = 1; j <= n; j++)
			if(G[v][j] > 0 && layer[j] == -1)
			{
				layer[j] = layer[v] + 1;
				if(j == n) return true;
				else q.push(j);
			}
	}
	return false;
}


int Dinic()
{
	int i;
	int maxflow = 0;
	deque<int> q;
	while(countLayer())
	{
		q.push_back(1);
		memset(vis, 0, sizeof(vis));
		vis[1] = true;

		while(!q.empty())
		{
			int nd = q.back();
			if(nd == n)
			{
				int minc = 1000000000;
				int minstart;
				for(i = 1; i < q.size();i++)
				{
					int vs = q[i-1];
					int ve = q[i];
					if(G[vs][ve] > 0 && minc > G[vs][ve])
					{
						minc = G[vs][ve];
						minstart = vs;
					}
				}
				maxflow += minc;
				for(i = 1; i < q.size(); i++)
				{
					int vs = q[i-1];
					int ve = q[i];
					G[vs][ve] -= minc;
					G[ve][vs] += minc;
				}
				while(!q.empty() && q.back() != minstart)
				{
					vis[q.back()] = false;
					q.pop_back();
				}
			}else{
				for(i = 1; i <= n; i++)
					if(G[nd][i] > 0 && layer[i] == layer[nd] + 1 && !vis[i])
					{
						vis[i] = true;
						q.push_back(i);
						break;
					}	
				if(i > n) q.pop_back();
			}
		}

	}

	return maxflow;
}


int main()
{

	#ifndef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif


	int r, c, d, num;
	scanf("%d%d%d", &r, &c, &d);
	n = 2 + r * c * 2;
	num = r*c;
	for(int i = 0; i < r; i++)
		scanf("%s", mp[i]);
	for(int i = 0; i < r; i++)
		scanf("%s", pos[i]);




	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if(mp[i][j] > '0')
			{
				// printf("%d %d %c\n", i, j, mp[i][j]);
				G[2 + i*c + j][2 + i*c + j + num] = mp[i][j] - '0';
				// printf("add age : %d %d = %d\n", 2 + i*c + j, 2 + i*c+j + num, mp[i][j] - '0');
				if(i - d < 0 || i + d >= r || j - d < 0 || j + d >= c)
				{
					G[2 + i*c + j + num][n] = 1000000000;
					// printf("add age : %d %d = %d\n", 2 + i*c+j + num, n, 1000000000);
				}
			}
			if(pos[i][j] == 'L')
			{
				cnt++;
				G[1][2 + i*c + j] = 1;
				// printf("add age : %d %d = %d\n", 1, 2 + i*c+j, 1);
			}
		}

	}

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)if(mp[i][j] > '0')
		{
			for(int ii = 0; ii < r; ii++)
			{
				for(int jj = 0; jj < c; jj++)if(mp[ii][jj] > '0' && (!(i == ii && j == jj)) && (abs(i - ii) + abs(j - jj) <= d))
				{
					G[2 + i*c + j + num][2 + ii*c + jj] = 1000000000;
					// printf("add age : %d %d = %d\n", 2 + i*c+j + num, 2 + ii*c+jj, 1000000000);
				}
			}
		}
	}

	



	// printf("%d\n", cnt);
	// printf("%d\n", Dinic());
	printf("%d\n", cnt - Dinic());

	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	system("pause");
	return 0;
}