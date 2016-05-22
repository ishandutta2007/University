#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	Node *lson, *rson, *father;
	Node *sons[100];
	int cnt;
	Node(int data, Node *lson, Node *rson, Node *father, int cnt):data(data),lson(lson),rson(rson),father(father),cnt(cnt){}
	Node(int data, Node *father):data(data),lson(NULL),rson(NULL),father(father),cnt(0){}
	Node(int data):data(data),lson(NULL),rson(NULL),father(NULL),cnt(0){}
	void show()
	{
		cout << "data = " << data;
		cout << "  cnt = " << cnt << endl;
	}
};
vector<Node*> heads;


void tree_to_binary(Node *now)
{
	// cout << "now = " << now->data << endl;
	for (int i = now->cnt - 1; i >= 0; i--)
	{
		if(now->sons[i]->cnt)
		{
			tree_to_binary(now->sons[i]);
		}
		if(i == 0)
		{
			now->lson = now->sons[i];
			now->lson->father = now;
		}
		else
		{
			now->sons[i-1]->rson = now->sons[i];
			now->sons[i]->father = now->sons[i-1];
		}
	}
	now->cnt = 0;
	memset(now->sons, -1, sizeof(now->sons));
}

Node* forest_to_binary(vector<Node*> heads)
{
	int len = heads.size();
	for (int i = 0; i < len; i++)
	{
		tree_to_binary(heads[i]);
	}

	Node *root = heads[0], *tmp = heads[0];

	for (int i = 1; i < len; i++)
	{
		tmp->rson = heads[i];
		heads[i]->father = tmp;
		tmp = heads[i];
	}
	return root;
}


void binary_to_tree(Node *now, Node *pre)
{

	// cout << "to tree" << now->data << endl;

	if(pre != NULL)
	{
		pre->sons[pre->cnt++] = now;
	}
	if(now->lson != NULL) {
		binary_to_tree(now->lson, now);
		now->lson = NULL;
	}
	if(now->rson != NULL) {
		binary_to_tree(now->rson, pre);
		if(pre != NULL)now->rson = NULL;
	}
}
void binary_to_forest(Node *root)
{
	heads.clear();
	while(root != NULL)
	{
		cout << "heads  " << heads[0]->data << endl;
		heads.push_back(root);
		binary_to_tree(root, NULL);
		root = root->rson;
	}
}


void inittree(Node *now)
{
	int cnt, tmp;
	scanf("%d", &cnt);
	now->cnt = cnt;
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &tmp);
		now->sons[i] = new Node(tmp, now);
	}
	for (int i = 0; i < cnt; i++)
	{
		inittree(now->sons[i]);
	}
}

void show_tree(Node *now)
{
	now->show();
	for (int i = 0; i < now->cnt; i++)
		show_tree(now->sons[i]);
}
void show_bi_tree(Node *now)
{
	now->show();
	if(now->lson != NULL)
		show_bi_tree(now->lson);
	if(now->rson != NULL)
		show_bi_tree(now->rson);
}



int main()
{

	int tmp;

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &tmp);
		heads.push_back(new Node(tmp));
		inittree(heads[i]);
		show_tree(heads[i]);
		cout << "==================" << endl;
	}
	// tree_to_binary(heads[0]);
	// show_bi_tree(heads[0]);

	Node *root = forest_to_binary(heads);
	show_bi_tree(root);

	cout << "====================" << endl;

	binary_to_forest(root);

	for (int i = 0, len = heads.size(); i < len; i++)
	{
		show_tree(heads[i]);
		cout << "++++++++++++++++++++" << endl;
	}


	return 0;
}
/*
     1
   / | \
  2  3  4
 /  / \
5  6   7
   |
   8
1
3
2 3 4
1
5
0
2
6 7
1
8
0
0
0

==========

      1
     / \
    2   3
   / \ / \
  4  5 6  7
1
2
2 3
2
4 5
0
0
2
6 7
0
0

===============

      1
     / \
    2   3
       / \
      4   5
     / \
    6   7

1
2
2 3
0
2
4 5
2
6 7
0
0
0


=====
1
3
2 3 4
1
5
0
2
6 7
1
8
0
0
0
1
2
2 3
2
4 5
0
0
2
6 7
0
0
1
2
2 3
0
2
4 5
2
6 7
0
0
0
*/