#include <bits/stdc++.h>
#define maxn 120000
using namespace std;
typedef long long LL;
LL p[maxn],a[maxn];
vector<LL> b[20];
vector<LL> q, e;
int n;
LL low, high;



// 扩展欧几里得
// a , b 任意
void EXT_GCD(LL a, LL b, LL &d, LL &x, LL &y)
{
  if(!b) {d = a, x = 1, y = 0;}
  else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}
// 慢速乘
// a * b % p;
LL slow_mul(LL a, LL b, LL p)
{
  if (b < 0 && a >= 0) swap(a, b);
  else if (a < 0 && b < 0) {a = -a; b = -b;}
  LL ret = 0;  
  while(b) {  
    if(b & 1) ret = (ret + a) % p;  
    a = (a + a) % p;
    b >>= 1;  
  }  
  return ret % p;  
}
// 中国剩余定理
// x ≡ a[i] (mod m[i])
// m[i] is coprime
LL CRT(vector<LL> a, vector<LL> m)
{
  int n = a.size();
  printf("=====\n");
  for (int i = 0; i < n; i++)
  	printf("%I64d %I64d\n", a[i], m[i]);
  LL M = 1, Mi, x0, y0, d, ret = 0;
  for(int i = 0; i < n; i++)
    M *= m[i];
  for(int i = 0; i < n; i++)
  {
    Mi = M/m[i];
    EXT_GCD(Mi, m[i], d, x0, y0);
    
    LL tmp = slow_mul(Mi, x0, M);
    tmp = slow_mul(tmp, a[i], M);
    ret = (ret + tmp) % M;
    //ret = (ret+Mi*x0*a[i]) % M;
  }
  if(ret <= 0)
    ret += M;
  printf("ret = %I64d\n", ret);
  return ret;
}

int count(int x)
{
	int tmp=0;
	while (x)
	{
		tmp+=(x&1);
		x>>=1;
	}
	return tmp;
}

int main()
{
  freopen("data.in", "r", stdin);
	int Case;
	scanf("%d",&Case);
	for (int o=1;o<=Case;o++)
	{
		scanf("%d%I64d%I64d",&n, &low, &high);
		int x,y;
		for (int i=0;i<n;i++)
			scanf("%I64d%I64d",&p[i], &a[i]);
		for (int msk=1;msk<=(1<<n)-1;msk++)
			b[count(msk)].push_back(msk);
		LL ans=high/7-(low-1)/7;
		for (int len=1;len<=n;len++)
			for (int j=0,ss=b[len].size();j<ss;j++)
			{
				int msk=b[len][j];
				q.clear(); e.clear();
				for (int i=0;i<n;i++)
					if ((msk>>i)&1)
					{
						q.push_back(p[i]);
						e.push_back(a[i]);
					}
				q.push_back(7);
				e.push_back(0);
				cout<<msk<<endl;
				for (int i=0;i<q.size();i++) cout<<q[i]<<' '; cout<<endl;
				for (int i=0;i<q.size();i++) cout<<e[i]<<' '; cout<<endl;
				LL tmp=CRT(e, q);
				printf("tmp = %I64d\n", tmp);

				if (len&1) ans-=(high/tmp-(low-1)/tmp);
				else ans+=(high/tmp-(low-1)/tmp);
			}
		printf("Case # : %I64d\n",ans);
	}
	return 0;
}
