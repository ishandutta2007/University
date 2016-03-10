#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class TheDeviceDiv2
{
public:

	string identify(vector <string> p)
	{
		bool flag = true;
		
		int n = p.size();
		int len = p[0].size();


		for(int i = 0; i < len; i++)
		{
			int cnt[2] = {0};
			for(int j = 0; j < n; j++)
				cnt[p[j][i] - '0'] ++;

			if(!(cnt[0] > 0 && cnt[1] > 1))
				flag = false;
		}

		return flag? "YES" : "NO";
	}
};