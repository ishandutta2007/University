#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define p 1000000007
#define maxn 1001
using namespace std;

typedef long long llg;

llg Pow(llg a,llg k)
{
	llg tmp=1;
	while (k)
	{
		if (k&1) tmp=tmp*a%p;
		k=k/2;
		a=a*a%p;
	}
	return tmp;
}


int C[maxn][maxn];
int f[maxn];

// int main()
// {
//     int n;
// 	while(cin >> n)
// 	{
// 		for (int i = 1; i <= n; i++)
// 	    {
// 	        C[i][0] = C[i-1][i-1] = 1;
// 	        for (int j = 1; j < i; j++)
// 	            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
// 	    }
// 		cout << C[n][n-1] << endl;
// 	}
// 	return 0;

// }
int main()
{
    for (int i = 0; i < maxn; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
    }
    f[0] = 1;
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j <= i; j++)
            f[i] = (f[i] + 1LL * C[i - 1][j - 1] * f[i - j]) % p;

    int n, ans;
    while (cin >> n)
    {
        ans = 0;
        for (int i = 0; i < n; i++)
            ans = (ans + 1LL * C[n][i] * f[i]) % p;
        cout << ans << endl;
    }
}