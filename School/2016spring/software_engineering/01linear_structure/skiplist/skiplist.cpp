#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Skiplist
{
private:
	int INF;
	struct Node
	{
		int data, level;
		Node *next_node,*next_level;
		Node (){}
		Node (int data, int level, Node *nn, Node *nl):data(data), level(level), next_node(nn), next_level(nl){}
	};
	int max_level;
	vector<Node*> heads;
	int roll_level()
	{
		int ret = 1;
		while (rand()%4 == 1) ret++;
		return ret;
	}
	void show_list(Node *head)
	{
		while (head->next_node != NULL)
		{
			cout << head->next_node->data << " ";
			head = head->next_node;
		}
	}
public:
	void sp_insert(int d)
	{
		int tmp_level = roll_level();
		while (heads.size() <= tmp_level)
		{
			int headsize = heads.size();
			heads.push_back(new Node(INF, headsize, NULL, heads[headsize - 1]) );
		}

		Node *pre_node = heads[heads.size()-1];
		Node *upper_node = NULL;
		while (true)
		{
			while (pre_node->next_node != NULL && pre_node->next_node->data > d)
			{
				pre_node = pre_node->next_node;
			}
			if (pre_node->level > tmp_level)
			{
				pre_node = pre_node->next_level;
				continue;
			}
			Node *tmp = new Node(d, pre_node->level, pre_node->next_node, NULL);
			pre_node->next_node = tmp;
			if (upper_node != NULL)
			{
				upper_node -> next_level = tmp;
			}
			upper_node = tmp;
			pre_node = pre_node->next_level;
			if (upper_node->level == 1) break;
		}
	}
	pair<Node*, Node*> sp_search(int d)
	{
		Node *now_node = heads[heads.size()-1];
		Node *pre_node = NULL;
		if (now_node == NULL) return make_pair((Node *)NULL, (Node *)NULL);
		while (true)
		{
			while (now_node->next_node != NULL && now_node->next_node->data >= d)
			{
				pre_node = now_node;
				now_node = now_node->next_node;
			}
			// cout << "hello" << endl;
			// cout << now_node->data << endl;
			if (now_node == NULL) return make_pair((Node *)NULL, (Node *)NULL);
			if (now_node->data == d)
			{
				return make_pair(now_node, pre_node);
			}
			else
			{
				now_node = now_node->next_level;
			}
			if (now_node == NULL) return make_pair((Node *)NULL, (Node *)NULL);
		}
			return make_pair((Node *)NULL, (Node *)NULL);
	}
	bool find(int d)
	{
		if(sp_search(d).first == NULL) return false;
		else return true;
	}
	int sp_delete(int d)
	{
		pair<Node*, Node*> pnn = sp_search(d);
		if (pnn.first == NULL)
		{
			return -1;
		}
		Node *pre = pnn.second;
		Node *now = pnn.first;

		while (true)
		{
			while(pre->next_node->data > d) pre = pre->next_node;
			Node *tmp = now;
			pre->next_node = now->next_node;
			now = now->next_level;
			pre = pre->next_level;
			delete tmp;
			if(pre == NULL) break;
		}

		return 1;

	}
	void clear()
	{
		INF = 0x3f3f3f3f;
		max_level = 0;
		heads.clear();
		heads.push_back(new Node(0,0,NULL,NULL));
	}
	void sp_init(vector<int> vi)
	{
		clear();
		for (int i = 0, len = vi.size(); i < len; i++)
			sp_insert(vi[i]);
	}
	void show_skip_list()
	{
		for (int i = 1, len = heads.size(); i < len ; i++)
		{
			cout << "level :" << i << endl;
			show_list(heads[i]);
			cout << endl;
		}
	}
	void show_level()
	{
		cout << heads.size() << endl;
	}
	Skiplist()
	{
		clear();
	}
}sp;


int main()
{
	cout << "There are 6 opitons" << endl;
	cout << "1. insert a number" << endl;
	cout << "2. check whether a number exist in the skiplist" << endl;
	cout << "3. delete a number" << endl;
	cout << "4. make a new skiplist with some numbers" << endl;
	cout << "5. show the skiplist" << endl;
	cout << "6. quit" << endl;
	int cmd = 0;
	while (true)
	{
		cout << "input command id:";
		cin >> cmd;
		if (cmd == 1) {
			int tmp;
			cout << "input the number you want to insert:";
			cin >> tmp;
			sp.sp_insert(tmp);
		}
		else if (cmd == 2) {
			int tmp;
			cout << "input the number you want to check:";
			cin >> tmp;
			if (sp.find(tmp)) cout << "found" << endl;
			else cout << "not found" << endl;
		}
		else if (cmd == 3) {
			int tmp;
			cout << "input the number you want to delete:";
			cin >> tmp;
			if (sp.sp_delete(tmp) == -1) cout << tmp << " not found" << endl;
			else cout << tmp << " deleted" << endl;
		}
		else if (cmd == 4) {
			int tmpn, tmp;
			sp.clear();
			cout << "input the numbers of the integers:";
			cin >> tmpn;
			cout << "input " << tmpn << " numbers" << endl;
			for (int i = 0; i < tmpn; i++) {
				cin >> tmp;
				sp.sp_insert(tmp);
			}
		}
		else if (cmd == 5) {
			sp.show_skip_list();
		}
		else if (cmd == 6) {
			sp.clear();
			break;
		}
	}

	cout << "thanks for testing Skiplist by Epro" << endl;
	cout << "report at py@hit.edu.cn if you find any bugs" << endl;
	return 0;
	
}
