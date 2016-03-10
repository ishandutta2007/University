#include <iostream>
#include <stdio.h>
using namespace std;
int i,j,n,a[100020],b[100020],c[100020];
int find(int *a,int len,int n)
{
    int left=0,right=len,mid=(left+right)/2;
    while(left<=right)
    {
        if(n>a[mid]) left=mid+1;
        else if(n<a[mid]) right=mid-1;
        else return mid;
        mid=(left+right)/2;
    }
    return left;
}


int main(void)
{

    int T;
    int max = 0;
    scanf("%d", &T);
    for(int ka = 1; ka <= T; ka++)
    {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            a[i] -= i;
        }
        c[0]=-1;
        c[1]=a[0];
        b[0]=1;
        for(i=1;i<n;i++)
        {
            j=find(c,n+1,a[i]);
            c[j]=a[i];
            b[i]=j;
        }
        for(max=i=0;i<n;i++)
            if(b[i]>max)
                max=b[i];
       printf("Case #%d:\n%d\n", ka, n - max);
    }
    return 0;
}
