#include <bits/stdc++.h>

using namespace std;

struct Node	
{
	int t, c;
	Node(){}
	Node(int t, int c):t(t), c(c){}
};

bool cmp(Node a, Node b)
{
	return a.c < b.c;
}

class FarmvilleDiv2
{
public:
	int minTime(vector <int> time, vector <int> cost, int budget)
	{
		int n = time.size();
		vector<Node> v;
		for(int i = 0; i < n; i++)
			v.push_back(Node(time[i], cost[i]));

		sort(v.begin(), v.end(), cmp);

		int ret = 0;

		for(int i = 0; i < n; i++)
		{
			if(budget >= v[i].t * v[i].c)
			{
				budget -= v[i].t * v[i].c;
			}
			else
			{
				v[i].t -= budget / v[i].c;
				budget %= v[i].c;
				ret += v[i].t;
			}
		}

		return ret;

	}
};