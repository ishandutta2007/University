#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

priority_queue< string ,vector<string>, greater<string> > pq;
// priority_queue< string > pq;

int n;

string combine(string a, string b)
{
	string tmp1 = a + b;
	string tmp2 = b + a;
	return min(tmp1, tmp2);
}


int main()
{
	cin >> n;
	string tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		pq.push(tmp);
	}

	// cout << pq.top() << endl;

	while(pq.size() > 1)
	{
		string tmp1 = pq.top();
		pq.pop();
		string tmp2 = pq.top();
		pq.pop();
		string tmp = combine(tmp1, tmp2);
		// cout << tmp << endl << endl;
		pq.push(tmp);
	}

	cout << pq.top() << endl;

	return 0;
}