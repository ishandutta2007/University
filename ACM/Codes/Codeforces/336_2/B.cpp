#include <bits/stdc++.h>

using namespace std;

char a[200200], b[200200];
int sb[200200];


int main()
{
	
	scanf("%s%s", a, b);
	int la = strlen(a), lb = strlen(b);
	for(int i = 0; i < lb; i++)
	{
		sb[i+1] = sb[i] + b[i] - '0';
	}
	
	// int ans = 0;
	long long ans = 0;
	for(int i = 0; i < la; i++)
	{
		int pre = i + 1, back = lb - (la - i - 1);
		if(a[i] == '0')
			ans += sb[back] - sb[pre-1];
		else
			ans += back - pre + 1 - sb[back] + sb[pre-1];
	}
	
	cout << ans << endl;
	
	return 0;
}

//10:07