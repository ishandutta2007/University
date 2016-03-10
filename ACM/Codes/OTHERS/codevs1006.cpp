#include"stdio.h"
#include"stdlib.h"
bool a[20000020]={0};
int right=0,left=20000000;

int _max(int a,int b)
{
	if(a>=b)
		return a;
	return b;
}

int _find(int dis){
	int i;
	int k;
	int temp=0;
	int max=0;
	for(k=0;k<dis;k++){
		temp=0;
		for(i=left+k;i<=right;i+=dis){
			if(max>(right-i)/dis)
				break;
			if(a[i]==1){
				temp++;
				// printf("temp:%d\n",temp);
				continue;
			}
			if(temp>max)
				max=temp;
			temp=0;
		}
		if(temp>max)
		max=temp;
	}
	// printf("dis:%d  max:%d\n",dis,max);
	return max;


}

int main(){
	int n,x;
	int i,j,k;
	int max=0,temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		a[x+10000000]=1;
		if(x+10000000>right)
			right=x+10000000;
		if(x+10000000<left)
			left=x+10000000;
	}
	if(right==left){
		printf("1");
		system("pause");
		return 0;
		}
	// printf("left=%d right=%d\n",left,right);
	for(i=1;i<=right-left;i++){
		if(max<(right-left)/i)
			max=_max(max,_find(i));
		// printf("%d\n",_find(i));
		}
	printf("%d",max);
	system("pause");
}