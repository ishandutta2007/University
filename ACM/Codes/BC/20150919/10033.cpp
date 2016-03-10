#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;


typedef long long LL;



map<string,string> varb;
map<string, int> tpid;
map<int , string> rev;
bool trans[520][520];

deque<int>deq;



int n, m;
char str[500020];
int now, len;


int solve()
{

	string tmp;
	int pre = -1, now = -1, nex = -1;
	deq.clear();
	tmp.clear();
	for(int i = 0, len = strlen(str); i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			tmp.push_back(str[i]);
			continue;
		}

		else if(str[i] == '*')
		{
			if(varb.find(tmp) == varb.end())
				return -1;


			now = tpid[varb[tmp]];
			if(pre == -1)
			{
				pre = now;
				now = -1;
				continue;
			}

			else if(!trans[now][pre])
			{
				return -1;
			}

			else
			{
				now = -1;
			}

		}


		else if(str[i] == '(')
		{
			
		}
		else if(str[i] == ')')
		{
			

		}

	}
}


int main()
{

	int T, cnt;
	cin >> T;
	string t1, t2;
	while(T--)
	{
		varb.clear();
		tpid.clear();
		rev.clear();
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> t1 >> t2;
			varb[t1] = t2;
		}

		cin >> m;
		memset(trans, 0, sizeof(trans));

		for(int i = 1; i <= m; i++)
		{
			cin >> t1 >> cnt;
			trans[i][i] = 1;
			int tmp;
			tpid[t1] = i;
			rev[i] = t1;
			while(cnt--)
			{
				cin >> tmp;
				trans[i][tmp] = 1;
			}
		}

		scanf("%s", str);


		int ans = solve();


	}
	return 0;
}