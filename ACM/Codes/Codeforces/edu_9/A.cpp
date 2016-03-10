#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;

typedef long long LL;


int n, p;
vector<int> vi;


int main()
{
	cin >> n >> p;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vi.push_back(tmp.length());
	}

	LL ans = 0;
	LL rest = 0;
	
	// cout << ans << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		if (vi[i] == 8) {
			ans += p * rest + p / 2;
			rest = rest * 2 + 1;
		}
		else {
			ans += p * rest;
			rest = rest * 2;
		}
		// cout << ans << endl;
	}

	cout << ans << endl;
	return 0;
}