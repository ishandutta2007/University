#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, m, k;
char mp[1020][1020];
int tot = 0, ans[1000000];
int cnt[1020][1020];
int vis[1020][1020][4];
deque<int> deqx, deqy;
int mx[4] = {0,0,-1,1};
int my[4] = {1,-1,0,0};

bool check(int x, int y)
{
	if(x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}


void bfs(int sx, int sy)
{
	int num = 0;
	int id = ++tot;
	deqx.push_back(sx);
	deqy.push_back(sy);
	cnt[sx][sy] = id;
	int nowx, nowy, tx, ty;
	while(!deqx.empty())
	{
		nowx = deqx.front();
		nowy = deqy.front();
		deqx.pop_front();
		deqy.pop_front();
		for(int i = 0; i < 4; i++)
		{
			tx = nowx + mx[i];
			ty = nowy + my[i];
			if(!check(tx, ty)) continue;

			if(mp[tx][ty] == '.' && cnt[tx][ty] == 0)
			{
				deqx.push_back(tx);
				deqy.push_back(ty);
				cnt[tx][ty] = id;
			}

			else if(mp[tx][ty] == '*' && vis[tx][ty][i] == 0)
			{
				num ++;
				vis[tx][ty][i]=1;
			}
		}
	}
	ans[id] = num;
}


int main()
{

	scanf("%d%d%d", &n, &m, &k);

	for(int i = 0; i < n; i++)
		scanf("%s", mp[i]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)if(cnt[i][j] == 0 && mp[i][j] == '.')
		{
			bfs(i, j);
		}

	for(int i = 0; i < k; i++)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", ans[cnt[n-1][m-1]]);
	}

	return 0;
}
