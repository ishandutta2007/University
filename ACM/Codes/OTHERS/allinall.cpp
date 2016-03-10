#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

char s[100000],t[100000];



int main(){
	int lens,lent;
	int ps;
	
	while(scanf("%s%s",s,t) != EOF){
		lens = strlen(s);
		lent = strlen(t);
		ps = 0;
		for(int i = 0; i < lent; i++){
			if(s[ps] == t[i])
				ps ++;
		}
		
		
		if(ps >= lens)
			printf("Yes\n");
		else
			printf("No\n");
	}


	return 0;
}

