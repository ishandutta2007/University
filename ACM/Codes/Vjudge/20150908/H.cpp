#include <iostream>
#include <cstdio>
#include <cmath>
#define p 1000000007

using namespace std;

typedef long long llg;

llg Pow(llg a,llg k)
{
	llg tmp=1;
	while (k)
	{
		if (k&1) tmp=tmp*a%p;
		k=k/2;
		a=a*a%p;
	}
	return tmp;
}

llg Com(llg n,llg m)
{
	if (m>n) return 0;
	llg ans=1;
	for (int i=1;i<=m;i++)
	{
		ans=ans*(n-i+1)%p;
		ans=ans*Pow(i,p-2)%p;
	}
	return ans;
}

llg lucas(llg n,llg m)
{
	if (m==0) return 1;
	return (Com(n%p,m%p)*lucas(n/p,m/p))%p;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%I64d\n",Com(2*(n+1),n+1)-1);
	return 0;
}