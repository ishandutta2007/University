#include <bits/stdc++.h>

using namespace std;


typedef long long LL;


priority_queue< LL, vector<LL> , greater<LL> >q;
map<LL, int> mp;

int main()
{


	q.push(1);
	mp[1] = true;


	for(int i = 1; i <= 1500; i++)
	{
		if(i == 1500)
		{
			cout << "The 1500'th ugly number is " << q.top() << "." << endl;
		}

		else
		{
			LL tmp = q.top();
			q.pop();
			if(mp.find(tmp*2) == mp.end()) q.push(tmp*2),mp[tmp*2] = 1;
			if(mp.find(tmp*3) == mp.end()) q.push(tmp*3),mp[tmp*3] = 1;
			if(mp.find(tmp*5) == mp.end()) q.push(tmp*5),mp[tmp*5] = 1;
		}

	}

	return 0;
}