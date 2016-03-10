#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char src[1002000];
char substring[1002000];
int next[1002000];


vector<int>v;


int* get_next(char* substring)
{
	int substring_len = strlen(substring);
	memset(next, 0, sizeof(next));
	next[0] = -1;
	int j = -1;
	for(int i = 1; i < substring_len; i++)
	{
		while(j > -1 && substring[i] != substring[j + 1])
			j = next[j];
		if(substring[j+1] == substring[i])
			j = j + 1;
		next[i] = j;
	}
//    for(int i = 0; i < substring_len; i++)
//        printf("%d ",next[i]);
//    printf("\n");
	return next;
}





int main()
{
	// int t;
	// scanf("%d",&t);
	while(scanf("%s", src) != EOF){
		
		get_next(src);

		// for(int i = 0,len = strlen(src); i < len; i++)
		// 	printf("%d ", next[i]);
		// printf("\n");

		int pos = strlen(src) - 1;
		v.clear();
		while(pos != -1)
		{
			v.push_back(pos);
			pos = next[pos];
		}
		sort(v.begin(), v.end());

		for(int i = 0,len = v.size(); i < len; i++)
		{
			printf("%d%c", v[i]+1, i == len-1? '\n':' ');
		}


	}
	return 0;
}

