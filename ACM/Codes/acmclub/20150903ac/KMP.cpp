#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char src[1002000];
char substring[1002000];

//process the substring
int* get_next(char* substring)
{
	int substring_len = strlen(substring);
	int* a = new int[substring_len];
	a[0] = -1;
	int j = -1;
	for(int i = 1; i < substring_len; i++)
	{
		while(j > -1 && substring[i] != substring[j + 1])
			j = a[j];
		if(substring[j+1] == substring[i])
			j = j + 1;
		a[i] = j;
	}
//    for(int i = 0; i < substring_len; i++)
//        printf("%d ",a[i]);
//    printf("\n");
	return a;
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
	int t;
	scanf("%d",&t);
	while(t--){
		memset(src, 0, sizeof(src));
		memset(substring, 0, sizeof(substring));
		scanf("%s%s",substring, src);
		int ans = kmp(src, substring, get_next(substring));
		printf("%d\n",ans);
	}
	return 0;
}

