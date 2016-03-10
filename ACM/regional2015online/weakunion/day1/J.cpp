#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int did[4] = {2, 3, 5, 7};
int tx[1020], ty[1020], xs[1020], ys[1020], x[1020], y[1020];
int n;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, -1, 0, 1};
map<int , vector<int> > vx, vy;
map<pair<int , int > , int> vis;

typedef pair<int , int > PII;


int main()
{

	while(scanf("%d", &n) != EOF)
	{


		vx.clear();
		vy.clear();
		vis.clear();
		x[0] = y[0] = tx[0] = xs[0] = ty[0] = ys[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &tx[i], &ty[i]);
			vx[tx[i]].push_back(ty[i]);
			vy[ty[i]].push_back(tx[i]);
		}


		for(int i = 1; i <= n; i++)
		{
			sort(vx[tx[i]].begin(), vx[tx[i]].end());
			sort(vy[ty[i]].begin(), vy[ty[i]].end());
		}


		int nowx = 0, nowy = 0, ans =0 ,dir = 0;
		int tmpx, tmpy;
		bool loop = false;
		while(true)
		{


			// cout << nowx << "  " << nowy << "  " << dir << endl;


			if(dir == 0)
			{
				if(vy.find(nowy) == vy.end())
					break;

				vector<int>& tmp = vy[nowy];
				{
					tmpy = nowy;
					tmpx = lower_bound(tmp.begin(), tmp.end(), nowx) - tmp.begin();
					if(tmpx >= tmp.size()) break;
					else
					{
						tmpx = tmp[tmpx] - 1;
						PII tmp = make_pair(tmpx, tmpy);
						if(vis.find(tmp) == vis.end())
							vis[tmp] = 1;

						if(vis[tmp] % did[dir] == 0)
						{
							loop = true;
							break;
						}
						else
						{
							vis[tmp] *= did[dir];
						}
						dir = (dir+1)%4;
						ans++;
						nowx = tmpx;
						nowy = tmpy;
					}
				}
			}

			else if(dir == 1)
			{
				if(vx.find(nowx) == vx.end())
					break;
				vector<int>& tmp = vx[nowx];
				{
					tmpx = nowx;
					tmpy = lower_bound(tmp.begin(), tmp.end(), nowy) - tmp.begin();
					if(tmpy == 0) break;
					else
					{
						tmpy = tmp[tmpy-1] + 1;
						PII tmp = make_pair(tmpx, tmpy);
						if(vis.find(tmp) == vis.end())
							vis[tmp] = 1;

						if(vis[tmp] % did[dir] == 0)
						{
							loop = true;
							break;
						}
						else
						{
							vis[tmp] *= did[dir];
						}
						dir = (dir+1)%4;
						ans++;
						nowx = tmpx;
						nowy = tmpy;
					}
				}
			}
			else if(dir == 2)
			{
				if(vy.find(nowy) == vy.end())
					break;
				vector<int>& tmp = vy[nowy];
				{
					tmpy = nowy;
					tmpx = lower_bound(tmp.begin(), tmp.end(), nowx) - tmp.begin();
					if(tmpx == 0) break;
					else
					{
						tmpx = tmp[tmpx-1] + 1;
						PII tmp = make_pair(tmpx, tmpy);
						if(vis.find(tmp) == vis.end())
							vis[tmp] = 1;

						if(vis[tmp] % did[dir] == 0)
						{
							loop = true;
							break;
						}
						else
						{
							vis[tmp] *= did[dir];
						}
						dir = (dir+1)%4;
						ans++;
						nowx = tmpx;
						nowy = tmpy;
					}
				}
			}
			else if(dir == 3)
			{
				if(vx.find(nowx) == vx.end())
					break;

				vector<int>& tmp = vx[nowx];
				{
					tmpx = nowx;
					tmpy = lower_bound(tmp.begin(), tmp.end(), nowy) - tmp.begin();
					if(tmpy >= tmp.size()) break;
					else
					{
						tmpy = tmp[tmpy] - 1;
						PII tmp = make_pair(tmpx, tmpy);
						if(vis.find(tmp) == vis.end())
							vis[tmp] = 1;

						if(vis[tmp] % did[dir] == 0)
						{
							loop = true;
							break;
						}
						else
						{
							vis[tmp] *= did[dir];
						}
						dir = (dir+1)%4;
						ans++;
						nowx = tmpx;
						nowy = tmpy;
					}
				}
			}
		}



	if(loop)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", ans);
	}

	}
	return 0;
}