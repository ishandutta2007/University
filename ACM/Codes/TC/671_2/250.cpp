#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class BearPaints
{
public:

	LL maxArea(LL W, LL H, LL M)
	{
		LL ans = 0;


		for(LL i = 1; i <= W; i++)
		{
			LL h = M / i;
			h = min(H, h);
			ans = max(ans, h * i);
		}
		return ans;
	}
};