#include"cstdio"
#include"iostream"
#include"cstring"

using namespace std;


char s[90];



bool check(int t){
	int len = strlen(s);
	if(t == len) return 1;
	
	for(int i = t; i < len; i+=t){
		for(int j = 0; j < t; j++)
			if(s[j] != s[i+j])
				return 0;
		
	}
	
	
	return 1;
}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(s, 0, sizeof(s));
		scanf("%s",s);
		for(int i = 1; i <= strlen(s); i++)
			if(strlen(s) % i == 0 && check(i))
			{
				printf("%d\n",i);
				break;
			}
		if(t != 0)
		printf("\n");
	}
//	printf("end");
	
	return 0;
}
