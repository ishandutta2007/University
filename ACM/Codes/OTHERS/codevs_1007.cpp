#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}


int ys(int a,int b){
	if(a<b)
		swap(a,b);
	if(a%b==0)
		return b;
	else
		return ys(b,a%b);

}

int bs(int a,int b){
	return (a*b)/ys(a,b);
}




int main(){
	int sum[2]={0,1};
	int n=0;
	int k;
	int min,max;
	scanf("%d",&k);
	while(1){
		n++;
		min=bs(sum[1],n);
		printf("min=%d\n",min);
		printf("%d %d\n",sum[0],sum[1]);
		sum[0]=sum[0]*min/sum[1]+min/n;
		sum[1]=min;
		if((double)sum[0]/sum[1]>k){
			printf("%d\n",n);
			system("pause");
			return 0;
		}
		max=ys(sum[0],sum[1]);
		sum[0]/=max;
		sum[1]/=max;
	}
}