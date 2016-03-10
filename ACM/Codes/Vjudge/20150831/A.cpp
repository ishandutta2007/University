#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;


int sg[23333333];
int Day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isleap(int y)
{
	if((y%4 == 0 && y %100 != 0) || y % 400 == 0) return true;
	return false;
}


bool legal(int y, int m, int d)
{
	if(y*10000 + m*100 + d > 20011104) return false;
	if(d <= Day[m] + (m == 2 && isleap(y)))
		return true;
	return false;
}



int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	sg[20011104] = 0;

	int y, m, d, yy, mm, dd;
	for(int i = 20011104; i >= 19000101; i--)
	{
		sg[i] = 1;
		yy=y = i / 10000;
		mm=m = (i%10000)/100;
		dd=d = i%100;
		if(!legal(y, m, d)) continue;
		mm++;
		if(mm > 12)
		{
			mm=1;
			yy++;
		}
		if(legal(yy, mm, dd))
		{
			sg[i] = min(sg[i], sg[yy*10000+mm*100+dd]);
		}
		d++;
		if(d > Day[m]+(m==2&&isleap(y)))
		{
			d = 1;
			m ++;
			if(m > 12)
			{
				m = 1;
				y ++;
			}
		}
		if(legal(y, m, d))
		{
			sg[i] = min(sg[i],sg[y*10000+m*100+d]);
		}
		if(sg[i] == 0) sg[i] = 1;
		else sg[i] = 0;

	}


	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		scanf("%d%d%d",&y,&m,&d);
		if(sg[y*10000+m*100+d])
			printf("YES\n");
		else
			printf("NO\n");
	}


	return 0;
}