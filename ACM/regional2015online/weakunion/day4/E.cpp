#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int dcmp(double a, double b)
{
	if(fabs(a - b) < 1e-8) return 0;
	return a < b ? -1 : 1;
}
vector<int> ans;
struct Node{
	int id, id1;
	int cnt;
	double data;
	Node(){}
	Node(int id, int id1, double data):id(id),id1(id1),data(data){cnt = 1;}
	Node(Node a, Node b)
	{
		id = a.id;
		id1 = b.id;
		data = a.data*b.data;
		cnt = 2;
	}
	void output()
	{
		ans.push_back(id);
		if(cnt == 2) ans.push_back(id1);
	}
};
bool cmp(Node a, Node b)
{
	if(dcmp(a.data, b.data) == 0) return a.cnt < b.cnt;
	return a.data > b.data;
}
vector<Node> neg, pos, aa;
int main()
{
	int n;
	scanf("%d", &n);

	double tmp;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf", &tmp);
		if(tmp < 0) neg.push_back(Node(i, -1, -tmp));
		else pos.push_back(Node(i, -1, tmp));
	}
	if(neg.size())
	{
		sort(neg.begin(), neg.end(), cmp);
		for(int i = 0, len = neg.size(); i < len-1; i += 2)
		{
			pos.push_back(Node(neg[i], neg[i+1]));
		}
	}
	sort(pos.begin(), pos.end(), cmp);
	aa.push_back(pos[0]);
	for(int i = 1, l = pos.size(); i < l; i++)if(pos[i].data > 1.0)
	{
		aa.push_back(pos[i]);
	}
	for(int i = 0, l = aa.size(); i < l; i++)
	{
		aa[i].output();
	}
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for(int i = 0, len = ans.size(); i < len ; i++)
	{
		printf("%d%c", ans[i], i == len-1? '\n':' ');
	}

	return 0;
}