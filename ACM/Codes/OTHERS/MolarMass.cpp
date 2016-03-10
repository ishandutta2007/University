#include"cstdio"
#include"iostream"
#include"cstring"


using namespace std;

char s[90];
int cnt[4];
int t;
double m[4] = {12.01,1.008,16.00,14.01};


int convert(int k){
	int ans = 0;
	while(s[k] >= '0' && s[k] <= '9'){
		ans = ans*10 + s[k]-'0';
		k++;
	}
//	printf("ans %d\n",ans);
	if(ans) return ans;
	return 1;
}


int main(){
	scanf("%d",&t);
	

	while(t--){

		memset(cnt,0,sizeof(cnt));
		memset(s,0,sizeof(s));
		scanf("%s",s);
		int i,v;
		for(i = 0;i<strlen(s);)
		{
			if(s[i] == 'C')
				v = 0;
			else if(s[i] == 'H')
				v = 1;
			else if(s[i] == 'O')
				v = 2;
			else if(s[i] == 'N')
				v = 3;
			cnt[v] += convert(++i);
//			printf("|%d|",cnt[v]);
			while(s[i] >= '0' && s[i] <= '9')
				i++;
		}
		
		printf("%.3lf\n",cnt[0]*m[0]+cnt[1]*m[1]+cnt[2]*m[2]+cnt[3]*m[3]);
	}
	
	return 0;
}
