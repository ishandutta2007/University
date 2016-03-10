#include"cstdio"
#include"cstring"
#include"iostream"
#define maxn 200020


using namespace std;


int M;
int SegTree[maxn * 4];
int n;


int query(int l,int r){
	int maxmarks = 0;
	for(l = l + M -1,r = r + M +1; l^r^1; l /= 2, r /= 2){
		if(l%2 == 0) maxmarks = max(maxmarks, SegTree[l^1]);
		if(r%2 == 1) maxmarks = max(maxmarks, SegTree[r^1]);
	}
	return maxmarks;
}


void update(int sub,int a){
	//to be understood!!!!  attention
	for(SegTree[sub += M] = a, sub /= 2; sub; sub /= 2)
		//you made a mistake here before ,  pay attention!!!!!!!!
		SegTree[sub] = max(SegTree[sub*2], SegTree[sub*2 + 1]);
	
	
	return;
}







int main(){
	int cnt_cmd;
	
	while(scanf("%d%d",&n,&cnt_cmd) != EOF){
		memset(SegTree, 0, sizeof(SegTree));
		M = 1;
		// ?1D¨¨????¨º?¡¤? n + 1 ¦Ì??¨º¨¬a 
		while(M <= n + 1) M *= 2;
//		for(M = 1;M <= n+1; M *= 2);
		for( int i = 1; i <= n; i++)
			scanf("%d", &SegTree[i + M]);
		for(int i = M - 1; i >= 1 ; i--)
			SegTree[i] = max(SegTree[i*2],SegTree[i*2 + 1]);
		
		
//		for(int i = 1; i <= M * 2; i++)
//			printf("%d ",SegTree[i]);
		char cmd[5];
		int x,y;
		for(int i = 1; i <= cnt_cmd; i++){
			scanf("%s%d%d",cmd,&x,&y);
//			printf("%d %d %d\n",strcmp(cmd, "Q"),x,y);
			if(strcmp(cmd, "Q") == 0)
				printf("%d\n",query(x, y));
			else if(strcmp(cmd, "U") == 0)
				update(x, y);			
			
		}
		
	}
	
	return 0;
}

