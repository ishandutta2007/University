#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define inf 1000000007
#define maxn 120000
#define maxm 4200

using namespace std;

char a[1000];
int v[30];
int sum;

// int IsEnglish(char *a) {
// char*s[8]={" a "," the","any"," and","you","ing ","ely"," of "};int i=0;
// while(i++<700)if(!strncmp(a+i/7,s[i%7],3+i%7%2))return 1;return 0;
// }
int IsEnglish(char *a) {
char*s[7]={" the"," of "," you"," and","e co"," we "," 10 "};int i=0,o=0;
while(i++<700)if(!strncmp(a+i/7,s[i%7],4))o=1;return o;
}

int main()
{
	freopen("C1.in","r",stdin);
	 for (int i=1;i<=100;i++)
	{
		gets(a);
		printf("%d\n",IsEnglish(a));
	}
	
	return 0;
}