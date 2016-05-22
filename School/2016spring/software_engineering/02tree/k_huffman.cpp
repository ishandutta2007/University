#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;


class Huffman
{
public:
	int k;
	map<char, int> mp;
	map<char, string> rmp;
	char tc[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	struct Node
	{
		char ch;
		int cnt;
		Node *sons[16];
		bool isLeaf;
		Node()
		{
			memset(sons, 0, sizeof(sons));
		}
		Node(char ch, int cnt, bool b):ch(ch),cnt(cnt),isLeaf(b)
		{
			memset(sons, 0, sizeof(sons));
		}
	};
	void dfs(Node *now, string str)
	{
		if(now == NULL) return;
		if(now->isLeaf == true)
		{
			cout << '[' << now->ch << ']' << " : " << str << endl;
			rmp[now->ch] = str;
			return;
		}

		for (int i = 0; i < k; i++)
		{
			dfs(now->sons[i], str + tc[i]);
		}
	}
	Node *head, *now;
	void input(char ch)
	{
		if(mp.find(ch) == mp.end())
			mp[ch] = 0;
		mp[ch] ++;
	}
	static bool cmp(Node *a, Node *b){return a->cnt < b->cnt;}

	void build()
	{

		deque<Node*> que1,que2;
		que1.clear(), que2.clear();
		for(pair<char ,int> x : mp)
		{
			cout << '[' << x.first << ']' << endl;
			Node* tmp = new Node(x.first, x.second, true);
			que1.push_back(tmp);
		}


		int tmpr = que1.size() % (k-1);
		int add;
		if (tmpr == 0) add = 1;
		else if (tmpr == 1) add = 0;
		else add = k - tmpr;
		while(add--)
		{
			Node* tmp = new Node(0, 0, true);
			que1.push_back(tmp);
		}
		sort(que1.begin(), que1.end(), cmp);
		int len1, len2;
		len1 = que1.size(),len2 = que2.size();
		
		while(len1 + len2 > 1)
		{
			Node *node = new Node(0, 0, false);
			for(int i = 0; i < k; i++)
			{
				if(len1 == 0)
				{
					node->cnt += que2[0]->cnt;
					node->sons[i] = que2[0];
					que2.pop_front();
					len2--;
				}
				else if(len2 == 0)
				{
					node->cnt += que1[0]->cnt;
					node->sons[i] = que1[0];
					que1.pop_front();
					len1--;
				}
				else if(que1[0]->cnt < que2[0]->cnt)
				{
					node->cnt += que1[0]->cnt;
					node->sons[i] = que1[0];
					que1.pop_front();
					len1--;	
				}
				else
				{
					node->cnt += que2[0]->cnt;
					node->sons[i] = que2[0];
					que2.pop_front();
					len2--;
				}
			}
			que2.push_back(node);
			len2 ++;
		}
		head = que2[0];
	}
	map<char, string> getmap()
	{
		string str = "";
		dfs(head, str);
		return rmp;
	}

	// char unzipin(char ch)
	// {
	// 	if(ch == '0')
	// 	{
	// 		now = now->lson;
	// 		if(now->isLeaf)
	// 		{
	// 			char ret = now->ch;
	// 			now = head;
	// 			return ret;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		now = now->rson;
	// 		if(now->isLeaf)
	// 		{
	// 			char ret = now->ch;
	// 			now = head;
	// 			return ret;
	// 		}
	// 	}
	// 	return '\0';
	// }

}huffman;




int main()
{
	cout << "input K : ";
	cin >> huffman.k;
	freopen("data.in", "r", stdin);
	// string str = "FFOOORRRRGGGGEEEEETTTTTTT";

	// for(int i = 0; i < str.length(); i++)
	// 	huffman.input(str[i]);

	char ch;
	while(scanf("%c", &ch) != EOF)
		huffman.input(ch);
	fclose(stdin);

	huffman.build();

	map<char, string> mp = huffman.getmap();

	freopen("data.in", "r", stdin);
	freopen("code.out", "w", stdout);

	string out;
	out.clear();

	while(scanf("%c", &ch)!=EOF)
	{
		// cout << mp[ch];
		out += mp[ch];
	}

	int r = out.size()%8;
	if(r)
	{
		int n = 8 - r;
		while(n--)
			out += '0';
	}


	cout << out << endl;

	// string tmp;
	// tmp.clear();
	// for(int i = 0; i < 8; i++)
	// {
	// 	tmp += r%2 + '0';
	// 	r/=2;
	// }
	// reverse(tmp.begin(), tmp.end());
	// out = tmp + out;
	// for(int i = 0, l = out.size(); i < l; i+=8)
	// {
	// 	unsigned short t = 0;
	// 	for(int j = 0; j < 8; j++)
	// 	{
	// 		t += (1<<(7-j)) * (out[i+j]-'0');
	// 	}
	// 	printf("%c:%u", t,t);
	// }
	fclose(stdin);
	fclose(stdout);

	// freopen("code.out", "r", stdin);
	// freopen("unzip.out", "w", stdout);

	// huffman.now = huffman.head;
	// while(scanf("%c", &ch)!=EOF)
	// {
	// 	// printf("%c", huffman.unzipin(ch));
	// 	char tmp = huffman.unzipin(ch);
	// 	if(tmp != '\0') printf("%c", tmp);
	// }

	// fclose(stdout);
	// fclose(stdin);
	// // huffman.show();

	return 0;
}