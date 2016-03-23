#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;


class Huffman
{
private:
	map<char, int> mp;
	map<char, string> rmp;
	struct Node
	{
		char ch;
		int cnt;
		Node *lson, *rson;
		bool isLeaf;
		Node(){}
		Node(char ch, int cnt, Node* l, Node* r, bool b):ch(ch),cnt(cnt),lson(l),rson(r),isLeaf(b){}
	};
	void dfs(Node *now, string str)
	{
		if(now->isLeaf == true)
		{
			cout << now->ch << " : " << str << endl;
			rmp[now->ch] = str;
		}

		if(now->lson != NULL)
		{
			dfs(now->lson, str + "0");
		}
		if(now->rson != NULL)
		{
			dfs(now->rson, str + "1");
		}
	}
public:
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
			cout << x.first << endl;
			Node* tmp = new Node(x.first, x.second, NULL, NULL, true);
			que1.push_back(tmp);
		}
		sort(que1.begin(), que1.end(), cmp);
		int len1, len2;
		Node* tmp[2];

		len1 = que1.size(),len2 = que2.size();
		while(len1 + len2 > 1)
		{
			for(int i = 0; i < 2; i++)
			{
				if(len1 == 0)
				{
					tmp[i] = que2[0];
					que2.pop_front();
					len2--;
				}
				else if(len2 == 0)
				{
					tmp[i] = que1[0];
					que1.pop_front();
					len1--;
				}
				else if(que1[0]->cnt < que2[0]->cnt)
				{
					tmp[i] = que1[0];
					que1.pop_front();
					len1--;	
				}
				else
				{
					tmp[i] = que2[0];
					que2.pop_front();
					len2--;
				}
			}
			Node* node = new Node('\0', tmp[0]->cnt+tmp[1]->cnt, tmp[0], tmp[1], false);
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

	char unzipin(char ch)
	{
		if(ch == '0')
		{
			now = now->lson;
			if(now->isLeaf)
			{
				char ret = now->ch;
				now = head;
				return ret;
			}
		}
		else
		{
			now = now->rson;
			if(now->isLeaf)
			{
				char ret = now->ch;
				now = head;
				return ret;
			}
		}
		return '\0';
	}

}huffman;




int main()
{
	cout << "!!!!" << '\0'<< "!!!!" << endl;
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
	string tmp;
	tmp.clear();
	for(int i = 0; i < 8; i++)
	{
		tmp += r%2 + '0';
		r/=2;
	}
	reverse(tmp.begin(), tmp.end());
	out = tmp + out;
	for(int i = 0, l = out.size(); i < l; i+=8)
	{
		unsigned short t = 0;
		for(int j = 0; j < 8; j++)
		{
			t += (1<<(7-j)) * (out[i+j]-'0');
		}
		printf("%c:%u", t,t);
	}
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