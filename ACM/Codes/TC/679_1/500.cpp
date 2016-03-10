#include <bits/stdc++.h>

using namespace std;

class FiringEmployees
{
public:
	int fire(vector <int> manager, vector <int> salary, vector <int> productivity)
	{

		int all = 0;
		int drop = 0;
		int n = manager.size();
		vector<int> d;
		d.clear();
		for(int i = 0 ; i < n; i++)
		{
			d.push_back(productivity[i] - salary[i]);
			all += productivity[i] - salary[i];
		}


		for(int i = n-1; i >= 0; i--)
		{
			if(d[i] < 0)
				drop += d[i];

			else if(manager[i] > 0)
			{
				d[manager[i]-1] += d[i];
			}

		}

		return all - drop;

	}
};

