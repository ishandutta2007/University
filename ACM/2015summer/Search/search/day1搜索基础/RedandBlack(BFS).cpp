#include<iostream>
#include<queue>
using namespace std;
const int maxn=100;
struct data{
	int x,y;
};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int g[maxn][maxn];
int RedandBlack(data start,int m,int n)
{
	queue<data> q;
	int i,cnt=0;
	data p,f;
	while(!q.empty())       //清空队列
	{
		q.pop();
	}
	q.push(start);         //初始状态入队
	g[start.x][start.y]=1;
	cnt++;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(i=0;i<4;i++)              //状态p的转移状态入队
		{
			f.x=p.x+dir[i][0];       
			f.y=p.y+dir[i][1];
			if(f.x<0||f.y<0||f.x>m-1||f.y>n-1)    //边界条件判断
				continue;
			if(g[f.x][f.y]==0)
			{
				q.push(f);
				g[f.x][f.y]=1;          
				cnt++;
			}
		}
	}
	return cnt;
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
		printf("%d\n",RedandBlack(start,m,n));
	}
	return 0;
}