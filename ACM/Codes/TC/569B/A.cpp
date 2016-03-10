#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class TheJediTestDiv2
{
public:
	int countSupervisors(vector<int> students, int Y, int J)
	{
		int simple[60] = {0}, sum[60] = {0};
		int n = students.size();

		for(int i = 0; i < n; i++)
		{
			simple[i+1] = ceil(students[i]*1.0 / J);
			sum[i+1] = simple[i+1] + sum[i];
		}

		int ret = sum[n];

		for(int i = 1; i <=n ; i++)
		{
			ret = min(ret, sum[n] - simple[i] + (int)ceil(max(students[i-1]-Y, 0)*1.0 / J));
		}


		return ret;
	}

};



int main()
{



	return 0;
}