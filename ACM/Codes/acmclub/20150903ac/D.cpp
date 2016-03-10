#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

char src[1002000];
char substring[1002000];
int _next[1002000];

void get_next(char* substring)
{
	int substring_len = strlen(substring);
	memset(_next, 0, sizeof(_next));
	_next[0] = -1;
	int j = -1;
	for(int i = 1; i < substring_len; i++)
	{
		while(j > -1 && substring[i] != substring[j + 1])
			j = _next[j];
		if(substring[j+1] == substring[i])
			j = j + 1;
		_next[i] = j;
	}
//    for(int i = 0; i < substring_len; i++)
//        printf("%d ",next[i]);
//    printf("\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s", src);
		get_next(src);
		
		int len = strlen(src);

		int circle = len - _next[len-1] - 1;
		// if(len % circle == 0)
		// 	printf("0\n");
		if(circle == len) printf("%d\n", len);
		else if(circle == 1 || len % circle == 0) printf("0\n");
		else
		printf("%d\n", circle - len % circle);

	}
	return 0;
}

