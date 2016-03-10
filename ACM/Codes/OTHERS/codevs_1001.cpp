#include"iostream"
#include"algorithm"
#include"cstdio"



#define MAXN 520
#define MAXM 500200

using namespace std;

int father[MAXN];
int x[MAXM],y[MAXM],v[MAXM];


int getgys(int a,int b)
{
	if(a%b==0)
		return b;
	else
		return getgys(b,a%b);

}



void output(int a,int b){
	if(a%b==0)
		printf("%d\n",a/b);
	
	
	else{
		int gys=getgys(a,b);
		printf("%d/%d\n",a/gys,b/gys);
	
	}

	return;

}



void _swap(int a,int b){
	int temp;
	temp=v[a];
	v[a]=v[b];
	v[b]=temp;

	temp=x[a];
	x[a]=x[b];
	x[b]=temp;

	temp=y[a];
	y[a]=y[b];
	y[b]=temp;
	return;
}


void sort(int m){
	int i,j;
	int max;
	for(i=1;i<=m;i++){
	max=i;
		for(j=i+1;j<=m;j++){
			if(v[max]>v[j])
				max=j;
		
		}
		_swap(max,i);
	}
	return;
}


int findfather(int a){
	while(1){
		if(father[a]==a)
			return a;
		a=father[a];
	}
}


void unionset(int a,int b){
	a=findfather(a);
	father[a]=findfather(b);
	return;
}


int main(){
	int n,m;
	int i,j;
	int s,t;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		father[i]=i;
	
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&x[i],&y[i],&v[i]);

	sort(m);
//	printf("sort complete\n");
//	for(i=1;i<=m;i++)
//		printf("v : %d x : %d y : %d\n",v[i],x[i],y[i]);
	scanf("%d%d",&s,&t);
	for(i=1;i<=m;i++){
//		printf("s : %d t : %d\n",findfather(s),findfather(t));
		if(findfather(s)==findfather(t))
			break;
//		printf("!!!%d\n",v[i]);
		if(findfather(x[i])!=findfather(y[i]))
			unionset(x[i],y[i]);
//		printf("x : %d y : %d\n",findfather(x[i]),findfather(y[i]));
//		printf("step : %d\n",i);
	}
//	printf("union complete\n");
//	printf("i : %d\n",i);
	if(findfather(s)==findfather(t)){
//		printf("%d %d\n",v[1],v[i-1]);
		output(v[1],v[i-1]);
	}
	else
		printf("IMPOSSIBLE\n");
	return 0;

}
