#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int heap[500020];
int len=0;

void swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
	return;
}

void _delete(){
	heap[1]=heap[len--];
	int nexti,i;
	for(i=1;i<=len;i=nexti){
		nexti=i*2;
		if(nexti>len)
			break;
		if(heap[nexti]>heap[nexti+1] && nexti+1<=len)
			nexti++;
		if(heap[nexti]<heap[i])
		{
			swap(heap[nexti],heap[i]);
			continue;
		}
		break;
	}
	
}


void add(int data){
	heap[++len]=data;
	int i;
	for(i=len;i>1;i/=2){
		if(heap[i]<heap[i/2])
			swap(heap[i],heap[i/2]);
	}
	return;
}


int main (){
	
	int n,i;
	char operation[10];
	int data;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",operation);
		if(strcmp(operation,"add")==0){
			scanf("%d",&data);
			add(data);
		}
		else if(strcmp(operation,"query")==0 && len)
			printf("%d\n",heap[1]);
		else if(strcmp(operation,"delete")==0 && len)
			_delete();
	}
	
	return 0;
	
}

