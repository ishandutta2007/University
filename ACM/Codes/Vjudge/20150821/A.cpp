#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

#define maxn 250

using namespace std;


int G[maxn][maxn];
int color[maxn];
int n, m;
deque<int>q;



bool bicolor()
{
	q.clear();
	memset(color, 0, sizeof(color));

	color[0] = 2;
	q.push_back(0);
	while(!q.empty())
	{
		int v = q.front();
		q.pop_front();
		for(int i = 0; i < n; i++)if(G[v][i] > 0)
		{
			if(color[i] != 0)
			{
				if(color[i] == color[v]) return false;
			}else{
				color[i] = color[v] ^ 1;
				q.push_back(i);
			}
		}
	}
	return true;
}


int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	while(cin >> n)
	{
		if(n == 0) return 0;
		cin >> m;
		memset(G, 0, sizeof(G));
		int x, y;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			G[x][y] = G[y][x] = 1;
		}

		if(bicolor()) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;
	}

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif


	return 0;
}