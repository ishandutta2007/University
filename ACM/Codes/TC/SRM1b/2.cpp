#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class BinaryCode
{
public:
	vector<string> decode(string code)
	{
		vector<string> ret;
		string tmp;
		ret.clear();
		int d;
		int i;
		int len = code.length();

		for(int t = 0; t < 2; t++)
		{
			tmp.clear();
			tmp.push_back(t + '0');
			for(i = 0; i < len - 1; i++)
			{
				if(i == 0)
					d = code[i] - tmp[i];

				else
					d = code[i] - tmp[i-1] - tmp[i] + '0';

				if(d != 1 && d != 0)
					break;


				tmp.push_back(d+'0');
			}
			if((i >= len-1 && tmp[len-2] + tmp[len-1] - '0' == code[len-1]) || (len == 1 && tmp[0] == code[0]))
			{
				ret.push_back(tmp);
			}
			else
			{
				ret.push_back("NONE");
			}
		}

		return ret;
	}
	
	
};

int main()
{

	BinaryCode bc;

	string s;
	while(cin >> s)
	{

		vector<string> vs = bc.decode(s);

		cout << vs[0] << endl;
		cout << vs[1] << endl;

	}

	return 0;
}