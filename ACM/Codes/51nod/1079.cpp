#include <bits/stdc++.h>
using namespace std;

typedef long long LL;


void EXT_GCD(LL a, LL b, LL &d, LL &x, LL &y)
//a , b 任意
{
	 if(!b) {d = a, x = 1, y = 0;}
	 else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}
LL CRT(LL *a, LL *m, int n)
//中国剩余定理
//x ≡ a[i] (mod m[i])
//m[i] is coprime
{
	LL M = 1, Mi, x0, y0, d, ret = 0;
	for(int i = 0; i < n; i++)
		M *= m[i];
	for(int i = 0; i < n; i++)
	{
		Mi = M/m[i];
		EXT_GCD(Mi, m[i], d, x0, y0);
		ret = (ret+Mi*x0*a[i]) % M;
	}
	if(ret < 0)
		ret += M;
	return ret;
}

LL arr1[20], arr2[20];


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &arr1[i], &arr2[i]);

	cout << CRT(arr2, arr1, n) << endl;

	return 0;
}