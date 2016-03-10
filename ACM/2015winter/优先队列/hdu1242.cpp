// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <cstdio>
// #include <queue>

// using namespace std;
// char mp[220][220];
// int vis[220][220];
// int mx[4] = {1,-1,0,0};
// int my[4] = {0,0,1,-1};
// int n, m;

// struct Node
// {
// 	int x, y, t;
// 	Node(int x, int y, int t):x(x),y(y),t(t){}
// 	Node(){}
// };

// bool operator < (Node a, Node b)
// {
// 	return a.t > b.t;
// }

// int solve(int x, int y)
// {
// 	priority_queue<Node> pq;
// 	pq.push(Node(x, y, 0));
// 	memset(vis, 0x3f, sizeof(vis));
// 	// vis[x][y] = 0;
// 	mp[x][y] = '#';
// 	while(!pq.empty())
// 	{
// 		Node now = pq.top();
// 		pq.pop();
// 		// if(mp[now.x][now.y] == 'r') return now.t;
// 		int tx, ty, tt;
// 		for(int i = 0; i < 4; i++)
// 		{
// 			tx = now.x + mx[i];
// 			ty = now.y + my[i];
// 			tt = now.t;

// 			if(tx >= 0 && tx < n && ty >= 0 && ty < m && mp[tx][ty] != '#')
// 			{
// 				if(mp[tx][ty] == 'r')
// 					return now.t + 1;

// 				else if(mp[tx][ty] == 'x')
// 				{
// 					pq.push(Node(tx,ty,tt + 2)),mp[tx][ty] = '#';
// 				}
// 				else if(mp[tx][ty] == '.')
// 					pq.push(Node(tx,ty,tt + 1)),mp[tx][ty] = '#';
// 			}
// 		}
// 	}
// 	return -1;
// }


// int main()
// {
// 	while(scanf("%d%d",&n,&m) != EOF)
// 	{
// 		for(int i = 0; i < n; i++)
// 			scanf("%s", mp[i]);
// 		int tx, ty;
// 		for(int i = 0; i < n; i++)
// 			for(int j = 0; j < m; j++)
// 			{
// 				if(mp[i][j] == 'a')
// 				{
// 					tx = i;
// 					ty = j;
// 				}
// 			}
// 		int tmp = solve(tx, ty);
// 		if(tmp == -1)
// 			printf("Poor ANGEL has to stay in the prison all his life.\n");
// 		else printf("%d\n", tmp);
// 	}
// 	return 0;
// }


#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;
char mp[220][220];
int vis[220][220];
int mx[4] = {1,-1,0,0};
int my[4] = {0,0,1,-1};


int n, m;


struct Node
{
	int x, y, t;
	Node(int x, int y, int t):x(x),y(y),t(t){}
	Node(){}
};


bool operator < (Node a, Node b)
{
	return a.t > b.t;
}



int solve(int x, int y)
{
	priority_queue<Node> pq;
	pq.push(Node(x, y, 0));
	memset(vis, 0, sizeof(vis));
	vis[x][y] = 1;
	while(!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		int tx, ty, tt;
		for(int i = 0; i < 4; i++)
		{
			tx = now.x + mx[i];
			ty = now.y + my[i];
			tt = now.t + 1;
			if(tx >= 0 && tx < n && ty >= 0 && ty < m && vis[tx][ty] == 0 && mp[tx][ty] != '#')
			{
				vis[tx][ty] = 1;
				if(mp[tx][ty] == 'r')
					return tt;
				else if(mp[tx][ty] == '.')
					pq.push(Node(tx,ty,tt));
				else if(mp[tx][ty] == 'x')
					pq.push(Node(tx,ty,tt+1));
			}
		}
	}
	return -1;
}




int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%s", mp[i]);
		int tx, ty;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				if(mp[i][j] == 'a')
				{
					tx = i;
					ty = j;
				}
			}
			int tmp = solve(tx, ty);
			if(tmp == -1)
				printf("Poor ANGEL has to stay in the prison all his life.\n");
			else printf("%d\n", tmp);
	}

	return 0;
}