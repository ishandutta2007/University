#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;



bool inque[600];
int w[600];


LL tmp, ans;



vector<int>  v;


int main()
{


	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d", &w[i]);


	int x;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &x);
		tmp = 0;
		int j;
		for(j = v.size()-1; j >= 0; j--)
		{
			if(v[j] == x)
			{
				break;
			}
			tmp += w[v[j]];
		}
		ans += tmp;
		if(j >= 0) v.erase(v.begin() + j);
		v.push_back(x);
	}

	printf("%I64d\n", ans);

	return 0;
}