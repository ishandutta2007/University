#include"iostream"
#include"cstdio"
#include"algorithm"
#include"queue"


using namespace std;

int L,R,C;
char puzzle[35][35][35];
int sl,sr,sc,el,er,ec;
int movel[6]={1,-1,0,0,0,0};
int mover[6]={0,0,1,-1,0,0};
int movec[6]={0,0,0,0,1,-1};

int check(int x,int y,int z){
	if(x>=1 && x<=L && y>=1 &&y<=R && z>=1 && z<=C && puzzle[x][y][z]!='#')
		return 1;
	return 0;
}

int escape(){
	queue<int> ans,l,r,c;
	l.push(sl);
	r.push(sr);
	c.push(sc);
	ans.push(0);
	int nowl,nowr,nowc,nowans;
	int templ,tempr,tempc;
	while(l.empty()==0){
		
		nowl=l.front();
		nowr=r.front();
		nowc=c.front();
		nowans=ans.front();
//		printf("!!!%d %d %d\n",nowl,nowr,nowc);
		l.pop();
		r.pop();
		c.pop();
		ans.pop();
		if(nowl==el && nowr==er && nowc==ec)
			return nowans;
		for(int i=0;i<6;i++){
			templ=nowl+movel[i];
			tempr=nowr+mover[i];
			tempc=nowc+movec[i];
			if(check(templ,tempr,tempc)){
				l.push(templ);
				r.push(tempr);
				c.push(tempc);
				ans.push(nowans+1);
				puzzle[templ][tempr][tempc]='#';
			}
		}
		
	}
	return 0;
}




int main(){
	int i,j,k,time;
	while(1){
		scanf("%d%d%d",&L,&R,&C);
		if(L==0 && R==0 && C==0)
			break;
		for(i=1;i<=L;i++)
			for(j=1;j<=R;j++){
				for(k=1;k<=C;k++){
					cin >> puzzle[i][j][k];
					if(puzzle[i][j][k]=='S'){
						sl=i;
						sr=j;
						sc=k;
					}
					else if(puzzle[i][j][k]=='E'){
						el=i;
						er=j;
						ec=k;
					}
				}
			}
//		for(i=1;i<=L;i++){
//			for(j=1;j<=R;j++){
//				for(k=1;k<=C;k++)
//					printf("%c",puzzle[i][j][k]);
//				printf("\n");
//			}
//			printf("\n");
//		}
//		printf("%d %d %d\n%d %d %d\n\n",sl,sr,sc,el,er,ec);
		time=escape();
		if(time==0)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",time);
	}
	
	
	
	
}
