#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int stk[80020];
int n, top;

int main()
{

	cout << INT_MAX << endl;

	scanf("%d", &n);
	int data;
	long long ans = 0;
	top = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &data);

		while(top > 0 && stk[top-1] <= data)
		{
			top--;
		}

		stk[top++] = data;

		ans += top - 1;
	}

	cout << ans << endl;

	return 0;
}