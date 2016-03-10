#include <bits/stdc++.h>

using namespace std;


class FourStrings
{
public:
	int ans;

	string combine2(string a, string b, int p)
	{
		int la = a.length(), lb = b.length();


		for(int i = 0, len = min(la-p, lb); i < len; i++)
		{
			if(a[i + p] != b[i]) 			{return "";}
		}

		for(int i = max(min(la-p,lb),0); i < lb; i++)
			a.push_back(b[i]);
		return a;
	}


	void combine(vector<string> vs)
	{
		if(vs.size() == 1)
		{
			if(ans > vs[0].length())
				ans = vs[0].length();
			return;
		}

		for(int i = 0, len = vs[0].length(); i <= len; i++)
		{
			string tmp = combine2(vs[0], vs[1], i);
			if(tmp.length() > 0)
			{
				vector<string> tmpvs;
				tmpvs.clear();
				tmpvs.push_back(tmp);
				for(int i = 2; i < min(4,vs.size()); i++)
					tmpvs.push_back(vs[i]);
				combine(tmpvs);
			}
		}
	}
	void calans(string a, string b, string c, string d)
	{
		vector<string> vs;
		vs.push_back(a);
		vs.push_back(b);
		vs.push_back(c);
		vs.push_back(d);
		combine(vs);
	}


	int shortestLength(string a, string b, string c, string d)
	{
		vector<string> vs;
		vs.push_back(a);
		vs.push_back(b);
		vs.push_back(c);
		vs.push_back(d);
		int aa[4] = {0, 1, 2, 3};
		ans = a.length() + b.length() + c.length() + d.length();
		do {
			calans(vs[aa[0]], vs[aa[1]], vs[aa[2]], vs[aa[3]]);
		}while(next_permutation(aa, aa + 4));
		return ans;
	}

}fs;

int main()
{

	cout << fs.shortestLength("x", "x", "x", "x");

	return 0;
}