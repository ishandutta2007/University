#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

using namespace std;


vector<int>pri, ans;
bool npri[10000020];

void init()
{
	for(int i = 2; i <= 10000020;i++)
	{
		if(npri[i] == 0)
		{
			pri.push_back(i);
			for(int j = i*2; j <= 10000020;j += i)
				npri[j] = true;
		}
	}
}




int main()
{


	init();


	int T;
	scanf("%d", &T);
	int n, m;
	while(T--)
	{
		scanf("%d", &n);
		ans.clear();
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &m);
			for(int j = 0,len = pri.size(); j < len; j++)
			{
				if(pri[j] > m) break;
				while(m % pri[j] == 0)
				{
					m /= pri[j];
					ans.push_back(pri[j]);
				}
			}
			if(m != 1)
				ans.push_back(m);
		}

		// unique(ans.begin(), ans.end());
		sort(ans.begin(), ans.end());
		if(ans.size() >= 2)
		{
			printf("%I64d\n", ((long long)ans[0])*ans[1]);
		}
		else
		{
			printf("-1\n");
		}

	}

	return 0;
}