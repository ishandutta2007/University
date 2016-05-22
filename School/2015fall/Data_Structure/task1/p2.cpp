/*
 *	有一个包括100个元素的数组，每个元素的值都是
 *	实数，请写出求最大元素的值及其位置的算法，
 *  讨论它可能采取的存储结构。
 */


#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>


using namespace std;

pair<int , double> findmax(vector<double> v)
{
	int pos = 0;
	double m = v[0];
	for(int i = 1, l = v.size(); i < l; i++)if(m < v[i])
	{
		pos = i;
		m = v[i];
	}
	return make_pair(pos + 1, m);
}




int main()
{
	int n;
	printf("Input array size\n");
	scanf("%d", &n);
	vector<double> v;
	printf("Input %d numbers\n", n);
	double tmp;
	for(int i = 0; i < n;i++)
	{
		scanf("%lf", &tmp);
		v.push_back(tmp);
	}
	pair<int , double> PID = findmax(v);
	printf("The max value %f appears at position %d\n",PID.second, PID.first);
	return 0;
}