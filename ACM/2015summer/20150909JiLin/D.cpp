#include <cstdio>
#include <iostream>


using namespace std;

int main()
{

	int T;
	cin >> T;

	long long n;
	while(T--)
	{
		cin >> n;
		cout << (2*n-1)*(2*n-1) - 1 + 5*n << endl;
	}



	return 0;
}
