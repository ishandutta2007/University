#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <map>
#include <queue>
#include <cmath>
#define INF 0x3f3f3f3f

using namespace std;



typedef long long LL;

// LL dist[987654322];
deque<int>dq;
deque<int>dd;
map<int, long long>dist;

int sid[4][10] = 
{
	{0,2,5,3,1,4,6,7,8,9},
	{0,1,3,6,4,2,5,7,8,9},
	{0,1,2,3,5,8,6,4,7,9},
	{0,1,2,3,4,6,9,7,5,8},
};
void prepro()
{
	dq.clear();
	dd.clear();
	dist[123456789] = 0;

	dq.push_back(123456789);
	dd.push_back(0);


	int now, nowd;
	int dig[10], tmpdig[10], nexts;
	while(!dq.empty())
	{
		now = dq.front();
		dq.pop_front();
		nowd = dd.front();
		dd.pop_front();
		for(int i = 9; i >= 1; i--)
		{
			dig[i] = now%10;
			now/=10;
		}

		for(int i = 0; i < 4; i++)
		{
			nexts = 0;
			for(int j = 1; j <= 9; j++)
			{
				tmpdig[j] = dig[sid[i][j]];
				nexts = nexts * 10 + tmpdig[j];
			}

			if(dist.find(nexts) == dist.end())
			{
				dist[nexts] = nowd+1;
				dq.push_back(nexts);
				dd.push_back(nowd+1);
			}
		}

	}

}



int main()
{


	prepro();
	int n , x;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 1; i < 9; i++)
		{
			scanf("%d", &x);
			n = n*10 + x;
		}

		printf("%lld\n", max(0LL, dist[n]));

	}


	return 0;
}