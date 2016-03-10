#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, m, k;
int mp[5020][5020];
int id[100020], pos[100020], a[100020];
int row[5020], cow[5020];


int main()
{
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= k; i++)
		scanf("%d%d%d", &id[i], &pos[i], &a[i]);


	for (int i = k; i > 0; i--)
	{
		int tmp = pos[i];
		if(id[i] == 1) {
			if(row[tmp] == 0)
			{
				row[tmp] = 1;
				for (int j = 1; j <= m; j++) if(mp[tmp][j] == 0)
				{
					mp[pos[i]][j] = a[i];
				}
			}
		} else {
			if(cow[tmp] == 0)
			{
				cow[pos[i]] = 1;
				for (int j = 1; j <= n; j++) if(mp[j][tmp] == 0)
				{
					mp[j][tmp] = a[i];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			printf("%d%c", mp[i][j], j == m? '\n' : ' ');
	return 0;
}