#include <bits/stdc++.h>

using namespace std;

bool f[100];

class MultiplicationTable2Easy
{
public:
	string isGoodSet(vector <int> table, vector <int> t)
	{
		memset(f, 0, sizeof(f));
		int n = sqrt(table.size());
		for (int i = 0, len = t.size(); i < len; i++)
			f[t[i]] = true;

		for (int i = 0, len1 = t.size(); i < len1; i++)
			for (int j = 0, len2 = t.size(); j < len2; j++)
			{
				if (f[table[t[i]*n + t[j]]] == false) {
					cout << i << " " << j << " " << i*n + j << endl;
					return "Not Good";
				}
			}


		return "Good";

	}
};