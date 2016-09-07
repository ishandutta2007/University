#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define inf 999999999
#define mo 1000000007
#define LL long long 
using namespace std;
queue <int> qx,qy;
int rx[10]={0,0,0,1,-1};
int ry[10]={0,1,-1,0,0};
char c[20][20];
int run[20][20];
int r=0;
bool Bfs(int x,int y)
{
  bool flag = true;
	int _x,_y;
	while (!qx.empty()) 
	{
		qx.pop();
		qy.pop();
	}
	qx.push(x);
	qy.push(y);
	while(!qx.empty())
	{
		x=qx.front();y=qy.front();
		run[x][y]=1;
		qx.pop();qy.pop();
		for (int i=1;i<=4;i++)
		{
			_x=x+rx[i];_y=y+ry[i];
			if (_x<0 || _x>=9 || _y<0 || _y>=9) continue;
			if (c[_x][_y]=='.') flag = false;
			if (c[_x][_y]=='o' && run[_x][_y] == 0) 
			{
        run[_x][_y] = 1;
				qx.push(_x);qy.push(_y);
			}
		}
	}
	return flag;
}
bool Find()
{
	bool flag=1;
  memset(run, 0, sizeof(run));
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			if (c[i][j]=='o' && run[i][j] == 0) flag=Bfs(i,j);
			if (flag==1) return 1;
		}
	}
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif
	int t;
	bool flag;
	scanf("%d",&t);
	for (int ca=1;ca<=t;ca++)
	{
		for (int i=0;i<9;i++)
		{
			scanf("%s",c[i]);
		}
		flag=0;
		for (int i=0;i<9;i++)
		{
			for (int j=0;j<9;j++)
			{
				if (c[i][j]=='.')
				{
					c[i][j]='x';
					flag=Find();
					c[i][j]='.';
				}
				if (flag) break;
			}
			if (flag) break;
		}
		printf("Case #%d: ",ca);
		if (flag) printf("Can kill in one move!!!\n");
		else printf("Can not kill in one move!!!\n");
	}	
}
