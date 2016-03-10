#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

LL F[100010];
void init(LL p)
{
	F[0] = 1;
	for(int i = 1;i <= p;i++)
		F[i] = F[i-1]*i%p;
}
LL inv(LL a,LL m)
{
    if(a == 1)return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
LL Lucas(LL n,LL m,LL p)
{
	LL ans = 1;
	while(n&&m)
	{
		LL a = n%p;
		LL b = m%p;
		if(a < b)return 0;
		ans = ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
		n /= p;
		m /= p;
	}
	return ans;
}

int main()
{
    int T;
	int n,m,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&p);
		init(p);
		printf("%d\n",(int)Lucas(n+m,n,p));
	}
    return 0;
}