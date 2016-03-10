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
	vector<int> vi;
	for(int i = 0; i < 10; i++)
	{
		vi.push_back(rand() % 11);
	}
	pq.init(vi);
	pq.show();
	return 0;
}