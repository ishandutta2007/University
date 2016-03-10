#include <cstdio>
#include <iostream>


using namespace std;


int r[20];
int ans;
int a[100020];
int rr;

int main()
{


	int n, k, x;
	scanf("%d%d",&n, &k);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &x);


		if(x % 10 > 0)
		{
			r[x%10]++;
			x = x/10+1;
			ans += x-1;
		}

		else
		{
			x = x/10;
			ans += x;
		}
		rr += 10 - x;
	}



	// cout << r[2] << endl;
	// cout << rr << endl;


	for(int i = 9; i >= 1; i--)
	{
		if(r[i] * (10-i) >= k)
		{
			ans += k / (10-i);
			k %= (10-i);
			break;
		}

		else
		{
			ans += r[i];
			k -= r[i] * (10-i);
 		}
	}


	if(k)
	{
		ans += min(rr, k/10);
	}

	printf("%d\n", ans);

	return 0;
}
