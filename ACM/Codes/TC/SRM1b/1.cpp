#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;


class Time
{
public:

	string whatTime(int seconds)
	{
		int h = seconds / 3600;
		int m = (seconds % 3600) / 60;
		int s = (seconds % 60);
		stringstream ret;
		ret.clear();

		ret << h << ':' << m << ':' << s;
		return ret.str();
	}
};




int main()
{

	Time time;
	int t;
	while(scanf("%d", &t))
	{
		cout << time.whatTime(t) << endl;
	}
	return 0;
}