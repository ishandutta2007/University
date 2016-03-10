#include <cstdio>
#include <cstring>
#include <map>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int depth[400000];
int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
int start[10], end[10];
deque<int> deq;
int mx[4] = {0, 0, -1, 1};
int my[4] = {-1, 1, 0, 0};
int vis[400000];


int cantor(int* a,int len)
{
	int ret = 0;
	for(int i = 0; i < len; i++)
	{
		int tmp = 0;
		for(int j = i+1; j < len; j++)
			if(a[i] > a[j])
				tmp++;
		ret += tmp * fact[len-i-1];

	}
	return ret;
}

int cantorrev(int* a,int d, int len)
{
	bool vis[10] = {0};
	int tmp, tt;
	for(int i = 0; i < len; i++)
	{
		tmp = d / fact[len-i-1];
		d %= fact[len-i-1];
		tt = 1;
		while(tmp || vis[tt])
		{
			if(vis[tt] == false)
				tmp--;
			tt++;
		}
		vis[tt] = true;
		a[i] = tt;
	}
	int i;
	for(i = 0; i < len; i++)
		if(a[i] == 9) break;
	return i;
}


int bfs(int now,int dest)
{
	int ay[10];
	memset(depth, -1, sizeof(depth));
	memset(vis, -1, sizeof(vis));
	deq.clear();
	int pos, line, cow;
	int tpos, tl, tc;
	int nex;
	depth[now] = 0;
	vis[now] = 0;
	deq.push_back(now);

	depth[dest] = 0;
	vis[dest] = 1;
	deq.push_back(dest);


	while(!deq.empty())
	{
		now = deq.front();

		if(now == dest && vis[now] == 0) return depth[now];

		deq.pop_front();
		pos = cantorrev(ay, now, 9);
		line = pos/3;
		cow = pos%3;


		for(int i = 0; i < 4; i++)
		{
			tl = line + mx[i];
			tc = cow + my[i];

			if(tl >=0 && tl < 3 && tc >= 0 && tc < 3)
			{
				tpos = tl * 3 + tc;
				swap(ay[pos], ay[tpos]);
				nex = cantor(ay, 9);
				if(depth[nex] == -1)
				{
					depth[nex] = depth[now] + 1;
					vis[nex] = vis[now];
					deq.push_back(nex);
				}

				else if((vis[nex]^1) == vis[now])
				{
					return depth[nex] + depth[now] + 1;
				}


				swap(ay[pos], ay[tpos]);
			}
		}

	}



	return -1;
}


int rev(int *a)
{
	int ret = 0;

	for(int i = 0; i < 9; i++)
	{
		if(a[i] == 9) continue;

		for(int j = 0; j < i; j++)
			if(a[j] > a[i] && a[j] != 9) ret++;

	}
	return ret;
}



int main()
{
	// freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	while(T--)
	{
		for(int i = 0; i < 9; i++)
		{
			scanf("%d", &start[i]);
			if(start[i] == 0)
				start[i] = 9;
		}
		for(int i = 0; i < 9; i++)
		{
			scanf("%d", &end[i]);
			if(end[i] == 0)
				end[i] = 9;
		}


		if((rev(start) + rev(end))%2 != 0)
		{
			printf("-1\n");
			continue;
		}




		int from = cantor(start, 9);
		int dest = cantor(end, 9);

		if(from == dest)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n", bfs(from, dest));


	}
	return 0;
}