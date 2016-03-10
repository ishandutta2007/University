#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

#define M 3
#define D 24
#define Y 2013


int DperM[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


using namespace std;

bool is_4(int y){
	if(y % 4 == 0 && y % 100 != 0)
		return 1;
	
	if(y % 400 == 0)
		return 1;
	return 0;
}



void future(int y, int m, int d, int n){
	
	DperM[2] = is_4(y)? 29:28;
	for(int i = 1; i <= n; i++){
		d++;
		if(d > DperM[m]){
			d -= DperM[m];
			m ++;
			if(m > 12){
				m -= 12;
				y ++;
				DperM[2] = is_4(y)? 29:28;
			}
		}
		
	}
	
	printf("%d/%d/%d\n",y,m,d);
}

void past(int y, int m, int d, int n){
	
	DperM[2] = is_4(y)? 29:28;
	for(int i = 1; i <= n; i++){
		d--;
		if(d < 0){
			d += DperM[m - 1];
			m --;
			if(m <= 0){
				m += 12;
				y --;
				DperM[2] = is_4(y)? 29:28;
			}
		}
		
	}
	
	printf("%d/%d/%d\n",y,m,d);
}




int main(){
	int t;
	int n;
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		future(Y, M, D, n);
		
		past(Y, M, D, n);
		
	}
	return 0;
}

