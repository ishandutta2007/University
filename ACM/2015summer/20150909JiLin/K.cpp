#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>



using namespace std;



map<char , char> mp1, mp2;

char s1[40], s2[40];
char ss[1000020];
char decrpt[200];

void Complete()
{
	char ch1, ch2;
	for(ch1 = 'a'; ch1 <= 'z'; ch1++)
		if(mp1.find(ch1) == mp1.end())
			break;
	for(ch2 = 'a'; ch2 <= 'z'; ch2++)
		if(mp2.find(ch2) == mp2.end())
			break;

	mp1[ch1] = ch2;

	
}

void getdecrpt()
{
	char ch1;
	for(ch1 = 'a'; ch1 <= 'z'; ch1++)
	{
		if(mp1.find(ch1) != mp1.end())
			decrpt[(int)ch1] = mp1[ch1];
		else
			decrpt[(int)ch1] = ch1;
	}
}


int main()
{

	int n;
	while(scanf("%d", &n) != EOF)
	{
		mp1.clear();
		mp2.clear();


		bool WA = false;
		for(int i = 0; i < n; i++)
		{
			scanf("%s%s", s1, s2);

			for(int j = 0,len = strlen(s1); j < len; j++)
			{
				if(mp1.find(s1[j]) == mp1.end())
				{
					mp1[s1[j]] = s2[j];
				}

				if(mp2.find(s2[j]) == mp2.end())
				{
					mp2[s2[j]] = s1[j];
				}

				if(mp1[s1[j]] != s2[j] || mp2[s2[j]] != s1[j])
				{
					WA = true;
					break;
				}	
			}
		}
		scanf("%s", ss);
		if(WA)
		{
			printf("Please nie in proportion!\n");
			continue;
		}

		int cnt = mp1.size();
		if(cnt == 25) Complete();

		getdecrpt();
		int ans1 = 0, ans2 = 0;
		for(int i = 0, len = strlen(ss); i < len; i++)
		{
			ss[i] = decrpt[(int)ss[i]];

			if(i >= 2 && ss[i] == 'e' && ss[i-1] == 'i' && ss[i-2] == 'n')
				ans1++;
			if(i >= 4 && ss[i] == 'a' && ss[i-1] == 'g' && ss[i-2] == 'e' && ss[i-3] == 'i' && ss[i-4] == 'n')
				ans2++;
		}

		printf("%d %d\n", ans1, ans2);

	}
	return 0;
}