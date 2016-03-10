#include <bits/stdc++.h>
using namespace std;

int a[100020], f[100020][4][3];
char s[100020];
const int unflip = 0, fliplast = 1, flipped = 2;

int main()
{
	int n;
	char x;
	scanf("%d", &n);
	scanf("%s", s);
	for(int i = 1; i <= n; i++)
	{
		a[i] = s[i-1]-'0';
	}
	// cout << a[1] << endl;
	f[1][unflip][a[1]] = 1;
	f[1][fliplast][a[1]^1] = 1;
	// cout << f[1][unflip][0] << ' ' << f[1][unflip][1] << endl;
	// cout << f[1][fliplast][0] << ' ' << f[1][fliplast][1] << endl;
	// cout << f[1][flipped][0] << ' ' << f[1][flipped][1] << endl;
	// cout << "---------------------------" << endl;

	for(int i = 2; i <= n; i++)
	{
		if(a[i] == 1)
		{
			f[i][unflip][a[i]] = max(f[i-1][unflip][a[i]], f[i-1][unflip][1^a[i]] + 1);
			f[i][unflip][1^a[i]] = f[i-1][unflip][1^a[i]];

			f[i][fliplast][0] = max(f[i-1][unflip][1], f[i-1][fliplast][1]) + 1;
			f[i][fliplast][1] = max(f[i-1][unflip][1], f[i-1][fliplast][1]);

			if(f[i-1][flipped][0] > 0) f[i][flipped][1] = f[i-1][flipped][0] + 1;
			else f[i][flipped][1] = f[i-1][flipped][1];
			f[i][flipped][0] = max(f[i-1][flipped][0], f[i-1][fliplast][0]);
			f[i][flipped][1] = max(f[i][flipped][1], f[i-1][fliplast][0] + 1);

		}
		else
		{
			f[i][unflip][a[i]] = max(f[i-1][unflip][a[i]], f[i-1][unflip][1^a[i]] + 1);
			f[i][unflip][1^a[i]] = f[i-1][unflip][1^a[i]];

			f[i][fliplast][1] = max(f[i-1][unflip][0], f[i-1][fliplast][0]) + 1;
			f[i][fliplast][0] = max(f[i-1][unflip][0], f[i-1][fliplast][0]);

			if(f[i-1][flipped][1] > 1) f[i][flipped][0] = f[i-1][flipped][1] + 1;
			else f[i][flipped][0] = f[i-1][flipped][0];
			f[i][flipped][1] = max(f[i-1][flipped][1],f[i-1][fliplast][1]);
			f[i][flipped][0] = max(f[i][flipped][0], f[i-1][fliplast][1] + 1);

		}
		
		// cout << f[i][unflip][0] << ' ' << f[i][unflip][1] << endl;
		// cout << f[i][fliplast][0] << ' ' << f[i][fliplast][1] << endl;
		// cout << f[i][flipped][0] << ' ' << f[i][flipped][1] << endl;
		// cout << "---------------------------" << endl;

	}


	cout << max(max(f[n][fliplast][0],f[n][fliplast][1]), max(f[n][flipped][0],f[n][flipped][1])) << endl;
	return 0;
}