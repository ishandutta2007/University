#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 100000;

deque<int> deq;
struct Node
{
	int data;
	int pre;
}NodePool[maxn];
void clear()
{
	deq.clear();
	for(int i = 0; i < maxn; i++)
		deq.push_back(i);
}


struct stack
{
	int top;
	stack(){top = -1;}
	bool empty()
	{
		return top == -1;
	}
	Node pop()
	{
		Node ret = NodePool[top];
		deq.push_back(top);
		top = ret.pre;
		return ret;
	}
	void push(int data)
	{
		int id = deq.front();
		deq.pop_front();
		NodePool[id].data = data;
		NodePool[id].pre = top;
		top = id;
	}
}stk[3];



int main()
{
	clear();
	int x, y;
	for(int i = 1; i <= 10; i++)
	{
		scanf("%d%d", &x, &y);
		if(x == 0) stk[0].push(y);
		else if(x == 1) printf("%d\n", stk[0].pop().data);
	}
	return 0;
}