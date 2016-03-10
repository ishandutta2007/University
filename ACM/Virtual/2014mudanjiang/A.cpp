#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;


int N, M;
int sum1, sum2;

int main()
{


	int T;
	cin >> T;

	int mmax, mmin;

	while(T--)
	{
		cin >> N >> M;
		sum1 = sum2 = 0;
		mmax = 100;
		mmin = 0;
		int tmp;
		for(int i = 1; i < N; i++)
		{
			cin >> tmp;
			sum1 += tmp;
		}
		for(int i = 1; i <= M; i++)
		{
			cin >> tmp;
			sum2 += tmp;
		}

		int avg = sum1 / (N-1);

		mmax = sum1 / (N-1);


		if(mmax * (N-1) == sum1)
			mmax--;


		avg = sum2 / M;


		mmin = ceil(1.0*sum2 / M);
		if(mmin * M == sum2)
			mmin ++;


		cout << mmin << " " << mmax << endl;
	}

	return 0;
}