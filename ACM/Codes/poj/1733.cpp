#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

map<int , int>mp;
int tot;
int n, m;


struct Node{
	int f, d;
}nd[10020];


pair<int ,int> root(int x)
{
	int same = 0;
	while(nd[x].f != x)
	{
		same += nd[x].d;
		x = nd[x].f;
	}
	return make_pair(x, same % 2);
}


int main()
{


	scanf("%d%d",&n,&m);
	for(int i = 0; i <= 2 * m; i++)
	{
		nd[i].f = i;
		nd[i].d = 0;
	}

	int l, r, d;
	char str[10];
	pair<int, int>rootl, rootr;

	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%s",&l,&r,str);

		if(strcmp(str, "even") == 0)
			d = 0;
		else
			d = 1;
		l--;

		if(mp.find(l) == mp.end())
		{
			mp[l] = tot++;
		}
		if(mp.find(r) == mp.end())
		{
			mp[r] = tot++;
		}
		l = mp[l];
		r = mp[r];
		rootl = root(l);
		rootr = root(r);

		if(rootl.first == rootr.first)
		{
			if((rootl.second + rootr.second)%2 != d)
			{
				printf("%d\n", i-1);
				return 0;
			}
		}

		else
		{
			nd[rootr.first].f = rootl.first;
			nd[rootr.first].d = (d+rootr.second+rootl.second)%2;
		}

	}


	printf("%d\n", m);



	return 0;
}