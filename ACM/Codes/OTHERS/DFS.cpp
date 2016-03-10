#include"stdio.h"
#include"stdlib.h"

struct str{
	int x,y;
	int count;
};
int movex[4]={1,0,0,-1};
int movey[4]={0,1,-1,0};



char puzzle[1000][1000];
bool flag[1000][1000];

str ch[10000];
//int head=0;
//int tail=0;
int top=0;
int m,n;


void push(str pos){
	ch[top++]=pos;
}

void pop(){
	top--;	
}

bool empty(){
	if(top==0)
		return 0;
	return 1;
}

int check(int x,int y){
	if(x>=0 && x<m && y>=0 && y<n && puzzle[x][y]=='0'){
		puzzle[x][y]='1';
		return 1;
	}
	return 0;


}
int main(){
	int i,j;
	str tmp;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		scanf("%s",&puzzle[i]);
	str start;
	start.x=0;
	start.y=0;
	start.count=0;
	push(start);
	while(empty()){
		start=ch[top-1];
		pop();
		if(start.x==m-1 && start.y==n-1){
			printf("YES\n%d\n",start.count);
			system("pause");
			return 0;
		}
		for(i=0;i<4;i++){
			tmp.x=start.x+movex[i];
			tmp.y=start.y+movey[i];
			tmp.count=start.count+1;
			// printf("%d %d\n",tmp.x,tmp.y);
			if(check(tmp.x,tmp.y))
				push(tmp);
		}
	
	
	}
	printf("NO\n");
	system("pause");
	return 0;
	
	
	
	


}
