#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


typedef long long LL;

class BearPaints{
public:
	LL maxArea(LL W, LL H, LL M)
	{
		if(W > H) swap(W, H);

		LL ans = 0;
		for(LL i = 1, len = min(W, M); i <= len; i++)
		{
			LL h = min(H, M / i);
			ans = max(ans, h * i);
		}

		return ans;
	}


};



int main()
{




	return 0;
}