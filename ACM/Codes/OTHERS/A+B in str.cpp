#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;



char s[100];

int number(int l, int r){
	int n = r - l + 1;
	if(n == 3){
		if(s[l] == 'o')
			return 1;
		if(s[l] == 't')
			return 2;
		if(s[l] == 's')
			return 6;
	}
	if(n == 4){
		if(s[r] == 'r')
			return 4;
		if(s[l] == 'f')
			return 5;
		if(s[l] == 'n')
			return 9;
		if(s[l] == 'z')
			return 0;
		
	}
	
	if(n == 5){
		if(s[l] == 'e')
			return 8;
		if(s[l] == 's')
			return 7;
		if(s[l] == 't')
			return 3;
	}
}


int getnumber(int l,int r){
	int p1 = l, p2;
	int ans = 0;
	
	for(int i = l + 1; i <= r; i++){
		if(s[i] == ' '){
			ans = ans*10 + number(p1, i-1);
			p1 = i+1;
		}
	}
	
	
	return ans;
	
}



int main(){
	int a, b;
	
	int pos1,pos2;
	
	while(1){
		memset(s,0,sizeof(s));
		
		gets(s);
		
		for(int i = 0; i < strlen(s); i++){
			if(s[i] == '+')
				pos1 = i;
			else if(s[i] == '=')
				pos2 = i;
		}
			a = getnumber(0,pos1-1);
			b = getnumber(pos1 + 2, pos2 - 1);
//			printf("%d %d\n",a,b);
			if(a == 0 && b == 0)
				return 0;
			else
				printf("%d\n",a + b);
		
	}

	return 0;
}

