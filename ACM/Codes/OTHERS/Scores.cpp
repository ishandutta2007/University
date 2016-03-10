#include"cstdio"
#include"iostream"
#include"cstring"

using namespace std;

char s[90];
int t;

int main(){
	scanf("%d",&t);
	
	while(t--){
		scanf("%s",s);
		int scores = 0;
		int tmp = 0;
		for(int i = 0; i < strlen(s); i++){
			if(s[i] == 'O'){
				tmp++;
				scores += tmp;
			}
			else
				tmp = 0;
			
		}
		printf("%d\n",scores);
	}
	
	return 0;
	
}
