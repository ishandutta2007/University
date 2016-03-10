#include <bits/stdc++.h>

using namespace std;


deque<char> sta;
char ss[1000020];



int main()
{
	scanf("%s", ss);
	
	int len = strlen(ss);
	
	sta.clear();
	int ans = 0;
	
	for(int i = 0; i < len; i++)
	{
		if(ss[i] == '{' || ss[i] == '[' || ss[i] == '(' || ss[i] == '<')
		{
			sta.push_front(ss[i]);
		}
		else
		{
			if(sta.size() == 0)
			{
				printf("Impossible\n");
				return 0;
			}
			else
			{
				char tmp = sta[0];
				sta.pop_front();
				if((tmp == '(' && ss[i] == ')') 
					|| (tmp == '[' && ss[i] == ']') 
					|| (tmp == '{' && ss[i] == '}') 
					|| (tmp == '<' && ss[i] == '>')
					) ans = ans;
				else ans++;
			}
		}
	}
	
	if(sta.size() == 0)
	{
		printf("%d\n", ans);
	}
	
	else
	{
		printf("Impossible\n");
	}
	
	return 0;
}