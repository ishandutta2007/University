#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int d, len;
	Node(){}
	Node(int d, int len):d(d),len(len){}
	bool operator < (const Node& nd) const
	{
		if(len == nd.len) return d < nd.d;
		else return len > nd.len;
	}
};

vector<Node> v;
class ReplacingDigit
{
public:

	vector<int> DD;
	int add(Node nd)
	{
		int pos = 9;
		while(DD[pos] == 0) pos--;
		if(pos == 0 || nd.d >= pos) return 0;
		DD[pos]--;
		return (pos-nd.d)*nd.len;
	}



	int getMaximumStockWorth(vector <int> A, vector <int> D)
	{

		DD.push_back(1);
		for (int i = 0; i < 9; i++)
			DD.push_back(D[i]);
		int sum = 0;
		for (int i = 0, len = A.size(); i < len; i++)
		{
			int tmp = A[i];
			sum += tmp;
			int mod = 1;
			while(tmp)
			{
				v.push_back(Node(tmp%10, mod));
				tmp /= 10;
				mod*=10;
			}
		}

		sort(v.begin(), v.end());


		for (int i = 0, len = v.size(); i < len; i++)
		{
			sum += add(v[i]);
		}
		return sum;
	}
};

int main()
{

	return 0;
}