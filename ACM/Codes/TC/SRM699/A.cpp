#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


struct P
{
	int d;
	string name;
}p[200];

bool cmp(struct P a, struct P b)
{
	return a.d > b.d;
}

map<string , bool>mp;

class LiveConcert{
public:

	int maxHappiness(vector<int> vi, vector<string> vs)
	{
		int ret = 0;
		int n = vi.size();

		for(int i = 0; i < n; i++)
		{
			p[i].d = vi[i];
			p[i].name = vs[i];
		}

		sort(p, p + n, cmp);
		mp.clear();

		for(int i = 0; i < n; i++)
		{
			if(mp.find(p[i].name) == mp.end())
			{
				ret += p[i].d;
				mp[p[i].name] = true;
			}
		}


		return ret;
	}



};