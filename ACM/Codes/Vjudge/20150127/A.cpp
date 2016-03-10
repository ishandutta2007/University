#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>


using namespace std;

char map[10][10];
int N,M,T;
int ex,ey;
int mx[4] = {1,-1,0,0};
int my[4] = {0,0,1,-1};
int ans;



bool check(int x, int y){
	if(x >= 0 && x < N && y >=0 && y < M && map[x][y] != 'X')
		return true;
	return false;
	
}


void DFS(int nowx, int nowy, int t){
	if(nowx == ex && nowy == ey && t == 0)
	{
		ans = 1;
		return;
	}
	
	if(t < 0)
		return;
	
	if(ans)
		return;
	int tmpx,tmpy;
	map[nowx][nowy] = 'X';
	for(int i = 0; i < 4; i++)
	{
		tmpx = nowx + mx[i];
		tmpy = nowy + my[i];
		if(check(tmpx,tmpy))
		{
			DFS(tmpx,tmpy,t-1);
		}
	}
	map[nowx][nowy] = '.';
	
	
}





int main(){
	int sx,sy;
	
	
	while(true){
		scanf("%d%d%d",&N,&M,&T);
		if(N == 0)
			break;
//		getchar();
		
		for(int i = 0; i < N; i++)
			scanf("%s",map[i]);
		
//		for(int i = 0 ; i < N; i++)
//			printf("%s\n",map[i]);
		
		for(int i = 0; i < N; i++)
			for(int j = 0 ; j < M; j++)
				if(map[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
				else if(map[i][j] == 'D')
				{
					ex = i;
					ey = j;
				}
		ans = 0;
		if(abs(sx - ex) + abs(sy - ey) > T){
			printf("NO\n");
			continue;
		}
		if(((sx + sy) % 2 == (ex + ey) % 2) && T % 2 == 1){
			printf("NO\n");
			continue;
		}
		if(((sx + sy) % 2 != (ex + ey) % 2) && T % 2 == 2){
			printf("NO\n");
			continue;
		}
		DFS(sx, sy, T);
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

