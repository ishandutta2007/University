#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<char, char> PCC;


map<PCC, int> mp;



char ss[1020];


PCC cal()
{
	vector<char> vc;
	vc.clear();
	int vis[26] = {0};
	int len = strlen(ss);
	for(int i = 0; i < len; i++)
		vis[ss[i] - 'a'] = 1;
	for(int i = 0; i < 26; i++)
	{
		if(vis[i] == 1)
		{
			vc.push_back(i+'a');
		}
	}
	int sz = vc.size();
	if(sz > 2) return make_pair('#','#');
	if(sz == 2)
	{
		return make_pair(vc[0], vc[1]);
	}
	return make_pair(vc[0], '#');
}




int main()
{


	for(char i = 'a'; i <= 'z'; i++)
	{
		for(char j = i; j <= 'z'; j++)
		{
			PCC tmp = make_pair(i, j);
			mp[tmp] = 0;
		}
	}

	int n;
	scanf("%d", &n);
	int len;
	PCC tmp;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%s", ss);
		len = strlen(ss);
		tmp = cal();


		//printf("%c %c\n", tmp.first, tmp.second);
		if(tmp.first != '#')
		{
			if(tmp.second != '#')
			{
				mp[tmp] += len;
				ans = max(mp[tmp], ans);
			}
			else
			{
				for(int j = 0; j < 26;j++)
				{
					PCC ttmp = tmp;
					ttmp.second = j + 'a';
					if(ttmp.first > ttmp.second) swap(ttmp.first, ttmp.second);
					//printf("%c %c\n", ttmp.first, ttmp.second);

					mp[ttmp] += len;
					ans = max(ans, mp[ttmp]);
				}
			}
		}
	}	

	printf("%d\n", ans);
	return 0;
}