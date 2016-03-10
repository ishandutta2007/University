#include"cstdio"
#include"iostream"

using namespace std;

int a[1000020];
int mq[1000020];

int f;
int r;

int n,k;

void Push_Asc(int i){
	while(r > f && a[mq[r - 1]] > a[i])
		r--;
	mq[r++] = i;
}
void Push_Desc(int i){
	while(r > f && a[mq[r - 1]] < a[i])
		r--;
	mq[r++] = i;
}

bool IsEmpty(){
	return f == r;
}

void Pop(){
	f++;
}
int Front(){
	return mq[f];
}


void SlidingWD(bool ascending){
	f = r = 0;
	void (*Push)(int) = ascending ? Push_Asc : Push_Desc;
	
	int i;
	
	for(i = 1; i <= k; i++){
		Push(i);
	}
	
	printf("%d",a[Front()]);
	
	for(; i <= n; i++){
		while(!IsEmpty() && Front() + k <= i) Pop();
		
		Push(i);
		
		printf(" %d",a[Front()]);
		
	}
	printf("\n");
	
}



int main(){
	
	scanf("%d%d",&n,&k);
	
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
		
	SlidingWD(true);
	SlidingWD(false);
	
	return 0;
}
