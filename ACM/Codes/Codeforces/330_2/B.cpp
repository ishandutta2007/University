#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;


int a[100020], b[100020];
int n, k;
const int mod = 1000000007;
int ALL = 1;
typedef long long  LL;


int calcnt(int a, int b)
{

	if(a < 0) return 0;
	// cout << a << " " << b << "ret" ;
	a = a - a % b;

	// cout << a / b + 1 << endl;

	return a / b + 1;
}


int cal(int a, int b)
{
	int res = ALL;
	int all = ALL;
	res -= all / 10;
	res -= all - calcnt(all - 1, a);




	int high = all / 10 * b;

	int tmp = calcnt(high - 1 + all/10, a) - calcnt(high - 1, a);

	//cout << tmp << endl;

	res += all/10 - tmp;

	//cout << res << endl;
	return res;
}


int main()
{


	scanf("%d%d", &n, &k);
	int cnt = n / k;


	for(int i = 0; i < k; i++) ALL *= 10;

	for(int i = 0; i < cnt; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < cnt; i++)
		scanf("%d", &b[i]);


	LL ans = 1;

	for(int i = 0; i < cnt; i++)
	{
		ans = (ans * cal(a[i], b[i])) % mod;
		//cout << ans << endl;
	}

	printf("%I64d\n", ans);


	return 0;
}