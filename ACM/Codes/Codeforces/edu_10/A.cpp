#include <bits/stdc++.h>
using namespace std;

int h1, h2, a, b;


int main()
{
	cin >> h1 >> h2 >> a >> b;


	h1 += a * 8;

	if(h1 >= h2) {
		cout << 0 << endl;
		return 0;
	}
	
	if(a <= b)  {
		cout << -1 << endl;
		return 0;
	}

	int delta = h2 - h1;
	int v = (a - b) * 12;

	if(delta % v == 0)
		cout << delta / v << endl;
	else
		cout << delta / v + 1 << endl;



	return 0;
}