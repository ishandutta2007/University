#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>


#define ll long long
#define __maxn 120
#define INF 100000000

using namespace std;


struct pos{
	int x, y, t;
	int del[6][2];
	int len;
	pos(){}
	pos(int x, int y, int t, int len):x(x),y(y),t(t),len(len){}
};
char mp[__maxn][__maxn];
int n, m;
int mk[2];
int mx[4] = {0,0,-1,1};
int my[4] = {1,-1,0,0};
bool vis[__maxn][__maxn];
deque<pos>q, q1;


bool __check(pos p)
{
	if(p.x >= 0 && p.x < n && p.y >= 0 && p.y < n && mp[p.x][p.y] != '#' && vis[p.x][p.y] == false) return true;
	return false;
}

int bfs(char dest)
{
	q.clear();
	q1.clear();
	memset(vis, 0, sizeof(vis));
	vis[mk[0]][mk[1]] = true;
	q.push_back(pos(mk[0], mk[1], 0, 0));
	pos now, tmp;
	while(!q.empty())
	{
		now = q.front();
		q.pop_front();
		// printf("now : %d %d\n", now.x, now.y);
		if(mp[now.x][now.y] == dest)
		{
			for(int i = 1; i <= now.len; i++)
			{
				int xx = now.del[i][0], yy = now.del[i][1];
				mp[xx][yy] = '.';
			}
			mk[0] = now.x;
			mk[1] = now.y;
			return now.t;	
		}
		

		for(int i = 0; i < 4; i++)
		{
			tmp = pos(now.x + mx[i], now.y + my[i], now.t + 1, now.len);
			for(int i = 1; i <= now.len; i++)
			{
				tmp.del[i][0] = now.del[i][0];
				tmp.del[i][1] = now.del[i][1];
			}
			if(!__check(tmp)) continue;
			vis[tmp.x][tmp.y] = true;
			if(mp[tmp.x][tmp.y] == 'S')
			{
				tmp.len++;
				int tlen = tmp.len;
				tmp.del[tlen][0] = tmp.x;
				tmp.del[tlen][1] = tmp.y;
				tmp.t++;
				q1.push_back(tmp);
			}
			else
				q.push_back(tmp);
		}
		while(!q1.empty())
		{
			tmp = q1.front();
			q1.pop_front();
			q.push_back(tmp);
		}

	}

	return INF;
}



int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	while(scanf("%d%d", &n, &m))
	{
		if(n + m == 0) break;

		for(int i = 0; i < n; i++)
			scanf("%s", mp[i]);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				if(mp[i][j] == 'K')
				{
					mk[0] = i;
					mk[1] = j;
					mp[i][j] = '.';
				}
			}


		int ans = 0;
		bool hasso = true;
		for(int i = 1; i <= m; i++)
		{
			ans += bfs(i + '0');
			// printf("ans = %d\n", ans);
			if(ans >= INF)
			{
				hasso = false;
				break;
			}
		}

		if(!hasso)
		{
			printf("impossible\n");
			continue;
		}
		ans += bfs('T');
		if(ans >= INF)
		{
			printf("impossible\n");
			continue;
		}
		else
		{
			printf("%d\n", ans);
		}
	}



	#ifdef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}