/**
 * @Author:      Poore@hit_cs
 * @Mail:        py@hit.edu.cn
 * @FileName:    BIT.cpp
 * @FilePath:    /C/Users/PoorE/Desktop/Data Structure/exp2/BIT.cpp
 * @DateTime:    2015-11-20 11:24:53
 */

 
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

class BIT
{
	int size;
	struct Node
	{
		char data;
		Node *lson, *rson;
		Node(char ch):data(ch),lson(NULL), rson(NULL){}
		Node():data(0),lson(NULL),rson(NULL){}
		void show(){cout << data << ' ';}
	};
	deque<Node*> NDdeq1,NDdeq2;
	void del_tree(Node *now)
	{
		if(now == NULL) return;
		if(now->lson != NULL)
		{
			del_tree(now->lson);
			now->lson = NULL;
		}
		if(now->rson != NULL)
		{
			del_tree(now->rson);
			now->rson = NULL;
		}
		delete now;
	}
	void build_by_DLR_LDR(char dlr[], char ldr[], int l, int r, Node *now)
	{
		now->data = dlr[size];
		int p;
		for(p = l; p <= r; p++)
		{
			if(ldr[p] == now->data)
				break;
		}
		if(p > l)
		{
			now->lson = new Node();
			size++;
			build_by_DLR_LDR(dlr, ldr, l, p-1, now->lson);
		}
		if(p < r)
		{
			now->rson = new Node();
			size++;
			build_by_DLR_LDR(dlr, ldr, p+1, r, now->rson);
		}
	}

	void build_by_DLR_LDR2(char dlr[], char ldr[], int len, Node *root)
	{
		deque< pair<Node*, int> > deq;
		deq.clear();
		Node *now;
		pair<Node*, int> tmp;
		int p;
		for(int i = 0; i < len; i++)
		{
			if(i == 0)
				now = root;
			else
				now = new Node();
			now->data = dlr[i];
			for(p = 0; p < len; p++)
				if(ldr[p] == now->data)
					break;
			tmp = make_pair(now, p);
			if(i == 0 || deq.empty())
			{
				deq.push_front(tmp);
				continue;
			}
			if(deq[0].second > p)
			{
				deq[0].first->lson = now;
				deq.push_front(tmp);
			}
			else
			{
				while(deq.size() > 1 && deq[1].second < p) deq.pop_front();

				deq[0].first->rson = now;
				deq.pop_front();
				deq.push_front(tmp);
			}
		}
	}

	void DLR(char d1, char d2, Node* now, int &find)
	{
		if(find % 6 == 0) return;
		if(find%2 != 0)
		{
			NDdeq1.push_back(now);
		}
		if(find%3 != 0)
		{
			NDdeq2.push_back(now);
		}
		if(now->data == d1)
		{
			find*=2;
		}
		if(now->data == d2)
		{
			find*=3;
		}
		if(now->lson != NULL && find%6 != 0)DLR(d1, d2, now->lson, find);
		if(now->rson != NULL && find%6 != 0)DLR(d1, d2, now->rson, find);
		if(find%2!=0)
		{
			NDdeq1.pop_back();
		}
		if(find%3!=0)
		{
			NDdeq2.pop_back();
		}
	}
public:
	Node *root;
	BIT():size(0),root(NULL){}
	void clear()
	{
		size = 0;
		del_tree(root);
		root = new Node();
		// root->show();
	}
	int LCA(char d1, char d2)
	{
		int find = 1;
		NDdeq1.clear();
		NDdeq2.clear();
		DLR(d1, d2, root, find);
		int i, l = min(NDdeq1.size(), NDdeq2.size());
		// cout << NDdeq1.size() << " " << NDdeq2.size();
		// cout << NDdeq2[0]->data;
		for(i = 0; i < l; i++)
		{
			// cout << NDdeq1[i]->data << " " << NDdeq2[i]->data << endl;
			if(NDdeq1[i]->data != NDdeq2[i]->data)
				break;
		}
		return NDdeq1[i-1]->data;
	}
	void build_by_dlr_ldr_recursive(char *dlr, char *ldr, int size)
	{
		build_by_DLR_LDR(dlr, ldr, 0, size-1, root);
	}
	void build_by_dlr_ldr_non_recursive(char *dlr, char *ldr, int size)
	{
		build_by_DLR_LDR2(dlr, ldr, size, root);
	}
	void show_DLR(Node *now)
	{
		now->show();
		if(now->lson != NULL)
			show_DLR(now->lson);
		if(now->rson != NULL)
			show_DLR(now->rson);
	}
	void show_LDR(Node *now)
	{
		if(now->lson != NULL)
			show_LDR(now->lson);
		now->show();
		if(now->rson != NULL)
			show_LDR(now->rson);
	}
	void show_LRD(Node *now)
	{
		if(now->lson != NULL)
			show_LRD(now->lson);
		if(now->rson != NULL)
			show_LRD(now->rson);
		now->show();
	}
	void show_LRD2(Node *now)
	{
		deque<pair<Node*, int> > deq;
		deq.clear();
		deq.push_back(make_pair(now, 0));
		pair<Node* , int> tmp;
		while(!deq.empty())
		{
			tmp = deq.front();
			deq.pop_front();
			if(tmp.second <= 0 && tmp.first->lson != NULL)
			{
				deq.push_front(make_pair(tmp.first, 1));
				deq.push_front(make_pair(tmp.first->lson, 0));
			}
			else if(tmp.second <= 1 && tmp.first->rson != NULL)
			{
				deq.push_front(make_pair(tmp.first, 2));
				deq.push_front(make_pair(tmp.first->rson, 0));
			}
			else
			{
				tmp.first->show();
			}
		}
	}
	void show_layer(Node *now)
	{
		deque<Node*> deq;
		deq.clear();
		deq.push_back(now);
		while(!deq.empty())
		{
			now = deq.front();
			deq.pop_front();
			now->show();
			if(now->lson != NULL)
				deq.push_back(now->lson);
			if(now->rson != NULL)
				deq.push_back(now->rson);
		}
	}
}bit;
char dlr[1000];
char ldr[1000];
int main()
{
	int size;
	printf("Please input 2 stings seperated by a space\n");
	printf("the  first one represeting the DLR\n");
	printf("the second one represeting the LDR\n");
	scanf("%s%s", dlr, ldr);
	size = strlen(dlr);
	bit.clear();


	bit.build_by_dlr_ldr_non_recursive(dlr, ldr, size);
	//!!! uncomment following lines and comment previous lines to get reverse
	// bit.build_by_dlr_ldr_recursive(dlr, ldr, size);
	bit.show_LRD2(bit.root);

	
	printf("input 2 nodes in a single line seperated by a space to get their LCA\n");
	printf("input # # to exit\n");
	char l[10], r[10];
	while(scanf("%s%s",l, r) == 2)
	{
		if(l[0] == '#') break;
		else
			printf("the LCA of %c and %c is %c\n", l[0], r[0], bit.LCA(l[0], r[0]));
	}
	return 0;
}

