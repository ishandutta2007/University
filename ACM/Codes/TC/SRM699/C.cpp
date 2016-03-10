#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class LineMSTDiv2{
public:
	int calret(int mask, int n)
	{
		long long ret = 1;

		for(int i = 0; i < n; i++)
		{
			for(int j = i + 2; j < n; j++)
			{
				bool hasTwo = false;
				for(int k = i; k < j; k++)
					if(mask & (1<<k)) hasTwo = true;
				ret *= hasTwo == true? 1 : 2;
				ret %= 1000000007;
			}
		}
		return ret;
	}
	int count(int N)
	{
		long long ret = 0;

		for(int i = 0; i < (1<<(N - 1)); i++)
			ret = (ret + calret(i, N)) % 1000000007;

		for(int i = 3; i <= N; i++)
			ret = ret*i % 1000000007;
		return ret;
	}
}lmst;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		cout << lmst.count(n) << endl;
	}
	return 0;
}