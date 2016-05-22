//在有n 个选手P1,P2,P3,…  ,Pn参加的单循环赛中，每对选手之间非胜即负。现要求求出一个选手序列： P1’,P2’,P3’,…  ,Pn’,其满足   Pi’胜Pi+1’(i=1,… ,n-1)。
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int mp[1020][1020];
int n;
vector<int> ans;
int main()
{
	printf("input the total number of players\n");
	scanf("%d", &n);
	printf("input a %d*%d matrix , the i row j col is 1 means i beat j\n", n, n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &mp[i][j]);
	ans.clear();
	for(int i = 1; i <= n; i++)
	{
		int j;
		int l = ans.size();
		for(j = 0; j < l; j++)
		{
			if(mp[i][ans[j]] == 0)
				break;
		}
		ans.insert(ans.begin()+j, i);
	}
	for(int i = ans.size()-1; i >= 0; i--)
		printf("%d ", ans[i]);
	return 0;
}