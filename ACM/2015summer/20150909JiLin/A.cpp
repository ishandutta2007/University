#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>


using namespace std;



char mp[1020][1020];
int n, m;

char UP(int x, int y)
{
	if(x - 2 < 0 || mp[x-1][y] != mp[x-2][y]) return 'a';
	return mp[x-1][y];
}
char MID(int x, int y)
{
	if(x + 1 >= n || x - 1 < 0 || mp[x-1][y] != mp[x+1][y]) return 'a';
	return mp[x-1][y];
}

char DO(int x, int y)
{
	if(x + 2 >= n || mp[x+1][y] != mp[x+2][y]) return 'a';
	return mp[x+1][y];
}

char LEFT(int x, int y)
{
	if(y - 2 < 0 || mp[x][y-1] != mp[x][y-2]) return 'a';
	return mp[x][y-1];
}

char RIGHT(int x, int y)
{
	if(y + 2 >= m || mp[x][y+1] != mp[x][y+2]) return 'a';
	return mp[x][y+1];
}

char MMID(int x, int y)
{
	if(y + 1 >= m || y - 1 < 0 || mp[x][y-1] != mp[x][y+1]) return 'a';
	return mp[x][y-1];
}

bool tleft(int x, int y)
{
	if(y + 1 >= m) return false;

	char ch = mp[x][y+1];
	if(UP(x, y) == ch) return true;
	if(MID(x, y) == ch) return true;
	if(DO(x, y) == ch) return true;
	if(LEFT(x, y) == ch) return true;

	ch = mp[x][y];
	if(UP(x, y+1) == ch) return true;
	if(MID(x, y+1) == ch) return true;
	if(DO(x, y+1) == ch) return true;
	if(RIGHT(x, y) == ch) return true;

	return false;
}
bool tdown(int x, int y)
{
	if(x + 1 >= n) return false;

	char ch = mp[x+1][y];
	if(LEFT(x, y) == ch) return true;
	if(MMID(x, y) == ch) return true;
	if(RIGHT(x, y) == ch) return true;
	if(UP(x, y) == ch) return true;

	ch = mp[x][y];
	if(LEFT(x+1, y) == ch) return true;
	if(MMID(x+1, y) == ch) return true;
	if(RIGHT(x+1, y) == ch) return true;
	if(DO(x+1, y) == ch) return true;

	return false;

}


int main()
{
	while(scanf("%d%d", &n, &m))
	{
		
		for(int i = 0; i < n; i++)
			scanf("%s", mp[i]);

		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				if(j+1 < m && tleft(i, j)) ans++;
				if(i+1 < n && tdown(i, j)) ans++;
			}

		printf("%d\n", ans);

	}
	return 0;
}