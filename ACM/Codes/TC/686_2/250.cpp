#include <bits/stdc++.h>
using namespace std;

class TreeAndVertex
{
public:
	int cnt[200];
	int ans = 0;
	int get(vector <int> tree)
	{
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0, len = tree.size(); i < len; i++)
		{
			cnt[i+1] ++;
			cnt[tree[i]]++;
			ans = max(ans, cnt[i+1]);
			ans = max(ans, cnt[tree[i]]);
		}
	}
	return ans;
};
