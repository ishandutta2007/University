#include <bits/stdc++.h>
using namespace std;


int ans[200][200];
int a[200][200];
int n;


void tonext(int &x, int &y, int &t)
{
	int dx, dy;
	int tx, ty;
	if(t % 2 == 0) {
		dx = -1;
		dy = 1;
	} else {
		dx = 1;
		dy = -1;
	}
	tx = x + dx;
	ty = y + dy;
	if(tx < 0 || tx >= n || ty < 0 || ty >= n)
	{
		t++;
		swap(dx, dy);
		if(t % 2 == 0)
		{
			x = t;
			y = 0;
		}
		else
		{
			x = 0;
			y = t;
		}

		while(x >= n || y >= n)
		{
			x += dx;
			y += dy;
		}

	} else {
		x = tx;
		y = ty;
	}
	// cout << x << " " << y << endl;
}


int main()
{

	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);

		int x = 0, y = 0, t = 0;
		for (int i = 0; i < n*n; i++)
		{
			ans[i/n][i%n] = a[x][y];
			if(i == n*n-1) break;
			tonext(x, y, t);
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				printf("%d%c", ans[i][j], j == n-1? '\n' : ' ');
			}

	}


	return 0;
}