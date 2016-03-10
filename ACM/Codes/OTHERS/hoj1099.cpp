#include"stdlib.h"
#include"stdio.h"
#include"algorithm"
#include"math.h"
using namespace std;

int N;
double point[720][2];
double lines[492000][2];


bool cmp(int a,int b){
	if(lines[a][0]>lines[b][0])
		return 1;
	if(lines[a][0]==lines[b][0] && lines[a][1]>lines[b][1])
		return 1;
	return 0;
}

void swap(int a,int b){
	double temp1,temp2;
	temp1=lines[a][0];
	temp2=lines[a][1];
	lines[a][0]=lines[b][0];
	lines[a][1]=lines[b][1];
	lines[b][0]=temp1;
	lines[b][1]=temp2;
	return;
}




void _sort(int n){
	int i,j;
	for(i=1;i<=n;i++){
		int max=i;
		for(j=i;j<=n;j++){
			if(cmp(max,j))
				max=j;
			
		}
		swap(max,i);
	}
}


int main(){
	
	int i,j;
	
	while(1){
		scanf("%d",&N);
		if(N==0)
			break;
		
		for(i=1;i<=N;i++)
			scanf("%lf %lf",&point[i][0],&point[i][1]);
		int count=0;
		for(i=1;i<=N;i++)
			for(j=i+1;j<=N;j++)
				//not vertical
				if(point[i][0]!=point[j][0]){
					count++;
					lines[count][0]=double((point[j][1]-point[i][1])/(point[j][0]-point[i][0]));
					lines[count][1]=double(point[i][1]-(point[i][0]*lines[count][0]));
				}
//		int temp[720]={0};
		int max=0;
		int temp;
		for(i=1;i<=N;i++){
			temp=1;
			for(j=i+1;j<=N;j++)
				if(point[i][0]==point[j][0])
					temp++;
			if(max<temp)
				max=temp;
		}
//		
//		printf("Unsorted\n");
//		for(i=1;i<=count;i++)
//			printf("%lf %lf\n",lines[i][0],lines[i][1]);
		
		_sort(count);
//		
//		printf("Sorted\n");
//		for(i=1;i<=count;i++)
//			printf("%lf %lf\n",lines[i][0],lines[i][1]);
		
		
		
		//how to sort the lines
//		sort(lines+1,lines+count+1);
//		int max=0;
		temp=1;
		for(i=1;i<=count;i++){
			if(fabs(lines[i][0]-lines[i-1][0])<1e-6 && fabs(lines[i][1]-lines[i-1][1])<1e-6)
				temp++;
			else{
				if(temp>max)
					max=temp;
				temp=1;
			}
		}
		if(temp>max)
			max=temp;
		printf("%d\n",max);
	}
	
	return 0;
	
}
