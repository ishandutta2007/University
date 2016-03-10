#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

typedef long long LL;

struct Node
{
	LL a, b, k;
	Node(LL a, LL b, LL k):a(a),b(b), k(k){}
	Node(){}
};

bool cmp(Node a, Node b)
{
	if(a.a != b.a)
		return a.a < b.a;
	return a.k < b.k;
}

vector<Node> v;


int main()
{

	int x1, x2;
	int n;
	scanf("%d", &n);
	scanf("%d%d", &x1, &x2);
	int k, b;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &k, &b);
		v.push_back(Node((LL)k*x1+b, (LL)k*x2+b, k));
	}

	sort(v.begin(), v.end(), cmp);


	// for(int i = 0; i < n; i++)
	// {
	// 	printf("%d %d\n", v[i].a, v[i].b);
	// }

	bool flag = false;
	for(int i = 0; i < n - 1; i++)
	{
		if(v[i].b > v[i+1].b) flag = true;
		else if(v[i].a == v[i+1].a && v[i].b == v[i+1].b) flag = true;
	}

	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}