#include"stdio.h"
#include"string.h"




int root(int data[],int len){
	int i;
//	for(i=0;i<len;i++)
//		printf("%d ",data[i]);
//	printf("\n");

	while(len>1){
		for(i=1;i<len;i++)
			data[0]+=data[i];
		
		len=1;
		while(data[len-1]>=10)
		{
			data[len]=data[len-1]/10;
			data[len-1]=data[len-1]%10;
			len++;
		}
	}
	
	
	return data[0];
	
	
}




int main(){
	char s[10000];
	int data[10000]={0};
	int i,j;
	int len;
	while(1){
		scanf("%s",&s);
		if(strlen(s)==1 && s[0]=='0')
			break;
		
		len=strlen(s);
		for(i=0;i<len;i++)
			data[i]=s[i]-48;
		
		printf("%d\n",root(data,len));
		
	}
	return 0;
	
}
