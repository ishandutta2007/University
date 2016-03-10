#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;


typedef long long LL;



map<string,string> varb;
map<string, int> tpid;
map<int , string> rev;
bool trans[520][520];
int depth;
int I;
int n, m;
char str[500020];
int now, len;
int solve()
{
	string tmp;
	tmp.clear();

	int pretp = -1;
	int nowtp = -1;
	int nextp = -1;
	for(; I < len; I++)
	{

		// printf("III : %d %d %d\n",I, pretp , nowtp);

		if(str[I] >= 'a' && str[I] <= 'z')
		{
			tmp.push_back(str[I]);
			continue;
		}

		if(str[I] == '*')
		{
			if(varb.find(tmp) == varb.end())
				return -1;
			nowtp = tpid[varb[tmp]];
			// cout << "nowtp " << nowtp << endl;
			tmp.clear();
			if(pretp == -1)
			{
				pretp = nowtp;
			}

			if(trans[nowtp][pretp] == 0)
			{
				return -1;
			}
		}

		else if(str[I] == ')')
		{
			if(depth <= 0) return -1;
			depth--;

			if(I > 0 && str[I-1] == ')')
			{
				nowtp = pretp;
			}
			else if(varb.find(tmp) == varb.end())
				return -1;
			
			else
				nowtp = tpid[varb[tmp]];
			tmp.clear();
			if(pretp == -1)
				pretp = nowtp;
			// cout << ")))" << pretp << " " << nowtp  << endl;

			if(trans[nowtp][pretp] == 0)
				return -1;
			return pretp;
		}

		else if(str[I] == '(')
		{
			if(tpid.find(tmp) == tpid.end())
				return -1;

			nowtp = tpid[tmp];
			tmp.clear();
			
			depth++;
			I++;
			nextp = solve();
			// cout << now << " " << nextp << endl;
			// cout << pretp << " " << nowtp << " " << nextp << "dep" << depth<<  endl;
			if(nextp == -1)
				return -1;


			if(pretp == -1)
				pretp = nowtp;

			if(trans[nowtp][pretp] == 0)
				return -1;
			if(trans[nextp][pretp] == 0)
				return -1;
			nowtp = nextp = -1;
			// cout << "!" << pretp << endl;
		}

	}


	if(tmp.length() > 0)
	{
		if(varb.find(tmp) == varb.end())
			return -1;
		nowtp = tpid[varb[tmp]];

		if(pretp == -1)
			pretp = nowtp;

		if(trans[nowtp][pretp])
			return pretp;
		return -1;
	}

	if(str[len-1] == '*') return -1;

	return pretp;

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
			trans[i][i] = true;
			int tmp;
			tpid[t1] = i;
			rev[i] = t1;
			while(cnt--)
			{
				cin >> tmp;
				trans[i][tmp] = true;
			}
		}

		scanf("%s", str);

		len = strlen(str);

		now = 0;
		I = 0;

		int id = solve();
		depth = 0;


		// cout << "main " << depth << " " << id << endl;

		// cout << tpid["int"] << endl;
		if(id == -1 || depth != 0)
		{
			printf("-1\n");
		}
		else
		{
			cout << rev[id] << endl;
		}

	}
	return 0;
}