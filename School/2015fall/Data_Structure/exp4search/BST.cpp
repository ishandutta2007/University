#include <bits/stdc++.h>

using namespace std;

class BST
{
private:
	struct Node
	{
		int data;
		Node *lson, *rson, *fa;
		Node(){}
		Node(int d, Node *l, Node *r, Node *fa): data(d), lson(l), rson(r), fa(fa){}
		void output()
		{
			if(data != 0x3f3f3f3f)
			cout << data << " " ;
		}
	};
	void add(Node *pre, Node *&now, int d)
	{
		if(now == NULL) now = new Node(d, NULL, NULL, pre);
		else if(d < now->data) add(now, now->lson, d);
		else add(now, now->rson, d);
	}
	
	void del_BST(Node *now)
	{
		if(now != NULL)
		{
			del_BST(now->lson);
			del_BST(now->rson);
			delete now;
		}
	}
	
	void dfs(Node *now)
	{
		if(now == NULL) return ;
		if(now -> lson != NULL) dfs(now -> lson);
		now->output();
		if(now -> rson != NULL) dfs(now -> rson);
	}
	void dfssort(Node *now, vector<int> &vi)
	{
		if(now == NULL) return ;
		if(now -> lson != NULL) dfssort(now -> lson, vi);
		if(now-> data != 0x3f3f3f3f)vi.push_back(now->data);
		if(now -> rson != NULL) dfssort(now -> rson, vi);
	}
	
public:

	
	Node *root;

	void clear()
	{
		del_BST(root);
		root = new Node(0x3f3f3f3f, NULL, NULL, NULL);
	}
	void show()
	{
		if(root == NULL) cout << "The BST is empty" << endl;
		dfs(root);
	}
	void build(vector<int> vi)
	{
		for(int i = 0, l = vi.size(); i < l ; i++)
		{
			add(NULL, root, vi[i]);
		}
	}
	
	Node* find(Node *now, int d)
	{
		if(now == NULL) return NULL;
		if(now->data == d) return now;
		if(now->data < d) return find(now->rson, d);
		else return find(now->lson, d);
	}
	
	Node* findmax(Node *now)
	{
		while(now->rson != NULL) now = now->rson;
		return now;
	}
	Node* findmin(Node *now)
	{
		while(now->lson != NULL) now = now->lson;
		return now;
	}
	void sort(vector<int> &vi)
	{
		if(root == NULL) cout << "The BST is empty" << endl;
		dfssort(root, vi);	
	}
	void deldata(Node *now, int d)
	{
		
		Node *tmp = find(now, d);
		if(tmp == NULL)
		{
			return;
		}
		
		if(tmp -> lson == NULL && tmp -> rson == NULL)
		{
			Node *fa = tmp->fa;
			if(fa != NULL)
			{
				if(fa->data < d)
					fa->rson = NULL;
				else
					fa->lson = NULL;
			}			
			delete tmp;
		}
		
		else if(tmp->lson == NULL)
		{
			Node *fa = tmp->fa;
			if(fa != NULL)
			{
			cout << "in del" << endl;
			cout << tmp->data << endl;
				if(fa->data < d)
					fa->rson = tmp->rson;
				else
					fa->lson = tmp->rson;
			}
			tmp->rson->fa = fa;
			Node *tt = tmp->rson;
			delete tmp;
			tmp = tt;
		}
		else if(tmp ->rson == NULL)
		{
			Node *fa = tmp->fa;
			if(fa != NULL)
			{
				if(fa->data < d)
					fa->rson = tmp->lson;
				else
					fa->lson = tmp->lson;
			}
			tmp->lson->fa = fa;
			Node *tt = tmp->lson;
			delete tmp;
			tmp = tt;
		}
		else
		{
			Node *nd = findmax(tmp->lson);
			// cout << " !! " << nd->data << endl;
			swap(tmp->data, nd->data);
			deldata(tmp->lson, d);
		}
	}
	
	BST():root(NULL){}
}bst;


int binary_search(vector<int> v, int l, int r, int x)
{
	int mid = (l + r) / 2;
	while(v[mid] != x && l < r)
	{
		if(v[mid] < x) l = mid+1;
		else r = mid - 1;
		mid = (l + r) / 2;
	}
	if(v[mid] == x) 
		cout << "mid is " << mid << endl;
	else
		cout << "no such element" <<endl;
	return mid;
}


int main()
{
	bst.clear();
	vector< int > vi;
	int n;
	cout << "input the size of the array" << endl;
	cin >> n;
	cout << "input n integers" << endl;
	while(n--)
	{
		int tmp;
		cin >> tmp;
		vi.push_back(tmp);
	}
	bst.build(vi);
	bst.show();
	cout << endl;
	cout << "input the number of delete operations" << endl;
	cin >> n;
	while(n--)
	{
		int tmp;
		cin >> tmp;
		bst.deldata(bst.root, tmp);
		bst.show();
		cout << endl;
	}

	
	
	// bst.show();
	// cout << endl;
	
	vi.clear();
	
	bst.sort(vi);
	
	for(int i = 0, l = vi.size(); i < l; i++)
		cout << vi[i] << " ";
	cout << endl;
	cin >> n ;
	binary_search(vi, 0, vi.size()-1, n);
	
	
	return 0;
}