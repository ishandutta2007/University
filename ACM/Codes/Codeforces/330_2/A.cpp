#include <cstdio>
#include <iostream>


using namespace std;


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;

	int x, y;
	for(int i = 0; i < n; i++)
	{
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			if(x+y > 0) ans ++;
		}
	}

	cout << ans << endl;

	return 0;
}