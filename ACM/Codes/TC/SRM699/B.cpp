#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;



class CombiningSlimes
{
public:
	int maxMascots(vector<int> a)
	{
		int ret = 0;
		int sum = a[0];
		int n = a.size();
		for(int i = 1; i < n; i++)
		{
			ret += sum * a[i];
			sum += a[i];
		}



		return ret;
	}


};