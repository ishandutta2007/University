#include"stdio.h"
#include"string.h"
char ch[100];
int top=0;

bool empty(){
	if(top==0)
		return 0;
	return 1;
}

char tp(){
	return ch[top-1];
}

void push(char x){
	ch[top++]=x;
}

void pop(){
	top--;
}

int main(){
	char s[100];
	int i;
	scanf("%s",&s);
	
	for(i=0;i<strlen(s);i++){
		if(s[i]=='(')
			push(s[i]);
		if(s[i]==')'){
			if(empty()==0)
			{
				printf("NO case 1\n");
				return 0;
			}
			else
				pop();
		}
	}
	printf("%d\n",top);
	if(top==0)
		printf("YES\n");
	else
		printf("NO case 2\n");
		
	return 0;


}