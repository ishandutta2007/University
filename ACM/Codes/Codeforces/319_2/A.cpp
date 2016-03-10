#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>


using namespace std;



int main()
{
	int x, n;

	scanf("%d%d",&n,&x);


	if(n > x) n = x;

	long long ans = 0;

	for(int i = 1; i <= n; i++)
		if(x % i == 0 && x / i <= n)
			ans ++;


	// int tmp = sqrt(x);
	// if(tmp * tmp == x) ans--;

	cout << ans << endl;

	return 0;
}