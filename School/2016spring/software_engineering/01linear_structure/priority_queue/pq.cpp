/*
 *	void init(vector<int>)
 *	void heap_adjust(int)
 *	void push(int)
 *	void pop(void)
 *	void clear(void)
 *	void show(void)
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Priority_queue
{
private:
	int len;
	int data[100000];
	// vector<int> data;
public:
	void heap_adjust(int pos)
	{
		for (int nxt = pos * 2; nxt <= len; pos = nxt, nxt = pos * 2)
		{
			if (nxt < len && data[nxt + 1] > data[nxt])
				nxt ++;
			if(data[pos] > data[nxt]) break;
			swap(data[pos], data[nxt]);
		}
	}
	void init(vector<int> vi)
	{
		len = vi.size();
		for (int i = 0; i < len; i++)
		{
			data[i+1] = vi[i];
		}

		for (int i = len / 2; i > 0; i--)
		{
			heap_adjust(i);
		}
	}
	void push(int d)
	{
		data[++len] = d;
		int now = len, p = now / 2;
		while(p > 0 && data[p] < data[now])
		{
			swap(data[p], data[now]);
			now = p;
			p = now / 2;
		}
	}
	void pop()
	{
		data[1] = data[len--];
		heap_adjust(1);
	}
	int top()
	{
		return data[1];
	}
	bool empty()
	{
		return len == 0;
	}
	void clear()
	{
		len = 0;
		memset(data, 0, sizeof(data));
	}
	void show()
	{
		for(int i = 1; i <= len; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	Priority_queue()
	{
		clear();
	}
}pq;

int main()
{
	cout << "there are 5 operations" << endl;
	cout << "1.initialize a heap with integers" << endl;
	cout << "2.insert an integer" << endl;
	cout << "3.pop an integer" << endl;
	cout << "4.show the largest integer" << endl;
	cout << "5.quit" << endl;

	int cmd;
	while(true)
	{
		cin >> cmd;
		if(cmd == 1)
		{
			vector<int> vi;
			for(int i = 0; i < 10; i++)
			{
				vi.push_back(rand() % 11);
			}
			pq.init(vi);
			pq.show();
		}
		else if(cmd == 2)
		{
			int tmp;
			cin >> tmp;
			pq.push(tmp);
			pq.show();
		}
		else if(cmd == 3)
		{
			cout << "pop up " << pq.top() << endl;
			pq.pop();
		}
		else if(cmd == 4)
		{
			cout << "the top is " << pq.top() << endl;
		}
		else if(cmd == 5)
			break;
	}


	return 0;
}