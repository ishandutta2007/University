#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

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

char s1[300], s2[300], ss[4000];
int a[10000];
int len1, len2;
int len;


int solve(char* s, char* ss, int l)
{

	if(l < len) return 0;

	int ret = 0;
	for(int i = 0; i + len <= l; i++)
	{
		if(strncmp(ss, s+i, len) == 0)
		{
			ret ++;
			i+=len-1;
		}
	}

	return ret;
}





int main()
{


	int n;
	
	gets(s1);
	gets(s2);
	gets(ss);

	len1 = strlen(s1);
	len2 = strlen(s2);
	len = strlen(ss);
	for(int i = 0 ; i < len1; i++)
		if(s1[i] >= 'A' && s1[i] <= 'Z')
			s1[i] = s1[i] - 'A' + 'a';

	for(int i = 0 ; i < len2; i++)
		if(s2[i] >= 'A' && s2[i] <= 'Z')
			s2[i] = s2[i] - 'A' + 'a';

	// a[0] = kmp(s1, ss, get_next(ss));
	// a[1] = kmp(s2, ss, get_next(ss));

	a[0] = solve(s1, ss, len1);
	a[1] = solve(s2, ss, len2);
	scanf("%d", &n);

	// cout << a[1] << " " << a[2] << endl;
	if(n == a[0])
	{
		printf("0\n");
		return 0;
	}
	else if(n == a[1])
	{
		printf("1\n");
		return 0;
	}

	for(int i = 2; ; i++)
	{
		a[i] = a[i-2] + a[i-1];

		if(a[i] == n)
		{
			printf("%d\n", i);
			return 0;
		}

		else if(a[i] > n)
		{
			printf("Impossible\n");
			return 0;
		}
	}

	return 0;
}

