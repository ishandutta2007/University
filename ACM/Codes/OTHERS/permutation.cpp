//字典序法求全排列


#include"stdio.h"
#include"stdlib.h"
#include"algorithm"


using namespace std;

int a[100];
int n;

void _swap(int i, int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	return;
}

//Reversion the data between a[s] and a[e]
void _roll(int s,int e){
	if(s>=e)
		return;
	int i;
	for(i=s;i<=(s+e)/2;i++)
		_swap(i,s+e-i);
		
	return;
}




//search and print the permutation!
void permutation(int s,int n){
	int li,ri,ii;
	int i;
	
	
	// li=n-1;
	// ri=n;
	int _count=0;
	while(li>0){
		_count++;
		printf("permutation %d :",_count);
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		for(i=n-1;i>=0;i--)
			if(a[i]<a[i+1])
				break;
		li=i;
		ri=i+1;
		for(i=n;i>li;i--)
			if(a[i]>a[li])
				break;
		ii=i;
		_swap(li,ii);
		_roll(ri,n);
	}
	printf("%d\n",_count);




}
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);	
	// for(i=1;i<=n;i++)
		// printf("%d ",a[i]);
	
	permutation(1,n);
	return 0;
}