#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct Node{

	char name[120];
	int adge;
}nd[120];


bool cmp(struct Node a, struct Node b)
{
	return a.adge > b.adge;
}


int main()
{


	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		getchar();
		for(int i = 0; i < n; i++)
		{
			gets(nd[i].name);

			int len = strlen(nd[i].name);
			nd[i].adge = 0;
			for(int j = 4; j > 0; j--)
			{
				nd[i].adge = nd[i].adge*10 + nd[i].name[len-j] - '0';
			}
			nd[i].name[len-5] = '\0';
			// printf("%s %d\n", nd[i].name, nd[i].adge);
		}

		sort(nd, nd + n, cmp);

		for(int i = 0; i < n; i++)
			cout << nd[i].name << endl;
	}

	return 0;
}