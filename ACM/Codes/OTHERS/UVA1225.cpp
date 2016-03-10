#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int ans[10020][10];


void add(int k){
	
	for(int i = 0;i < 10; i++)
		ans[k][i] = ans[k-1][i];
	int tmp = k;
	while(tmp > 0){
		ans[k][tmp%10]++; 
		tmp /= 10;
	}
	
	
}


int main(){
	
	for(int i = 1; i < 10020; i++){
		
		add(i);
		
	}
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i < 10; i++)
			printf("%d ",ans[n][i]);
		printf("\n");
	}

	return 0;
}

