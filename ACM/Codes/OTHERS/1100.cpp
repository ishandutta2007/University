#include"stdio.h"
#include"stdlib.h"
#include"string.h"

void check(char s[270]){
	int len = strlen(s);
	int pre = 0;
	int i;
	for(i=len-1;i>=0;i--){
		if(s[i]>='p' && s[i]<='z')
		{
			pre++;
			continue;
		}
		else if(s[i]=='N')
			continue;
		else if(s[i]=='C' || s[i]=='D' || s[i]=='E' || s[i]=='I'){
			if(pre>=2)
				pre-=1;
			else
				{
					printf("NO\n");
					return;
				}
			continue;
		}
		else {
			printf("NO\n");
			return;
		
		}
	}

	if(pre==1)
		printf("YES\n");
	else
		printf("NO\n");
		
	return;

}




int main(){
	char s[270];
	while(scanf("%s",&s)!=0){
		// printf("input=%s\n",s);
		check(s);
	}
	return 0;


}