#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 200020


int T[N*4],M;
int sub[N*4];
int W,H,n;


void seg_build(int n){
    int i,maxi;
    for(M=1;M<=H+1;M*=2);
    for(i=1;i<=n;i++){
        T[i + M] = W;
        sub[i + M] = i + M;
    }
    for(i=M-1;i;i--) {
    	if(T[i*2] >= T[i*2+1])
    		maxi = i*2;
    	else
    		maxi = i*2+1;
		T[i]=T[maxi];
		sub[i] = sub[maxi];
	}
}

void seg_update(int n,int V){
	V = T[n+M] - V;
	int maxi;
    for(T[n+=M]=V,n/=2;n;n/=2){
        if(T[n*2] >= T[n*2+1])
        	maxi = n*2;
        else
        	maxi = n*2+1;
		T[n] = T[maxi];
		sub[n] = sub[maxi];
		
		//T[n]=max(T[n*2],T[n*2+1]);
	}
}


int query(int x,int k){
	if(k > M){
		seg_update(k-M, x);
		return k-M;
	}
	if(T[k*2] >= x)
		return query(x, k*2);
	else
		return query(x, k*2+1);
}





int main()
{
     while(scanf("%d%d%d",&H,&W,&n) == 3){
        memset(T,0,sizeof(T));
        memset(sub,0,sizeof(sub));
        if(H > n)
        	H = n;
        seg_build(H);
//        printf("M:%d\n",M);
//        for(int i = 1;i<=M+H;i++)
//        	printf("T:%d sub:%d\n",T[i],sub[i]);
        
        int w;
        while(n--){
//        	for(int i = 1;i<=M+H;i++)
//        		printf("T:%d sub:%d\n",T[i],sub[i]);
            scanf("%d",&w);
            if(T[1] < w)
            	printf("-1");
            else{
            	printf("%d\n",query(w, 1));
			}
        }
    }
    return 0;
}
