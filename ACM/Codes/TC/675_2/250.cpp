#include <bits/stdc++.h>

using namespace std;


map<string, int> mp;


class LengthUnitCalculator
{
public:
	double calc(int amount, string fromUnit, string toUnit)
	{
		mp["in"] = 1;
		mp["ft"] = 12;
		mp["yd"] = 36;
		mp["mi"] = 63360;


		amount *= mp[fromUnit];


		return amount*1.0 / mp[toUnit];

	}
};