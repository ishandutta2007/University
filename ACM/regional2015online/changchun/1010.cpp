#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <deque>
#define maxn 200
#define maxm 200002
#define inf 0x3f3f3f3f
using namespace std;

typedef unsigned long long llg;






llg Extend_Euclid(llg a, llg b, llg &x, llg &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    llg d = Extend_Euclid(b,a%b,x,y);
    llg t = x;
    x = y;
    y = t - a/b*y;
    return d;
}
//求解模线性方程组x=ai(mod ni)
llg China_Reminder(int len, llg* a, llg* n)
{
    int i;
    llg N = 1;
    llg result = 0;
    for(i = 0; i < len; i++)
        N = N*n[i];
    for(i = 0; i < len; i++)
    {
        llg m = N/n[i];
        llg x,y;
        Extend_Euclid(m,n[i],x,y);
        x = (x%n[i]+n[i])%n[i];
        result = (result + m*a[i]*x%N)%N;
    }
    return result;
}

//快速幂
llg pow(llg a,llg k,llg p)
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

//Lucas定理(求组合数取模)
llg com(llg n,llg m,llg p)
{
	if (m>n) return 0;
	llg ans=1;
	for (int i=1;i<=m;i++)
	{
		ans=ans*(n-i+1)%p;
		ans=ans*pow(i,p-2,p)%p;
	}
	return ans;
}

llg lucas(llg n,llg m,llg p)
{
	if (m==0) return 1;
	return (com(n%p, m%p, p)*lucas(n/p, m/p, p))%p;
}

llg r[maxn],p[maxn];
llg n,m;
int k;

int main()
{
	int Case;
	scanf("%d",&Case);
	while (Case--)
	{
		scanf("%I64u%I64u%d",&n,&m,&k);
		llg pp=1;
		for (int i=0;i<k;i++)
		{
			scanf("%I64u",&p[i]);
			r[i]=lucas(n,m,p[i]);
		}
		printf("%I64u\n",China_Reminder(k,r,p));
	}
	return 0;
}