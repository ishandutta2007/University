#include"cstdio"
#include"iostream"
#include"cstring"


using namespace std;


int a[1020][1020];

int main(){
	int n;
	int tmp;
	while(scanf("%d",&n) == 1)
	{
		memset(a,0,sizeof(a));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= i; j++)
			{
				scanf("%d",&a[i][j]);
				a[i][j] += max(a[i-1][j], a[i-1][j-1]);
			}
			
		tmp = 0;
		for(int i = 1; i <= n; i++)
			tmp = max(tmp,a[n][i]);
			
		printf("%d\n",tmp);
	}
	
	
	
	return 0;
}
