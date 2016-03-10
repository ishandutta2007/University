#include <bits/stdc++.h>
using namespace std;



struct Node
{
	int x, y;
	Node(){}
	Node(int _x, int _y):x(_x),y(_y){}
	bool operator < (Node a)
	{
		return x < a.x;
	}
};

// bool operator < (Node a, Node b)
// {
// 	return a.x < b.x;
// }

priority_queue<Node> q;



// priority_queue<int> q;
// priority_queue<int , vector<int>, greater<int> > qq;

int fa[1111];

//clear 初始化每个集合，初始时每个集合只含有一个元素
void clear(int n)
{
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}

//root 查找i元素所属的集合编号，此处包含了路径压缩
int root(int i)
{
	while (i != fa[i])
		i = fa[i] = fa[fa[i]];
	return i;
}

//root 查找i元素所属的几何编号，此处不包含路径压缩
int root(int i)
{
	while (i != fa[i])
		i = fa[i];
	return i;
}


int unite(int x, int y)
{
	fa[root(x)] = root(y);
}




int main()
{

	q.push(Node(1,1));
	q.push(Node(2,2));


	cout << q.top().x << endl;


	return 0;
}