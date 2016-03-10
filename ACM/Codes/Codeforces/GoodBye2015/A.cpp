#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	string tmp, str;
	int x;
	
	cin >> x >> tmp >> str;
	
	
	if(str == "week")
	{
		if(x == 5 || x == 6)
			printf("53\n");
		else
			printf("52\n");
	}
	
	else
	{
		int ans = 0;
		if(x <= 29) ans = 12;
		else if(x <= 30) ans = 11;
		else ans = 7;
		printf("%d\n", ans);
	}
	
	
	return 0;
}