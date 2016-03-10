#include <bits/stdc++.h>
using namespace std;


class PlaneGame
{
public:
	int bestShot(vector <int> x, vector <int> y)
	{
		int n = x.size();
		if(n <= 3) return n;
		int ret = 3;
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				int xn = x[i]-x[j], yn = y[i]-y[j];
				for(int k = 0; k < n; k++)if(k != i && k != j)
				{
					int tmp = 0;
					for(int ii = 0; ii < n; ii++)
					{
						int xi = x[i]-x[ii],yi = y[i]-y[ii];
						int xj = x[j]-x[ii],yj = y[j]-y[ii];
						int xt = x[k]-x[ii],yt = y[k]-y[ii];
						if(xi*yj-xj*yi == 0 || xn*xt+yn*yt == 0)
							tmp++;
					}
					ret = max(tmp, ret);
				}
			}
		}
		return ret;
	}
};