#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

int n;
int a[400];
int fa[400];
char mp[400][400];
vector<int> v[400];


int root(int a)
{
	return fa[a] == 0? a : fa[a] = root(fa[a]); 
}
void unionset(int a, int b)
{
	int ra = root(a);
	int rb = root(b);
	if(ra != rb)
		fa[ra] = b;
}



int main()
{


	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int x;

	for(int i = 0; i < n; i++)
		scanf("%s", mp[i]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(mp[i][j] == '1')
				unionset(a[i+1], a[j+1]);
		}


	// cout << "!! " << endl;
	for(int i = 1; i <= n; i++)
	{
		x = root(a[i]);
		// printf("%d %d\n", i, x);
		v[x].push_back(a[i]);
	}

	for(int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());

	for(int i = 1; i <= n; i++)
	{
		int rt = root(a[i]);

		printf("%d ", v[rt][0]);
		v[rt].erase(v[rt].begin());
	}
	return 0;
}