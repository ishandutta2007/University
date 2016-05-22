#include <bits/stdc++.h>

using namespace std;


char str[10];
int a[10];

int main()
{
	scanf("%s", str);
	int len = strlen(str);

	for (int i = 0; i < len; i++)
		a[i] = str[i] - '0';


	sort(a, a + len);
	do {
		for (int i = 0; i < len; i++)
			cout << a[i];
		cout << endl;
	} while(next_permutation(a, a + len));

	return 0;
}