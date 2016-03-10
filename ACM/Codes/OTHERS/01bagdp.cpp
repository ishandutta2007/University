#include"cstdio"
#include"iostream"

using namespace std;

int n,m;
int f[13000];
int w[3500],v[3500];



int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d %d",&w[i],&v[i]);
	
	
	for(i=1;i<=n;i++)
		for(j=m;j>=1;j--)
			if(j>=w[i])
				f[j]=max(f[j],f[j-w[i]]+v[i]);
	printf("%d\n",f[m]);
	return 0;
}
