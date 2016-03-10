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

int main()
{
	while(scanf("%s", src) != EOF){
		if(strcmp(src, ".") == 0)
			break;
		memset(substring, 0, sizeof(substring));
		get_next(src);
		int sublen = strlen(src) - next[strlen(src)-1] - 1;
		strncpy(substring, src, sublen);
 		int len = strlen(src);


 		// printf("%d %d\n", len, sublen);
 		if(len % sublen != 0)
 			printf("1\n");
 		else printf("%d\n", len / sublen);

 	// 	if(len % sublen != 0)
 	// 	{
 	// 		printf("1\n");
 	// 		continue;
 	// 	}
		// bool flag = true;
		// for(int i = 0; i < len; i+=sublen)
		// {
		// 	if(strncmp(src+i, substring, sublen) != 0)
		// 	{
		// 		flag = false;
		// 		break;
		// 	}
		// }
		// if(flag) printf("%d\n", len / sublen);
		// else printf("1\n");
	}
	return 0;
}