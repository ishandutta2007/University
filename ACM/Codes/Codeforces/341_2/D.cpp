#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

double x, y, z;
double ans = -1000000000000.0;

double a1()
{
	// cout << z*log(y) + log(x) << endl;
	return z*log(y) + log(x);
}

double a2()
{
	// cout << y*log(z) + log(x) << endl;
	return y*log(z) + log(x);
}
double a3()
{
	// cout << z*y*log(x) << endl;
	return log(z*y*log(x));
}
double a5()
{
	// cout << z*log(x) + log(y) << endl;
	return z*log(x) + log(y);
}
double a6()
{
	// cout << x*log(z) + log(y) << endl;
	return x*log(z) + log(y);
}
double a7()
{
	// cout << z*x*log(y) << endl;
	return log(z*x*log(y));
}
double a9()
{
	// cout << y*log(x) + log(z) << endl;
	return y*log(x) + log(z);
}
double a10()
{
	// cout << x*log(y) + log(z) << endl;
	return x*log(y) + log(z);
}
double a11()
{
	// cout << y*x*log(z) << endl;
	return log(y*x*log(z));
}

int main()
{
	cin >> x >> y >> z;
	cout << x << y << z << endl;
	int id = 0;
	if(ans < a1())
	{
		id = 1;
		ans = a1();
	}
	if(ans < a2())
	{
		id = 2;
		ans = a2();
	}
	if(ans < a3())
	{
		id = 3;
		ans = a3();
	}
	if(ans < a5())
	{
		id = 5;
		ans = a5();
	}
	if(ans < a6())
	{
		id = 6;
		ans = a6();
	}
	if(ans < a7())
	{
		id = 7;
		ans = a7();
	}
	if(ans < a9())
	{
		id = 9;
		ans = a9();
	}
	if(ans < a10())
	{
		id = 10;
		ans = a10();
	}
	if(ans < a11())
	{
		id = 11;
		ans = a11();
	}
	cout << x << y << z << endl;
	if(id == 1) cout << "x^y^z" << endl;
	if(id == 2) cout << "x^z^y" << endl;
	if(id == 3) cout << "(x^y)^z" << endl;
	if(id == 5) cout << "y^x^z" << endl;
	if(id == 6) cout << "y^z^x" << endl;
	if(id == 7) cout << "(y^x)^z" << endl;
	if(id == 9) cout << "z^x^y" << endl;
	if(id == 10) cout << "z^y^x" << endl;
	if(id == 11) cout << "(z^x)^y" << endl;

	return 0;
}