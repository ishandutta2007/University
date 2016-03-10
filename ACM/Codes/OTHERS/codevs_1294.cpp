#include"stdio.h"
#include"stdlib.h"
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
	return;
}
int main(){
	int a[11];
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		a[i]=i;
	while(i>1){
		for(j=1;j<=n;j++)
			printf("%d ",a[j]);
		printf("\n");
		for(i=n;i>=1;i--)
			if(a[i]>a[i-1])
				break;
		for(j=n;j>=i;j--)
			if(a[j]>a[i-1])
				break;
		swap(a[i-1],a[j]);
		for(j=i;j<=(i+n)/2;j++)
			swap(a[j],a[i+n-j]);
		
		
	}
	system("pause");
	return 0;
}