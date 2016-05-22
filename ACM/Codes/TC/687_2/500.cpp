#include <bits/stdc++.h>

using namespace std;

class Quacking
{
public:
	int state[6];
	map<char, int> dict;
	int quack(string s)
	{
		int len = s.length();
		memset(state, 0, sizeof(state));
		dict['q'] = 0;
		dict['u'] = 1;
		dict['a'] = 2;
		dict['c'] = 3;
		dict['k'] = 4;
		int ans = 0, st;
		for (int i = 0; i < len; i++)
		{
			st = dict[s[i]];
			if(state[st] == 0)
			{
				if(st != 0)	return -1;
				ans++;
				state[(st+1) % 5]++;
			}
			else
			{
				state[st] --;
				state[(st+1) % 5]++;
			}
		}

		for (int i = 1; i < 5; i++)
			if(state[i]) return -1;

		return ans;

	}
};