#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>

using namespace std;

int n,m;
char map[300][300];
int mx[4] = {1,-1,0,0};
int my[4] = {0,0,-1,1};

int flag[300][300];

queue<int> qx,qy,qt;

bool check(int x, int y){
	if(x >= 0 && x < n && y >=0 && y < m && map[x][y] != '#' && flag[x][y] == 0)
		return true;
	return false;
}


int BFS(int sx,int sy){
	int ans = INT_MAX;
	int nowx,nowy,nowt;
	int tmpx,tmpy,tmpt;
	
	memset(flag,0,sizeof(flag));
	
	qx.push(sx);
	qy.push(sy);
	qt.push(0);
	
	flag[sx][sy] = 1;
	
	while(!qx.empty())
	{
		nowx = qx.front();
		nowy = qy.front();
		nowt = qt.front();
		
		
		qx.pop();
		qy.pop();
		qt.pop();
		
		for(int i = 0; i < 4; i++)
		{
			tmpx = nowx + mx[i];
			tmpy = nowy + my[i];
			tmpt = nowt + 1;
			if(check(tmpx, tmpy))
			{
				int tt = 0;
				if(map[tmpx][tmpy] == 'a')
					ans = min(ans,tmpt);
				else
				{
					if(map[tmpx][tmpy] == 'x')
						tt = 1;
					
					flag[tmpx][tmpy] = 1;
					
					qx.push(tmpx);
					qy.push(tmpy);
					qt.push(tmpt + tt);
				}
			}
		}
		
	}
	return ans;
}



int main(){
	
	while(scanf("%d%d",&n,&m) == 2){
		memset(map,0,sizeof(map));
		
		getchar();
		
		int ans = INT_MAX;
		int sx,sy;
		
		for(int i = 0; i < n; i++)
			scanf("%s",&map[i]);
		
//		for(int i = 0; i < n; i++)
//			printf("%s\n",map[i]);
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(map[i][j] == 'r'){
					int tmp = BFS(i, j);
//					printf("%d %d %d\n",i,j,tmp);
					ans = min(ans ,tmp);
					map[i][j] = '#';
				}
		if(ans != INT_MAX)
			printf("%d\n",ans);
		else
			printf("Poor ANGEL has to stay in the prison all his life.\n");
	}

	return 0;
}

