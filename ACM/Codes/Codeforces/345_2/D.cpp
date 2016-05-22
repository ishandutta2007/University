#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int n, a, b, T;
char str[500020];
int sum_left[500020];
int sum_right[500020];

int main()
{
	cin >> n >> a >> b >> T;
	scanf("%s", str);

	if(str[0] == 'w') T -= b;
	if(T <= 0) {
		cout << 0 << endl;
		return 0;
	}
	else T--;
	int ans = 1;

	for (int i = n-1; i > 0; i--) {
		sum_left[i] = sum_left[i+1] + a + 1;
		if(str[i] == 'w') sum_left[i] += b;
		if(sum_left[i] <= T) ans = max(ans, n-i+1);
		// printf("left[%d] = %d\n", i, sum_left[i]);
	}

	for (int i = 1; i < n; i++) {
		sum_right[i] = sum_right[i-1] + a + 1;
		if(str[i] == 'w') sum_right[i] += b;
		if(sum_right[i] <= T) ans = max(ans, i + 1);
		// printf("right[%d] = %d\n", i, sum_right[i]);
	}

	int left = 1;
	for (int i = 1; i < n; i++) {
		while(sum_left[left] + sum_right[i] + min(i*a, (n-left)*a) > T && left <= n) left++;

		if(n - left + i + 1 > ans && sum_left[left] + sum_right[i] + min(i*a, (n-left)*a) <= T && left <= n) {
			// cout << left << "  " << i << endl;
			ans = max(ans, n - left + i + 1);
		}

	}

	// int right = 1;
	// for (int i = n - 1; i >= 0; )

	cout << min(ans, n) << endl;
	return 0;
}