#include <bits/stdc++.h>

using namespace std;

int d[60][60];
int vis[60][60];
int dd[60][60];

const int INF = 0x3f3f3f3f;

class ShortestPathWithMagic
{
public:
	double getTime(vector<string> dist, int t)
	{
		int n = dist.size();
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				d[i][j] = (dist[i][j] - '0') * 2;
		}



		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


		while(t--)
		{
			int tmp = INF;
			int xx = -1, yy = -1;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)if(i != j)
				{
					if(vis[i][j] == 0 && d[0][i] + d[j][1] + d[i][j] / 2 < tmp)
					{
						tmp = d[0][i] + d[j][1] + d[i][j] / 2;
						xx = i, yy = j;
					}
				}

			if(xx == -1) continue;


			cout << xx  << "   " << y << endl;

			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
					d[i][j] = (dist[i][j] - '0') * (2 - vis[i][j]);
			}


			vis[xx][yy] = vis[yy][xx] = 1;
			d[xx][yy] /= 2;
			d[yy][xx] /= 2;




			for(int k = 0; k < n; k++)
				for(int i = 0; i < n; i++)
					for(int j = 0; j < n; j++)
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					printf("%d%c", d[i][j], j == n-1? '\n':' ');

		}

		return d[0][1] * 0.5;
	}
};

