#include"cstdio"
#include"iostream"

using namespace std;

int main(){
	int first = 1;
	char c;
	while(scanf("%c",&c) != EOF){
		if(c == '"'){
			printf("%s",first? "``":"''");
			first = !first;
		}
		
		else
			printf("%c",c);
	}
	
	return 0;
}
