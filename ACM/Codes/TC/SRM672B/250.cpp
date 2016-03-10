#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int cnt1[120], cnt2[120];

class SetPartialOrder
{
public:
	string compareSets(vector <int> a, vector <int> b)
	{
		bool ainb, bina;
		ainb = bina = true;
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));

		for(int i = 0, l = a.size(); i < l ; i++)
			cnt1[a[i]]++;
		for(int i = 0, l = b.size(); i < l ; i++)
			cnt2[b[i]]++;

		for(int i = 1; i <= 100; i++)
		{
			if(cnt1[i] > cnt2[i]) ainb = false;
			if(cnt1[i] < cnt2[i]) bina = false;
		}

		if(ainb && bina) return "EQUAL";
		else if(ainb) return "LESS";
		else if(bina) return "GREATER";
		else return "INCOMPARABLE";
	}

};