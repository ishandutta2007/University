#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

int board[1020][1020];
int flag[1020][1020];
int mx[4] = {1,-1,0,0};
int my[4] = {0,0,-1,1};

int n,m;

queue<int> qx,qy,px,py,t;

bool check(int x, int y){
	if(x >= 1 && x <= n && y >= 1 && y <= m && flag[x][y] == 0 && board[x][y] == 0)
		return true;
	return false;
}



bool BFS(int sx, int sy, int ex, int ey){
	int nowx,nowy,nowt,nowpx,nowpy;
	int tmpx,tmpy,tmpt,tmppx,tmppy;
	
	memset(flag,0,sizeof(flag));
	
	qx.push(sx);
	qy.push(sy);
	px.push(-1);
	py.push(-1);
	t.push(0);
	
	while(!qx.empty()){
		nowx = qx.front();
		nowy = qy.front();
		nowpx = px.front();
		nowpy = py.front();
		nowt = t.front();
		qx.pop();
		qy.pop();
		px.pop();
		py.pop();
		t.pop();
		
		for(int i = 0; i < 4; i++){
			tmpx = nowx + mx[i];
			tmpy = nowy + my[i];
			if(tmpx == ex && tmpy == ey)
				return true;
			if(check(tmpx,tmpy))
			{
				flag[tmpx][tmpy] = 1;
				if(nowpx == -1 && nowpy == -1)
				{
					flag[tmpx][tmpy] = 1;
					qx.push(tmpx);
					qy.push(tmpy);
					px.push(nowx);
					py.push(nowy);
					t.push(0);
				}
				else
				{
					tmpt = nowt;
					if(nowpx != tmpx && nowpy != tmpy)
						tmpt++;
					
					if(nowt <= 2)
					{
						flag[tmpx][tmpy] = 1;
						qx.push(tmpx);
						qy.push(tmpy);
						px.push(nowx);
						py.push(nowy);
						t.push(tmpt);
					}
				}
				
			}
			
		}
		
		
	}
	return false;
}




int main(){
	
	while(scanf("%d%d",&n,&m) && n && m){
		
		memset(board,0,sizeof(board));
		
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d",&board[i][j]);
		
		int q;
		int x1,y1,x2,y2;
		scanf("%d",&q);
		while(q--){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(board[x1][y1] && board[x1][y1] == board[x2][y2] && BFS(x1,y1,x2,y2))
				printf("YES\n");
			else
				printf("NO\n");
		}
		
		
	}
	return 0;
}

