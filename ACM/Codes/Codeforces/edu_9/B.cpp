#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;

typedef long long LL;

string str;
LL a[1000000];
LL sum;
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	cin >> str;

	for(int i = 0; i < n; i++)
	{
		if(str[i] == 'A') a[i+1] *= -1;
		else sum += a[i+1];
	}
	LL ans = sum;
	LL tmp = 0;
	for(int i = 1; i <= n; i++)
	{
		tmp += a[i];
		if(sum - tmp > ans) ans = sum - tmp;
	}

	tmp = 0;
	for(int i = n; i > 0; i--)
	{
		tmp += a[i];
		if(sum - tmp > ans) ans = sum - tmp;
	}
	cout << ans << endl;
	return 0;
}