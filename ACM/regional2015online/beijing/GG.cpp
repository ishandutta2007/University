#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;


int step[7777778][8];
int onslot[10];
int high[10];
int tmp[10];
int a[10];
int b[10];

int asd[8] = {0, 1, 12, 123, 1234, 12345, 123456, 1234567};
queue<int> qu;


void getslot(int x, int n)
{
	memset(high, 0x3f, sizeof(high));
	int slot;
	while(x)
	{
		slot = x % 10;
		high[slot] = n;
		onslot[n] = slot;
		n--;
		x /= 10;
	}
}


int getid(int n)
{

	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		ret = ret*10 + tmp[i];
	}

	return ret;

}

void showslot(int n)
{
	cout << "slot" << endl;
	for(int i = 1; i <= n; i++)
	{
		printf("%d %d\n", i, onslot[i]);
	}

	printf("\n");

	cout << "high" << endl;
	for(int i = 1; i <= n; i++)
	{
		printf("%d %d\n", i, high[i]);
	}
	printf("\n");
}

void showtmp(int n)
{
	cout << "tmp" << endl;
	for(int i = 1; i <= n; i++)
	{
		printf("%d %d\n", i, tmp[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");

} 


void prepro(int n)
{
	step[asd[n]][n] = 0;

	while(!qu.empty())
		qu.pop();

	qu.push(asd[n]);

	int now, nextid;
	while(!qu.empty())
	{
		now = qu.front();
		qu.pop();

		getslot(now, n);

		// showslot(n);

		// system("pause");

		for(int i = 1; i <= n; i++)if(high[i] <= n)
		{
			if(i - 1 > 0 && high[i] < high[i-1])
			{
				for(int j = 1; j <= n; j++)
					tmp[j] = onslot[j];

				tmp[high[i]] = i-1;
				nextid = getid(n);

				if(step[nextid][n] == -1)
				{

					// showtmp(n);
					// system("pause");
					step[nextid][n] = step[now][n] + 1;
					// cout << "push" << nextid <<endl;
					qu.push(nextid);
				}
			}
			if(i + 1 <= n && high[i] < high[i+1])
			{
				for(int j = 1; j <= n; j++)
					tmp[j] = onslot[j];

				tmp[high[i]] = i+1;
				nextid = getid(n);

				if(step[nextid][n] == -1)
				{
					// showtmp(n);
					// system("pause");
					step[nextid][n] = step[now][n] + 1;
					// cout << "push" << nextid <<endl;
					qu.push(nextid);
				}
			}
		}
	}

}






int main()
{
	memset(step, -1, sizeof(step));

	for(int i = 1; i < 8; i ++)
		prepro(i);


	// cout << sizeof(step)/1024/1024 << endl;
	// prepro(4);
	
	// cout << step[2244][4] << endl;

	// cout << step[1335414][7] << endl;
	// cout << step[1554655][7] << endl;

	// freopen("in.txt", "r", stdin);

	// freopen("out.txt", "w", stdout);
	// for(int i = 1; i < 1000; i++)
	// {
	// 	printf("%d %d\n", i, step[i][3]);
	// }
	// return 0;
	// cout << "!!" << endl;
	int T;
	scanf("%d", &T);

	int n;
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
		}

		sort(b + 1, b + n + 1);

		for(int i = 1; i <= n; i++)
			tmp[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;

		int id = getid(n);
		// cout << "!!" << endl;
		cout << step[id][n] << endl;

	}



	return 0;
}