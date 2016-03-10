#include <bits/stdc++.h>

using namespace std;


class RelationClassifier
{
public:
	string isBijection(vector <int> domain, vector <int> range)
	{
		bool flag = true;
		int len = domain.size();
		for(int i = 0; i < len; i++)
		{
			for(int j = 0; j < i; j++)
				if(domain[i] == domain[j])
					flag = false;
		}
		for(int i = 0; i < len; i++)
		{
			for(int j = 0; j < i; j++)
				if(range[i] == range[j])
					flag = false;
		}

		return flag ? "Bijection" : "Not";
	}
};