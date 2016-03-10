#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;


char mp[200][200];


struct P
{
	int x, y;
	char c;
}p[3];


bool cmp(struct P a, struct P b)
{
	return a.x > b.x;
}


int main()
{

	int x, y;
	for(int i = 0; i < 3; i++)
	{
		scanf("%d%d", &x, &y);
		p[i].x = max(x, y);
		p[i].y = min(x, y);
		p[i].c = 'A' + i;
	}
	sort(p, p + 3, cmp);
	int width = p[0].x;
	int h = p[0].y;
	for(int i = 1; i <= p[0].y; i++)
		for(int j = 1; j <= width; j++)
			mp[i][j] = p[0].c;


	if(p[1].x == p[2].x && p[1].x == width )
	{

		if(p[1].y + p[2].y + p[0].y != width)
		{
			printf("-1\n");
			return 0;
		}

		for(int i = 1; i <= p[1].y; i++)
			for(int j = 1; j <= width; j++)
				mp[i+p[0].y][j] = p[1].c;
		for(int i = 1; i <= p[2].y; i++)
			for(int j = 1; j <= width; j++)
				mp[i+p[0].y + p[1].y][j] = p[2].c;

		printf("%d\n", width);
		for(int i = 1; i <= width; i++)
		{
			for(int j = 1; j <= width;j++)
				printf("%c", mp[i][j]);
			printf("\n");
		}
		return 0;
	}




	if((p[1].x + h == width || p[1].y + h == width) && (p[2].x + h == width || p[2].y + h == width))
	{
		if(p[1].y + h == width)
		{
			swap(p[1].x, p[1].y);
		}
		if(p[2].y + h == width)
		{
			swap(p[2].x, p[2].y);
		}


		if(p[1].y + p[2].y != width)
		{
			printf("-1\n");
			return 0;
		}


		int d = p[1].y;


		for(int i = h + 1; i <= width; i++)
			for(int j = 1; j <= width; j++)
			{
				mp[i][j] = j > d? p[2].c : p[1].c;
			}

			printf("%d\n", width);
		for(int i = 1; i <= width; i++)
		{
			for(int j = 1; j <= width;j++)
				printf("%c", mp[i][j]);
			printf("\n");
		}
		return 0;
	}

	else
	{
		printf("-1\n");
		return 0;
	}

	
	return 0;
}