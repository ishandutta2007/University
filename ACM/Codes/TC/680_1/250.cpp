#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


class BearFair
{
public:
	string isFair(int n, int b, vector <int> upTo, vector <int> quantity)
	{
		upTo.push_back(0);
		quantity.push_back(0);
		upTo.push_back(b);
		quantity.push_back(n);
		n++;
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j < n - i; j++)if(upTo[j] > upTo[j+1])
			{
				swap(upTo[j], upTo[j+1]);
				swap(quantity[j], quantity[j+1]);
			}
		}

		int even = 0, odd = 0;
		for(int i = 1; i <= n; i++)
		{
			int tmpeven = 0;
			int tmpodd = 0;
			int low = upTo[i-1] + 1, high = upTo[i];
			int mmin = quantity[i] - quantity[i-1];
			if(mmin < 0) return "unfair";
			if(high - low + 1 < mmin) return "unfair";

			for(int j = low; j <= high; j++)
			{
				if(j % 2 == 0) tmpeven++;
				else tmpodd++;
			}
			
			even += min(mmin, tmpeven);
			odd += min(mmin, tmpodd);

		}

		int cnt = (n-1) / 2;
		if(even >= cnt && odd >= cnt) return "fair";
		else return "unfair";
	}

};

int main()
{
	return 0;
}