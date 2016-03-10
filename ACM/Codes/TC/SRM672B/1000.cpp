#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;


int vis[20];
deque<int> deq;


class Tdetectived2
{
public:
	int reveal(vector <string> s)
	{
		int ans[20] = {0};
		deq.clear();
		deq.push_back(0);
		int found = 0;
		int now, tmp;
		while(!deq.empty())
		{
			now = deq.front();
			deq.pop_front();
			if(vis[now] == 1)
			{
				continue;
			}

		}


	}
};
