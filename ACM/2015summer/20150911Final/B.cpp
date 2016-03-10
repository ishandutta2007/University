#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;


deque<int>deq[2], id[2], oq;
bool indeq[2000020][2];

int maxpos, minpos;





void __maxinsert(int x, int i)
{
	while(!deq[maxpos].empty() && deq[maxpos].back() < x)
	{
		int iid = id[maxpos].back();
		indeq[maxpos][iid] = false;
		id[maxpos].pop_back();
		deq[maxpos].pop_back();
	}
	id[maxpos].push_back(i);
	deq[maxpos].push_back(x);
}
void __mininsert(int x, int i)
{
	while(!deq[minpos].empty() && deq[minpos].back() > x)
	{
		int iid = id[minpos].back();
		indeq[minpos][iid] = false;
		id[minpos].pop_back();
		deq[minpos].pop_back();
	}
	id[minpos].push_back(i);
	deq[minpos].push_back(x);
}

void __deqpop()
{

	int iid = oq.front();
	oq.pop_front();
	if(id[minpos].front() == iid)
	{
		indeq[minpos][iid] = false;
		deq[minpos].pop_front();
		id[minpos].pop_front();
	}

	if(id[maxpos].front() == iid)
	{
		indeq[maxpos][iid] = false;
		deq[maxpos].pop_front();
		id[maxpos].pop_front();
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	int n;
	char cmd[10];
	for(int ka = 1; ka <= T; ka++)
	{
		deq[0].clear();
		deq[1].clear();
		id[0].clear();
		id[1].clear();
		oq.clear();
		maxpos = 0, minpos = 1;
		memset(indeq, 0, sizeof(indeq));

		scanf("%d", &n);

		for(int i = 1; i <= n; i++)
		{
			scanf("%s", cmd);
			if(strcmp(cmd, "MAX") == 0 && oq.size() > 0)
			{
				printf("%d\n", deq[maxpos][0]);
			}

			else if(strcmp(cmd, "PUSH") == 0)
			{
				int x;
				scanf("%d", &x);
				__maxinsert(x, i);
				__mininsert(x, i);
				indeq[i][0] = indeq[i][1] = true;
				oq.push_back(i);
			}
			else if(strcmp(cmd, "POP") == 0 && oq.size() > 0)
			{
				__deqpop();
			}

			else if(strcmp(cmd, "MINUS") == 0 && oq.size() > 0)
			{
				swap(maxpos, minpos);

				for(int j = 0, len = deq[maxpos].size(); j < len; j++)
					deq[maxpos][j] = -deq[maxpos][j];

				for(int j = 0, len = deq[minpos].size(); j < len; j++)
					deq[minpos][j] = -deq[minpos][j];
			}
			// printf("MAX: ");
			// for(int i = 0, len = deqmax.size(); i < len; i++)
			// 	printf("%d ", deqmax[i]);
			// printf("\nMIN: ");
			// for(int i = 0, len = deqmin.size(); i < len; i++)
			// 	printf("%d ", deqmin[i]);
			// printf("\n");
		}

		if(ka != T) printf("\n");

	}



	return 0;
}