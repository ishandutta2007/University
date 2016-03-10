#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


map<char ,char> mp;
bool v1[30], v2[30];

class SubstitutionCipher
{
public:
	string decode(string a, string b, string y)
	{
		mp.clear();
		int len = a.length();
		for(int i = 0; i < len; i++)
		{
			mp[b[i]] = a[i];
			v1[a[i]-'A'] = true;
			v2[b[i]-'A'] = true;
		}


		if(mp.size() == 25)
		{
			int p1 , p2;
			for(p1 = 0; p1 < 26; p1++)
				if(v1[p1] == 0) break;
			for(p2 = 0; p2 < 26; p2++)
				if(v2[p2] == 0) break;
			mp[p2+'A'] = p1+'A';
		}

		bool found = true;

		len = y.length();
		string res;
		res.clear();
		for(int i = 0; i < len;i++)
		{
			if(mp.find(y[i]) == mp.end())
			{
				found = false;
				break;
			}
			res.push_back(mp[y[i]]);
		}
		if(found) return res;
		else return "";
	}
};