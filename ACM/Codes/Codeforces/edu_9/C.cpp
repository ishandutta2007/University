#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> vs;
int n;

bool cmp(string a, string b)
{
	return a + b < b + a;
}

int main()
{
	cin >> n;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vs.push_back(tmp);
	}

	sort(vs.begin(), vs.end(), cmp);


	for (int i = 0; i < n; i++)
		cout << vs[i];
	cout << endl;

	return 0;
}