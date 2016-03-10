#include"stdio.h"



int a[100];
int _count=0;

void _swap(int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
//    return;
// return problem!!!!!!!!!!!!!!!!!!!!!
}


int check(int k,int j){
    for(int i=k;i<j;i++)
        if(a[i]==a[j])
            return 0;
    return 1;
}


void permutation(int k,int m){
    if(k==m){
        for(int i=1;i<=m;i++)
            printf("%d ",a[i]);
        printf("\n");
        _count++;
//        return;
    }
    for(int j=k;j<=m;j++)
        if(check(k,j)==1){
        _swap(j,k);
        permutation(k+1,m);
        _swap(j,k);
//        return;
    }



}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    permutation(1,n);
    printf("%d\n",_count);
    return 0;
}

