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



int main()
{


	freopen("out1.txt", "w", stdout);

	init(100000);
	memset(sg, -1, sizeof(sg));
	int n = 35;
	for(int j = 1; j <= n; j++)
	{
		sg[j][j] = 0;


		for(int i = j - 1; i > 0; i--)
		{
			int np1 = i + 1;
			int np2 = lower_bound(pri.begin(), pri.end(), i) - pri.begin();
			if(pri[np2] == i) np2++;
			np2 = pri[np2];

			if(np1 > j && np2 > j) sg[i][j] = 0;
			else
			{
				sg[i][j] = 1;
				if(np1 <= j) sg[i][j] = min(sg[i][j], sg[np1][j]);
				if(np2 <= j) sg[i][j] = min(sg[i][j], sg[np2][j]);

				if(sg[i][j] == 0) sg[i][j] = 1;
				else sg[i][j] = 0;
			}

		}
		
	}

	printf("finish\n");
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			printf("%d%c", sg[i][j] > -1? sg[i][j]:0, j == n?'\n':' ');

	return 0;
}