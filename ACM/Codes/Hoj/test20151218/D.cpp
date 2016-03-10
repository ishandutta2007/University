#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;

char ss[10][10];


int f(int x, int y)
{
	if(ss[x][y] == '#') return 1;
	else return 0;
}

int getans(int x, int y)
{
	int tmp = 0;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			tmp += f(x + i, y + j);
	
	if(tmp >= 3 || tmp <= 1)
		return 1;
	return 0;
	
}


int main()
{
	
	int T;
	
	cin >> T;
	while(T--)
	{
		for(int i = 0; i < 4; i++)
			scanf("%s", ss[i]);
		
		
		int ans = 0;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				ans = max(ans, getans(i,j));
		
		printf("%s\n", ans ? "YES" : "NO");
	}
	
	
	
	
	return 0;
}