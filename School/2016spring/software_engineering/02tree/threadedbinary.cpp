#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data, lf, rf;
	Node *lson, *rson;
	Node(int d, Node *l, Node *r):data(d),lf(0),rf(0),lson(l),rson(r){}
	Node(int d):data(d),lf(0),rf(0),lson(NULL),rson(NULL){};
	void show()
	{
		cout << "data = " << data  << endl;
	}
};

Node *pre;

void thread_LDR(Node *now)
{
	if(now == NULL) return;
	// now->show();
	// system("pause");
	thread_LDR(now->lson);
	if(pre != NULL && pre->rson == NULL) {
		pre->rf = 1;
		pre->rson = now;
	}
	if(now->lson == NULL) {
		now->lf = 1;
		now->lson = pre;
	}
	pre = now;
	thread_LDR(now->rson);
}

void show_LDR(Node *now)
{
	if(now->lson != NULL)
		show_LDR(now->lson);
	// now->show();
	if(now->rson != NULL)
		show_LDR(now->rson);
}


void init(Node *now)
{
	int tmp1, tmp2;
	scanf("%d%d", &tmp1, &tmp2);
	if(tmp1 != 0)
	{
		now->lson = new Node(tmp1);
		init(now->lson);
	}
	if(tmp2 != 0)
	{
		now->rson = new Node(tmp2);
		init(now->rson);
	}
}



void show_thread(Node *root)
{
	Node *now = root;
	while(now->lf == 0) now = now->lson;
	now->show();
	while(now->rson != NULL)
	{
		if(now->rf == 1) now = now->rson;
		else
		{
			now = now->rson;
			while(now->lf == 0 && now->lson != NULL)
				now = now->lson;
		}
		now->show();
	}
}


int main()
{
	int tmp;
	scanf("%d", &tmp);
	Node *root = new Node(tmp);
	init(root);
	show_LDR(root);

	pre = NULL;
	thread_LDR(root);
	cout << "==================" << endl;
	show_thread(root);

	return 0;
}

/*
1
2 3
4 5
0 0
7 0
0 0
6 0
0 0

*/