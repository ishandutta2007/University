#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>


using namespace std;


vector<int>pri;
bool npri[1000020];
int d[1020];
int sg[10000][10000];
int tab[10000][10000];


void init(int mm)
{
	npri[1] = true;

	for(int i = 2; i <= mm; i++)
	{
		if(!npri[i])
		{
			pri.push_back(i);
			for(int j = i*2; j <= mm; j+=i)
			{
				npri[j] = true;
			}
		}
	}
}



int dfs(int i, int j)
{
	if(sg[i][j] != -1) return sg[i][j];
	// printf("dfs %d %d\n", i, j);
	int np1 = lower_bound(pri.begin(), pri.end(), i) - pri.begin();
	if(pri[np1] == i)
	{
		np1++;
	}
	np1 = pri[np1];
	int np2 = i+1;
	if(np1 > j && np2 > j) 
	{
		// printf("dfs %d %d %d\n", i, j, 1);
		return 1;
	}

	int ret = 1;

	if(np1 <= j) ret = min(ret, dfs(np1, j));
	if(np2 <= j) ret = min(ret, dfs(np2, j));

	if(ret == 1)
	{
		// printf("dfs %d %d %d\n", i, j, 0);
		return 0;
	}
	// printf("dfs %d %d %d\n", i, j, 1);
	return 1;
}

int main()
{


	freopen("out.txt", "w", stdout);

	init(100000);
	memset(sg, -1, sizeof(sg));
	int n = ;
	for(int j = 1; j <= n; j++)
	{

		sg[j][j] = 0;
		for(int i = 1; i < j; i++)
		{
			sg[i][j] = dfs(i, j);
		}
	}

		printf("finish\n");
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			printf("\t%d%c", sg[i][j] > -1? sg[i][j]:0, j == n?'\n':' ');

	return 0;
}