#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
long long int a[300000],sum[300000];
long long int n,k,x,ans,num,b,c;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&k,&x);
	num=1;
	for (int i=1;i<=k;i++) num*=x;

	sum[0]=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+1+n);

	for (int i=1;i<=n;i++) sum[i]=sum[i-1]|a[i];
	ans=0;c=0;
	for (int i=n;i>=1;i--)
	{
		b=(sum[i-1])|(a[i]*num)|c;
		c|=a[i];
		ans=max(ans,b);
	}
	printf("%I64d\n",ans);
}