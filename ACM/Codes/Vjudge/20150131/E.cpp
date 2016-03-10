#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>

using namespace std;

int n,m;
char map[120][120];
int mx[8] = {1,-1,0,0,1,1,-1,-1};
int my[8] = {0,0,-1,1,1,-1,1,-1};

queue<int> qx,qy;

bool check(int x, int y){
	if(x >= 0 && x < n && y >=0 && y < m && map[x][y] == '@')
		return true;
	return false;
}


void BFS(int sx,int sy){
	qx.push(sx);
	qy.push(sy);
	map[sx][sy] = '*';
	int nowx,nowy;
	int tmpx,tmpy;
	
	while(!qx.empty())
	{
		nowx = qx.front();
		nowy = qy.front();
		
		
		
		qx.pop();
		qy.pop();
		
		
		for(int i = 0; i < 8; i++)
		{
			tmpx = nowx + mx[i];
			tmpy = nowy + my[i];
			if(check(tmpx, tmpy))
			{
				qx.push(tmpx);
				qy.push(tmpy);
				map[tmpx][tmpy] = '*';
			}
		}
		
	}
}



int main(){
	
	while(scanf("%d%d",&n,&m) == 2){
		if(n ==0 && m == 0)
			break;
		memset(map,0,sizeof(map));
		
		getchar();
		
		int ans = 0;
		for(int i = 0; i < n; i++)
			scanf("%s",&map[i]);
		
//		for(int i = 0; i < n; i++)
//			printf("%s\n",map[i]);
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(map[i][j] == '@'){
					BFS(i, j);
					ans ++;
				}
		
		printf("%d\n",ans);
	}

	return 0;
}

