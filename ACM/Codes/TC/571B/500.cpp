#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;


typedef long long LL;

int cnt[6000020];

class BearDartsDiv2{
public:
	LL count(vector <int> w)
	{
		int n = w.size();		
		memset(cnt, 0, sizeof(cnt));

		for(int i = 2; i < n; i++)
			cnt[w[i]] ++;
		LL res = 0;
		for(int c = 2; c < n; c++)
		{
			cnt[w[c]]--;
			for(int a = 0; a < c; a++)
				for(int b = a+1; b < c; b++)
				{
					LL tmp = (LL)w[a]*w[b]*w[c];
					if(tmp <= 6000000)
						res += cnt[tmp];
				}
		}

		return res;
	}


};