#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;


typedef class cards{
private:
	int order[53];
	int tmp[53];
	int l,r,n;
	
public:
	cards(){ memset(order, 0, sizeof(order)); l = 0; r = 0; }
	void get_order(){
		for(int i = 1; i <= 52; i++)
			scanf("%d",&order[i]);
	}
	
	void get_swap(){
		scanf("%d%d",&l,&r,&n);
	}
	
	void single_swap(){
		for(int i = 1; i <= 52; i++)
			tmp[i] = order[i];
		
		for(int i = l,j = 52; i <= r; i++,j--){
			order[j] = tmp[i];
		}
		int len = l - r + 1;
		for(int i = l; i <= len; i++)
			order[i] = tmp[i+len]; 
	}
	
	void shuffle(){
		for(int i = 1; i <= n; i++)
			single_swap();
	}
	
	void output(){
		for(int i = 1; i <= 52; i++)
			printf(" %d",order[i]);
	}
	
	
}cards;




int main(){
	int t;
	cards c;
	scanf("%d",&t);
	while(t--){
		c.get_order();
		c.get_swap();
		c.shuffle();
		printf("Case #%d:");
		c.output();
		printf("\n");
	}


	return 0;
}

