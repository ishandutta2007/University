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


int step[10000000];
int onslot[10];
int high[10];
int tmp[10];
int a[10];
int b[10];
int n;

int asd[8] = {0, 1, 12, 123, 1234, 12345, 123456, 1234567};
queue<int> qu;


void getslot(int x)
{
	memset(high, 0x3f, sizeof(high));
	int slot;
	int tp = n;
	while(x)
	{
		slot = x % 10;
		high[slot] = tp;
		onslot[tp--] = slot;
		x /= 10;
	}
}


int getid()
{

	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		ret = ret*10 + tmp[i];
	}

	return ret;

}

void showslot()
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


int  bfs(int st)
{
	step[st] = 0;
	while(!qu.empty())
	{
		qu.pop();
	}

	qu.push(st);
	int now, nextid;
	while(!qu.empty())
	{
		now = qu.front();
		qu.pop();

		// cout << "now" << " " << now << endl;

		if(now == asd[n])
			return step[now];

		getslot(now);

		// showslot();

		// system("pause");

		for(int i = 1; i <= n; i++)if(high[i] <= n)
		{
			if(i - 1 > 0 && high[i] < high[i-1])
			{
			// cout << "!!!" << endl;
				for(int j = 1; j <= n; j++)
					tmp[j] = onslot[j];

				tmp[high[i]] = i-1;
				nextid = getid();
				
				if(step[nextid] == -1)
				{

					// showtmp(n);
					// system("pause");
					step[nextid] = step[now] + 1;
					// cout << "push" << nextid <<endl;
					qu.push(nextid);
				}
			}
			if(i + 1 <= n && high[i] < high[i+1])
			{
				for(int j = 1; j <= n; j++)
					tmp[j] = onslot[j];

				tmp[high[i]] = i+1;
				nextid = getid();

				if(step[nextid] == -1)
				{
					// showtmp(n);
					// system("pause");
					step[nextid]= step[now] + 1;
					// cout << "push" << nextid <<endl;
					qu.push(nextid);
				}
			}
		}
	}
	return -1;
}






int main()
{
	// memset(step, -1, sizeof(step));

	// for(int i = 1; i < 8; i ++)
	// 	prepro(i);


	// cout << sizeof(step)/1024/1024 << endl;
	// prepro(7);


	// cout << step[1335414][7] << endl;
	// cout << step[1554655][7] << endl;

	// freopen("in.txt", "r", stdin);

	// freopen("out.txt", "w", stdout);
	// for(int i = 1; i < 1000; i++)
	// {
	// 	printf("%d %d\n", i, step[i][3]);
	// }
	// return 0;

	int T;
	scanf("%d", &T);

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

		int id = getid();

		memset(step, -1, sizeof(step));


		// cout << id << endl;

		printf("%d\n", bfs(id));

	}



	return 0;
}