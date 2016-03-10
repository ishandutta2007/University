#include<iostream>
using namespace std;
const int maxn=100;
struct data{
	int x,y;
};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int g[maxn][maxn];
int cnt;
void RedandBlack(data s,int m,int n)
{
	int i;
	data f;
	g[s.x][s.y]=1; 
	cnt++; 
	for(i=0;i<4;i++)                     
	{
		f.x=s.x+dir[i][0];       
		f.y=s.y+dir[i][1];
		if(f.x<0||f.y<0||f.x>m-1||f.y>n-1)    //±ß½çÌõ¼şÅĞ¶Ï
			continue;
		if(g[f.x][f.y]==0)
		{
			
			
			RedandBlack(f,m,n);
	    }
	}
	return ;
}
int main()
{
	int m,n,i,j;
	char x;
	data start;
	while(scanf("%d %d",&n,&m)==2&&m&&n)
	{
		getchar();
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%c",&x);
				if(x=='.')
				{
					g[i][j]=0;
				}
				else if(x=='#')
				{
					g[i][j]=1;
				}
				else
				{
					g[i][j]=0;
					start.x=i;
					start.y=j;
				}
			}
			getchar();
		}
		cnt = 0;
		RedandBlack(start,m,n);
		printf("%d\n",cnt);
	}
	return 0;
}