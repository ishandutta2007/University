#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 201000
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

int r[maxn*3],sa[maxn*3];//DC3中r与sa数组的大小为3×maxn!!
int Rank[maxn],height[maxn];
int wa[maxn],wb[maxn],wv[maxn],wd[maxn];

int c0(int *r,int a,int b) {return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
int c12(int k,int *r,int a,int b){
   if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
   else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
}
void sort(int *r,int *a,int *b,int n,int m){
  int i;
  for(i=0;i<n;i++) wv[i]=r[a[i]];
  for(i=0;i<m;i++) wd[i]=0;
  for(i=0;i<n;i++) wd[wv[i]]++;
  for(i=1;i<m;i++) wd[i]+=wd[i-1];
  for(i=n-1;i>=0;i--) b[--wd[wv[i]]]=a[i];
}
void dc3(int *r,int *sa,int n,int m){//n=r最后一个元素下标+1,strlen(s)+1
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
}

void calheight(int *r,int *sa,int *height,int *rank,int n){//n==r的最后一个元素(添加的最小元素)，strlen(s);
  int i,j,k;
  for (i=1;i<=n;i++)rank[sa[i]]=i;
  for (i=0,height[0]=k=0;i<n;height[rank[i++]]=k)
     for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}

char s1[maxn],s2[maxn];
int len,l1,l2;
int h[maxn],cnt[maxn];
long long sum[maxn];

long long apple(int k,int func){
  int i,j;
  long long ret=0;
  int top=0;
  sum[0]=0;h[0]=0;cnt[0]=0;
  long long tsum;
  int tcnt=0;
  for(i=1;i<=len;++i){
    tcnt=0;
    while(top>0){
      if (h[top]<=height[i]) break;
      else {
        tcnt+=cnt[top];
        top--;
      }
    }
    if (tcnt>0&&height[i]>=k) {
      h[++top]=height[i];
      cnt[top]=tcnt;
      sum[top]=sum[top-1]+((long long)height[i]+1-k)*tcnt;
    }
    if ((sa[i]>l1)^func){
      h[++top]=maxn+10;
      cnt[top]=1;
    }
    else ret+=sum[top];

  }
  return ret;
}

int main(){
  //freopen("3415in.txt","r",stdin);
  int i,p,k;
  while(scanf("%d",&k)&&k){
    scanf("%s%s",s1,s2);
    l1=strlen(s1);l2=strlen(s2);
    p=0;
    for(i=0;i<l1;++i){
      r[p++]=s1[i]-'A'+2;
    }
    r[p++]=1;
    for(i=0;i<l2;++i){
      r[p++]=s2[i]-'A'+2;
    }
    r[p]=0;
    len=p;
    dc3(r,sa,len+1,200);
    calheight(r,sa,height,Rank,len);
    long long ans=apple(k,0)+apple(k,1);
    printf("%I64d\n",ans);
  }
  return 0;
}
