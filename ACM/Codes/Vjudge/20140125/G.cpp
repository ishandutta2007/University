#include"cstdio"
#include"iostream"
#include"cstring"


using namespace std;

int si[30];
char ss[30][30];

bool toint(int n){
	si[n] = 0;
	for(int i = 0; i < strlen(ss[n]); i++){
		if(ss[n][i] >= '0' && ss[n][i] <= '9')
			si[n] = si[n]*10 + ss[n][i] - '0';
			
		else
			return 0;
	}
	
	return 1;
	
}

int main(){
	int cnt = 0;
	int n;
	while(scanf("%d",&n) == 1){
		getchar();
		memset(ss,0,sizeof(ss));
		memset(si,0,sizeof(si));
		bool wrong = false;
		cnt++;
		for(int i = 1; i <= n; i++){
			scanf("%s",ss[i]);
			if(i % 2 == 1 && !toint(i))
				wrong = true;
			if(i % 2 == 0 && !(strcmp(ss[i],"*") == 0 || strcmp(ss[i], "+") == 0))
				wrong = true;
		}
		
		if(wrong || n % 2 == 0){
			printf("Case %d: Invalid Expression!\n",cnt);
			continue;
		}
		
		long long ans = 0;
		long long tmp = si[1];
		for(int i = 2; i <= n; i+=2){
			if(strcmp(ss[i], "+") == 0){
				ans += tmp;
				tmp = si[i+1];
			}
			else{
				tmp *= si[i+1];
			}
		}
		ans += tmp;
		printf("Case %d: %I64d\n",cnt,ans);
	}
	
	
	return 0;
}
