#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


struct Point
{
	int x, y;
	int up[2], upright[2], right[2], downright[2], down[2], same[2];
	void clear()
	{
		up[1] = upright[1]= right[1]= downright[1]= down[1]= same[1] = up[0] = upright[0]= right[0]= downright[0]= down[0]= same[0] = 0;
	}
}stand_s[120], tmp_s[120], stand_e[120], tmp_e[120];

int stand_m;



bool cmp(Point a, Point b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}


void cal(Point& a, Point sta[120], Point ed[120], int len)
{

	for(int i = 0; i < len; i ++)
	{
		if(sta[i].x == a.x && sta[i].y == a.y)
		{
			a.same[0]++;
		}
		else if(sta[i].x == a.x)
		{
			if(sta[i].y > a.y)
				a.up[0]++;
			else
				a.down[0]++;
		}
		else if(sta[i].y == a.y)
		{
			if(sta[i].x > a.x)
				a.right[0]++;
		}

		else if(sta[i].x > a.x && sta[i].y > a.y)
		{
			a.upright[0]++;
		}
		else if(sta[i].x > a.x && sta[i].y < a.y)
		{
			a.downright[0]++;
		}
	}
	for(int i = 0; i < len; i ++)
	{
		if(ed[i].x == a.x && ed[i].y == a.y)
		{
			a.same[1]++;
		}
		else if(ed[i].x == a.x)
		{
			if(ed[i].y > a.y)
				a.up[1]++;
			else
				a.down[1]++;
		}
		else if(ed[i].y == a.y)
		{
			if(ed[i].x > a.x)
				a.right[1]++;
		}

		else if(ed[i].x > a.x && ed[i].y > a.y)
		{
			a.upright[1]++;
		}
		else if(ed[i].x > a.x && ed[i].y < a.y)
		{
			a.downright[1]++;
		}
	}

}

void cl()
{
	for(int i = 0; i <= 100; i++)
	{
		tmp_s[i].clear();
		tmp_e[i].clear();
	}
}

bool ccmp(Point A, Point B)
{
	if(!( A.up[0] == B.up[0] && A.upright[0] == B.upright[0] && A.right[0] == B.right[0] && A.downright[0] == B.downright[0] && A.down[0] == B.down[0] && A.same[0] == B.same[0]))
		return false;
	if(!( A.up[1] == B.up[1] && A.upright[1] == B.upright[1] && A.right[1] == B.right[1] && A.downright[1] == B.downright[1] && A.down[1] == B.down[1] && A.same[1] == B.same[1]))
		return false;
	return true;
}


bool totcmp()
{

	for(int i = 0; i < stand_m; i++)
	{
		if(!ccmp(stand_s[i], tmp_s[i])) return false;
		if(!ccmp(stand_e[i], tmp_e[i])) return false;
	}
	return true;
}


int main()
{

	int n;
	scanf("%d", &n);
	scanf("%d", &stand_m);
	for(int i = 0; i < stand_m; i++)
	{
		scanf("%d%d%d%d", &stand_s[i].x,&stand_s[i].y,&stand_e[i].x,&stand_e[i].y);
	}
	sort(stand_s, stand_s + stand_m, cmp);
	sort(stand_e, stand_e + stand_m, cmp);

	for(int i = 0; i < stand_m; i++)
	{
		cal(stand_s[i], stand_s, stand_e, stand_m);
		cal(stand_e[i], stand_s, stand_e, stand_m);
	}

	for(int i = 1; i < n; i++)
	{
		cl();
		int m;
		scanf("%d", &m);

		for(int i = 0; i < m; i++)
			scanf("%d%d%d%d", &tmp_s[i].x,&tmp_s[i].y,&tmp_e[i].x,&tmp_e[i].y);		

		if(m != stand_m)
		{
			printf("INCORRECT\n");
			continue;
		}
		sort(tmp_s, tmp_s + m, cmp);
		sort(tmp_e, tmp_e + m, cmp);

		for(int i = 0; i < stand_m; i++)
		{
			cal(tmp_s[i], tmp_s, tmp_e, m);
			cal(tmp_e[i], tmp_s, tmp_e, m);
		}

		printf("%s\n", totcmp()? "CORRECT" : "INCORRECT");

	}


	return 0;
}