#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = int(4e6)+10;

int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}
int wa[N],wb[N],ws[N],wv[N];
int height[N], rank[N];

// void da(int *r,int *sa,int n,int m){
//     int i,j,p,*x=wa,*y=wb;
//     for(i=0;i<m;i++) ws[i]=0;
//     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
//     for(i=1;i<m;i++) ws[i]+=ws[i-1];
//     for(i=n-1;i>=0;i--) sa[--ws[x[i]]] = i;
//     for(j=1,p=1;p<n;j*=2,m=p)
//     {
//         for(p=0,i=n-j;i<n;i++) y[p++]=i;
//         for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
//         for(i=0;i<m;i++) ws[i]=0;
//         for(i=0;i<n;i++) wv[i]=x[y[i]];
//         for(i=0;i<n;i++) ws[wv[i]]++;
//         for(i=1;i<m;i++) ws[i]+=ws[i-1];
//         for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
//         for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
//             x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
//     }
// }
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int c0(int *r,int a,int b)
    {return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
    int c12(int k,int *r,int a,int b)
    {if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];}
    void sort(int *r,int *a,int *b,int n,int m)
    {
        int i;
        for(i=0;i<n;i++) wv[i]=r[a[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) b[--ws[wv[i]]]=a[i];
        return;
    }
    void dc3(int *r,int *sa,int n,int m) //涵义与DA 相同
    {
        int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
        r[n]=r[n+1]=0;
        for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
        sort(r+2,wa,wb,tbc,m);
        sort(r+1,wb,wa,tbc,m);
        sort(r,wa,wb,tbc,m);
        for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
        if(p<tbc) dc3(rn,san,tbc,p);
        else for(i=0;i<tbc;i++) san[rn[i]]=i;
        for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
        if(n%3==1) wb[ta++]=n-1;
        sort(r,wb,wa,ta,m);
        for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
        for(i=0,j=0,p=0;i<ta && j<tbc;p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
        for(;i<ta;p++) sa[p]=wa[i++];
        for(;j<tbc;p++) sa[p]=wb[j++];
        return;
    }
void calheight(int *r,int *sa, int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n; height[rank[i++]] = k )
        for(k?k--:0,j=sa[rank[i]-1]; r[j+k]==r[i+k];k++);
}


char s1[N], s2[N];
int r[N], n1, n2, n;
int sa[N];

int main(){


	// printf("%d\n", 'a'-1);
    while( scanf("%s%s",s1,s2) != EOF)
    {
        n1 = strlen(s1); n2 = strlen(s2);
        // {0,n1-1}, n1+{ 1,n2 }
        for(int i = 0; i < n1; i++)
            r[i] = s1[i] - 'a' + 2;
        r[n1] = 1;
        for(int i = 0; i < n2; i++)
            r[ n1+1+i ] = s2[i] - 'a' + 2;
        r[n1+n2+1] = 0;
        n = n1+n2;

        dc3(r,sa,n+1,30);
        calheight(r,sa,n);
        int Max = 0, st;
        for(int i = 2; i <= n; i++)
        {
            if( height[i] > Max ){
                if( (sa[i-1]<n1&&sa[i]>n1) || (sa[i-1]>n1&&sa[i]<n1) )
                    Max = height[i], st = sa[i]>n1?sa[i-1]:sa[i];
            }
        }
        printf("%d\n", Max);
       /* for(int i = 0; i < Max; i++)
            printf("%c", s1[st+i]);
        puts("");*/
    }
    return 0;
}