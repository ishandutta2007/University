#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, string> fullof;
map<string, int> fullsize;

char ss[100];
char tmpss[100];
string tmp, ori;
char getlower(char ch)
{
	if(ch >= 'A' && ch <= 'Z')
		ch = ch - 'A' + 'a';
	return ch;
}


void addword(string str)
{

	string now, tmp;
	int len = str.length() - 2;
	now.clear();
	now.push_back(str[0]);

	while(len)
	{
		tmp.push_back(len % 10 + '0');
		len /= 10;
	}
	for(int i = tmp.size() - 1; i  >= 0; i--)
		now.push_back(tmp[i]);
	now.push_back(str[str.length()-1]);


	if(fullsize.find(now) != fullsize.end() && fullof[now] != str)
	{
		fullsize[now] ++;
	}
	else if(fullsize.find(now) == fullsize.end() || (fullsize[now] == 1 && fullof[now] == str))
	{
		fullsize[now] = 1;

		// cout << "add word:" + now + "--->" + str << endl;
		fullof[now] = str;
	}
}


int getsize(string str)
{
	if(fullsize.find(str) != fullsize.end())
	{
		return fullsize[str];
	}
	return 0;
}

string getstring(string str)
{
	return fullof[str];
}

void process()
{
	if(!(tmp[1] >= '0' && tmp[1] <= '9'))
	{
		cout << ori;
		if(tmp.length() > 2)
			addword(tmp);
	}

	else
	{
		int sz = getsize(tmp);
		if(sz == 0 || sz > 1)
		{
			cout << ori;
		}
		else if(sz == 1)
		{
			string now = getstring(tmp);
			if((ori[ori.length()-1] >= 'A') && (ori[ori.length()-1] <= 'Z'))
			{
				for(int i = 0, l = now.length(); i < l; i++)
					now[i] = now[i] - 'a' + 'A';
			}
			else if(ori[0] >= 'A' && ori[0] <= 'Z')
				now[0] = now[0] - 'a' + 'A';
			cout << now;
		}
	}
}

int main()
{
	// freopen("in.txt", "r", stdin);
	fullof.clear();
	fullsize.clear();
	gets(ss);
	while(strlen(ss))
	{
		int len = strlen(ss);
		ss[len++] = '\n';
		for(int i = 0; i < len; i++)
			tmpss[i] = getlower(ss[i]);
		tmp.clear();
		ori.clear();
		for(int i = 0; i < len; i++)
		{
			if((tmpss[i] >= 'a' && tmpss[i] <= 'z') || (tmpss[i] >= '0' && tmpss[i] <= '9'))
			{
				tmp.push_back(tmpss[i]);
				ori.push_back(ss[i]);
			}
			else
			{
				if(tmp.size())
				{
					process();
				}
				printf("%c", ss[i]);
				tmp.clear();
				ori.clear();
			}
		}

		memset(ss, 0, sizeof(ss));
		gets(ss);
	}
	return 0;
}