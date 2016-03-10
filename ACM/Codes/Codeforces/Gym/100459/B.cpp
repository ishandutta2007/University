#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<int ,int>mp;
int n, d;
long long ans;
int main()
{
	scanf("%d%d", &n, &d);
	ans = 0;
	int x;
	int pos;
	int pre = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		int tmp = x + d;
		pos = 0;
		if(mp.find(tmp) != mp.end())
		{
			pos = max(pos, mp[tmp]);
			pre = max(pos, pre);
		}
		tmp = x - d;
		if(mp.find(tmp) != mp.end())
		{
			pos = max(pos, mp[tmp]);
			pre = max(pre, pos);
		}
		if(pos < n) ans += max(pos, pre);
		mp[x] = i;
	}

	cout << ans << endl;

	return 0;
}