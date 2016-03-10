#include <bits/stdc++.h>

using namespace std;

class PalindromePrime
{

public:

	bool prime(int x)
	{
		if(x == 1) return false;

		for(int i = 2, len = sqrt(x); i <= len; i++)
		{
			if(x % i == 0) return false;
		}
		return true;
	}

	bool pa(int x)
	{
		int tmp = x;
		int y = 0;
		while(tmp > 0)
		{
			y = y*10 + tmp % 10;
			tmp /= 10;
		}

		return x == y;
	}


	int count(int L, int R)
	{
		int ret = 0;



		for(int i = L; i <= R; i++)
		{
			if(prime(i) && pa(i))
				ret ++;
		}

		return ret;

	}
};