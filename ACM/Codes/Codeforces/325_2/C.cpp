#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

struct Pa{
	LL v, d, p, id;
	Pa(){}
	Pa(LL v, LL d, LL p, LL id):v(v),d(d),p(p),id(id){}
};
vector<int> ans;

vector<Pa> update(int pos, vector<Pa> pa)
{
	vector<Pa> ret;
	ret.clear();
	int len = pa.size();
	LL tmp = pa[pos].d;


	while(++pos < len)
	{
		pa[pos].p -= tmp;
		if(pa[pos].p < 0)
			tmp += pa[pos].d;
	}
	for(int i = 0; i < len; i++)
	{
		if(pa[i].p >= 0)
			ret.push_back(pa[i]);
	}

	return ret;
}


int main()
{

	vector<Pa> pa;
	ans.clear();
	pa.clear();
	int n;
	scanf("%d", &n);
	int v, d, p;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &v, &d, &p);
		pa.push_back(Pa(v, d, p, i));
	}
	Pa now;
	LL len;
	while(pa.size() > 0)
	{
		now = pa[0];
		ans.push_back(now.id);
		pa.erase(pa.begin());
		len = pa.size();
		// printf("%d %d\n", len, now.v);

		// system("pause");

		for(int i = 0; i <= min(len, now.v); i++)
		{
			pa[i].p -= (now.v-i);
			if(pa[i].p < 0) pa[i].p = -1;
		}
		for(int i = 0; i < len; i++)
			if(pa[i].p < 0)
			{
				pa = update(i, pa);
				break;
			}
	}

	len = ans.size();
	printf("%I64d\n", len);
	for(int i = 0; i < len; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}