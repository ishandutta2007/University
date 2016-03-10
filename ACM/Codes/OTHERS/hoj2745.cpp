#include"cstdio"
#include"cstring"
#include"iostream"

using namespace std;


int sum[620];
int father[620];
int n;
bool connected[620][620];


int getfather(int a){
	if(father[a] == a)
		return a;
	return getfather(father[a]);
}

void cnt(int a, int b){
	//=========================/
	//my version
	//wrong
//	int fa = getfather(a);
//	father[b] = fa;
//	sum[fa] += sum[b];
	//=========================/
	int fa = getfather(a), fb = getfather(b);
    if (fa != fb) {
        father[fa] = fb;
        sum[fb] += sum[fa];
    }
}

int cal(int a){
	if(sum[a] == 1)
		return 0;
	return sum[a]*(sum[a]-1)/2;
}



int main(){
	while(scanf("%d",&n) == 1){
		int i;
		int j;
		int num,temp;
		memset(connected,0,sizeof(connected));
		for(i=0;i<n;i++){
			scanf("%d",&num);
			father[i] = i;
			sum[i] = 1;
			for(j=0;j<num;j++){
				scanf("%d",&temp);
				connected[i][temp] = 1;
				connected[temp][i] = 1;
			}
		}
//		printf("============\n");
//		for(i=0;i<n;i++)
//		{
//			for(j=0;j<n;j++)
//				printf("%d ",connected[i][j]);
//			printf("\n");
//		}
//		printf("============\n");
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(connected[i][j] == 1){
					cnt(i,j);
				}
		int ans = 0;
		
//		printf("************\n");
		for(i=0;i<n;i++)
			if(father[i] == i){
				ans += cal(i);
//				if(sum[i] > 16)
//					ans += cal(16)+(sum[i]-16)*14;
//				printf("i = %d; sum[i] = %d\n",i,sum[i]);
//				else
//					ans += cal(i);
			}
//		printf("************\n");
//		


//		for(i=0;i<n;i++)
//			for(j=i+1;j<n;j++)
//				if(getfather(i) == getfather(j))
//					ans++;
		printf("%d\n",ans);
		
	}
	return 0;
}
