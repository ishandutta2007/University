#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

vector<string> vs;


int main()
{


	freopen("out.txt", "w", stdout);
	vs.push_back("");
	vs.push_back("c");
	vs.push_back("ff");
	// vs[1] = "c";
	// vs[2] = "ff";
	// cout << "!!!" << endl;
	cout << 1 << ":" << vs[1] << endl;
	cout << 2 << ":" << vs[2] << endl;
	int n = 20;
	for(int i = 3; i < n; i++)
	{
		vs.push_back(vs[i-2] + vs[i-1]);

		// cout << i << ":" << vs[i] << endl;

		int tmp = 0;

		for(int j = 0, len = vs[i].length(); j < len ; j++)if(vs[i][j] == 'c')
		{
			for(int k = j + 1; k < len; k++)
				if(vs[i][k] == 'c')
					tmp = (tmp + k - j) % 530600414;
		}
		cout << i << ": "<< tmp << endl;
	}



	return 0;
}