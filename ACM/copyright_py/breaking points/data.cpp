#include <bits/stdc++.h>
using namespace std;

int vis[50020];
int T = 100;
int n = 50000;


int main()
{

	freopen("data.in", "w", stdout);
	cout << T << endl;
	while(T)
	{
		int tn, tk, tm;
		tn = rand()%(n+1);
		if(tn == 0) continue;
		tk = rand()%(tn+1);
		if(tk == 0) continue;
		tm = rand()%(tn+1);

		printf("%d %d %d\n", tn, tk, tm);
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < tm; i++)
		{
			int tmp = rand() % (tn+1);
			if(vis[tmp] == 1) {
				i--;
				continue;
			}
			else{
				vis[tmp] = 1;
				printf("%d%c", tmp, i == tm-1? '\n':' ');
			}

		}
		T--;
	}
	return 0;
}