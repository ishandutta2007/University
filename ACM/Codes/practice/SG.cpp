#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

using namespace std;


int sg[100][100];
vector<int> pri;



bool isprime(int x)
{
	for(int i = 2; i <= sqrt(x); i++)
		if(x % i == 0) return false;
	return true;
}

void init()
{
	for(int i = 2; i <= 1000; i++)
		if(isprime(i))
			pri.push_back(i);
}




int main()
{

	init();
	



	return 0;
}
