#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char src[1002000];
char substring[1002000];
int next[1002000];

//process the substring
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

//process src & substring to get the position
int kmp(char* src, char* substring, int* next)
{
	int j = -1;
	int ans = 0;
	int substring_len = strlen(substring);
	int src_len = strlen(src);
	for(int i = 0; i < src_len; i++)
	{
		while(j > -1 && src[i] != substring[j + 1])
			j = next[j];
		if(src[i] == substring[j + 1])
			j++;

		if(j == substring_len -1)
		{
			ans ++;
//            printf("From position %d to position %d\n", i + 2 - substring_len, i+1);
			j = next[j];
		}
	}
	return ans;
}




int main()
{
	// int t;
	// scanf("%d",&t);
	while(scanf("%s", src) != EOF){
		if(strcmp(src, ".") == 0)
			break;
		// memset(src, 0, sizeof(src));
		memset(substring, 0, sizeof(substring));
		// scanf("%s",src);
		get_next(src);
		
		int sublen = strlen(src) - next[strlen(src)-1] - 1;
		strncpy(substring, src, sublen);
 		int len = strlen(src);
 		if(len % sublen != 0)
 		{
 			printf("1\n");
 			continue;
 		}
 		// printf("%d %d\n", len, sublen);
		bool flag = true;
		for(int i = 0; i < len; i+=sublen)
		{
			if(strncmp(src+i, substring, sublen) != 0)
			{
				flag = false;
				break;
			}
		}
		if(flag) printf("%d\n", len / sublen);
		else printf("1\n");
		// for(int i = 0,len = strlen(substring);i < len; i++)
		// 	printf("%d ", next[i]);
		// printf("\n");
	}
	return 0;
}

