#include <bits/stdc++.h>

using namespace std;


char mp[100][100];
int ans[100][100][120];
int mx[4] = {0, 0, -1, 1};
int my[4] = {-1, 1, 0, 0};

class BoardEscapeDiv2
{
public:
	string findWinner(vector <string> s, int k)
	{
		int n = s.size();
		int m = s[0].size();

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				mp[i][j] = s[i][j];

		memset(ans, 0, sizeof(ans));
		for(int ka = 1; ka <= k; ka++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if(mp[i][j] == 'E')
					{
						ans[i][j][ka] = 0;
					}
					else if(mp[i][j] == '.' || mp[i][j] == 'T')
					{
						ans[i][j][ka] = 1;
						int tmpx, tmpy;
						for(int ii = 0; ii < 4; ii++)
						{
							tmpx = i + mx[ii];
							tmpy = j + my[ii];
							if(tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m && (mp[tmpx][tmpy] == '.' || mp[tmpx][tmpy] == 'T' || mp[tmpx][tmpy] == 'E'))
							{
								ans[i][j][ka] = min(ans[i][j][ka], ans[tmpx][tmpy][ka-1]);
							}
						}

						if(ans[i][j][ka] == 1) ans[i][j][ka] = 0;
						else ans[i][j][ka] = 1;
					}
				}
			}
		}

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(mp[i][j] == 'T')
					return ans[i][j][k] == 1? "Alice" : "Bob";


	}
};

int main()
{
	return 0;
}