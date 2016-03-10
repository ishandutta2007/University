#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;


struct Hand{
	int wind[10];
	int stk[10];
	int num[10];
	int ball[10];
	int color[10];
	void clear()
	{
		memset(wind, 0, sizeof(wind));
		memset(stk, 0, sizeof(stk));
		memset(num, 0, sizeof(num));
		memset(ball, 0, sizeof(ball));
		memset(color, 0, sizeof(color));
	}
	void insert(char s[5])
	{
		if(s[0] > '0' && s[0] <= '9')
		{
			int a = s[0] - '0';
			if(s[1] == 'N') num[a] ++;
			else if(s[1] == 'S') stk[a] ++;
			else ball[a] ++;
		}
		else if(s[0] >= 'A' && s[0] <= 'Z')
		{
			if(s[0] == 'E') wind[0]++;
			else if(s[0] == 'S') wind[1]++;
			else if(s[0] == 'W') wind[2]++;
			else wind[3]++;
		}
		else
		{
			if(s[0] == 'r') color[0]++;
			else if(s[0] == 'w') color[1]++;
			else color[2]++;
		}
	}

	bool check()
	{
		for(int i = 0; i < 4; i ++)if(wind[i] >= 2)
		{
			int tmp = wind[i];
			wind[i] = 0;
			if(_4set()) return true;
			if(_12one(i)) return true;
			wind[i] = tmp;
		}
		return false;
	}

	int calslash(int a[10])
	{
		int tmp[10] = {0};
		for(int i = 0; i < 10; i++)
			tmp[i] = a[i];
		int ret = 0;
		for(int i = 1; i + 2 <= 9; i++)
		{
			if(tmp[i] && tmp[i+1] && tmp[i+2])
			{
				ret ++;
				tmp[i]--;
				tmp[i+1]--;
				tmp[i+2]--;
			}
		}
		return ret;
	}
	int calset(int a[10])
	{
		
		int tmp[10], tmp1[10] = {0};
		vector<int> pos;
		pos.clear();
		for(int i = 0; i < 10; i++)
		{
			tmp[i] = a[i];
			if(tmp[i] >= 3)
				pos.push_back(i);
		}


		int ret = pos.size();
		if(ret >= 4) return ret;


		else if(pos.size() == 0)
		{
			return calslash(tmp);
		}
		else if(pos.size() == 1)
		{
			tmp[pos[0]] -= 3;
			ret += calslash(tmp);
			tmp[pos[0]] += 3;
			ret = max(ret, calslash(tmp));
		}
		else if(pos.size() == 2)
		{
			for(int i = 0; i < 2; i++)
				tmp[pos[i]] -= 3;
			ret += calslash(tmp);

			for(int i = 0; i < 2; i++)
			{
				for(int j = 0; j < 10; j++)
					tmp1[j] = tmp[j];

				tmp1[i] += 3;
				ret = max(ret, 1 + calslash(tmp1));
			}
			ret = max(ret, calslash(a));
		}
		else
		{
			ret = max(ret, calslash(a));
			for(int i = 0; i < 3; i++)
				tmp[pos[i]] -= 3;
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 10; j++)
					tmp1[j] = tmp[j];
				tmp1[pos[i]] += 3;
				ret = max(ret, 2 + calslash(tmp1));
			}

			for(int i = 0; i < 6; i++)
			{
				for(int j = 0; j < 10; j++)
					tmp1[j] = tmp[j];
			}
		}
		return max(ret, calslash(a));
	}

	bool _4set()
	{
		int cnt = 0;
		for(int i = 0; i < 4; i++)
		{
			if(wind[i] >= 3) cnt++;
			if(color[i] >= 3) cnt++;
		}

		cnt += calset(ball) + calset(stk) + calset(num);

		if(cnt >= 4) return true;
		return false;
	}

	bool _12one(int dtp)
	{
		int cnt = 0;
		for(int i = 0; i < 4; i++)
		{
			if(wind[i] > 0) cnt++;
			if(color[i] > 0) cnt++;
		}
		if(ball[1] > 0) cnt++;
		if(ball[9] > 0) cnt++;
		if(stk[1] > 0) cnt++;
		if(stk[9] > 0) cnt++;
		if(num[1] > 0) cnt++;
		if(num[9] > 0) cnt++;
		if(cnt == 12) return true;
		return false;
	}
}hd[5];


char ss[200][5];
char name[4][20] = {"Takakamo Shizuno", "Matsumi Kuro"};


int main()
{

	int n;
	scanf("%d", &n);

	for(int ka = 1; ka <= n; ka++)
	{
		for(int i = 0; i < 138; i++)
			scanf("%s", ss[i]);




	}




	return 0;
}

