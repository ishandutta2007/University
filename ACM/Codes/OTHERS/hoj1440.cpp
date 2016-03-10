#include"cstdio"
#include"iostream"
#include"algorithm"
#include"queue"
#include"cstring"


using namespace std;

char start[3];
char end[3];
int sx,sy,ex,ey;
int movex[8]={1,1,-1,-1,2,2,-2,-2};
int movey[8]={2,-2,2,-2,1,-1,1,-1};
int map[10][10];
int check(int x, int y){
	if(x>=1 && x<=8 && y>=1 && y<=8  && map[x][y]==0)
		return 1;
	return 0;
	
}


int go(){
	memset(map,0,sizeof(map));
	int nowx,nowy,nowans;
	queue<int> x,y,ans;
	x.push(sx);
	y.push(sy);
	map[sx][sy]=1;
	int tempx,tempy;
	ans.push(0);
	while(x.empty()==0){
		nowx=x.front();
		nowy=y.front();
		nowans=ans.front();
		x.pop();
		y.pop();
		ans.pop();
		if(nowx==ex && nowy==ey)
			return nowans;
		for(int i=0;i<8;i++){
			tempx=nowx+movex[i];
			tempy=nowy+movey[i];
			if(check(tempx,tempy)){
				x.push(tempx);
				y.push(tempy);
				map[tempx][tempy]=1;

				ans.push(nowans+1);
			}
		}
		
	}
	
	
}



int main(){
	while(scanf("%s %s",start,end)==2){
		sx=(int)start[0]-96;
		sy=(int)start[1]-48;
		ex=(int)end[0]-96;
		ey=(int)end[1]-48;
//		printf("%d %d\n%d %d\n\n",sx,sy,ex,ey);
		printf("To get from %s to %s takes %d knight moves.\n",start,end,go());
		
	}
	
	
	
	
}
