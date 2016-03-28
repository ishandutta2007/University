/*
 *	math templates
 *	created by poore : 2015/09/14
 *	last edit : 2015/10/19
 *	
 *	Contents:
 *
 *	GCD
 *	ext_GCD
 *	筛法求素数
 *	slow_mul
 *	linear_mod_equation 一元线性方程组求解
 *	pow_mod
 *	Lucas Lehmer 判定梅森素数
 *	miller robbin 素数判定
 *	pollard rho 返回一个随机的约数
 *	calc 寻找最小的约数
 *	mega_mod(n)解 n 个一元线性同于方程组
 *	CRT() 中国剩余定理
 *	欧拉函数
 *	整数拆分
 *	Stirling's approximation
 */


#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define INF 0x3f3f3f3f
typedef long long LL;


using namespace std;

const int MOD = 1e9+7;


//GCD
LL GCD(LL a, LL b)
//递归
{
	if(a > b) swap(a, b);
	LL r = a % b;
	if(r == 0) return b;
	return GCD(b, r);
}

LL gcd(LL M,LL N)
//非递归
{
	LL Rem;
	while(N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}

void EXT_GCD(LL a, LL b, LL &d, LL &x, LL &y)
//a , b 任意
{
	if(!b) {d = a, x = 1, y = 0;}
	else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}

//递归求逆元
//p, x 互质
LL inv(LL x, LL m)
{
	if (x == 1) return x;
	return inv(m % x, m)*(m - m / x) % m;
}


ll inv(LL a, LL c)
// 用扩展欧几里得求逆元
// 要求 a, c 互质
// 如果没有逆元返回 -1
{
	LL d, x, y;
	EXT_GCD(a, c, d, x, y);
	return d == 1 ? (x + c) % c : -1;
}
LL ext_gcd(LL a, LL b, LL& x, LL& y)
// a >= 0, b > 0
{
	LL x1=0LL, y1=1LL, x0=1LL, y0=0LL;
	LL r = (a%b + b) % b;
	LL q = (a-r) / b;
	x = 0LL,y = 1LL;	
	while(r)
	{
		x=x0-q*x1;y=y0-q*y1;
		x0=x1;y0=y1;
		x1=x;y1=y;
		a=b;b=r;
		r=a%b;
		q=(a-r)/b;
	}
	return b;
}

const int maxn = 100020;
bool isprime[maxn];
LL prime[maxn];
int doprime(LL N)
//prime[] 储存质数。1-based index;
{
	int nprime = 0;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for(LL i = 2; i <= N; i++)
	{
		if(isprime[i])
		{
			prime[++nprime] = i;
			for(LL j = i*i; j <= N; j+=i)
				isprime[j] = false;
		}
	}
	return nprime;
}


LL slow_mul(LL a, LL b, LL p)
{
	// cout << a << " " << b << endl;
	LL ret = 0;  
	while(b) {  
		if(b & 1) ret = (ret + a) % p;  
		a = (a + a) % p;
		b >>= 1;  
	}  
	return ret % p;  
}  
  
LL pow_mod(LL a, LL b, LL p)
//快速幂   
{
	LL ret = 1;  
	while(b) {  
		if(b & 1) ret = (ret*a)%p;  
		a = (a*a)%p;  
		b >>= 1;  
	}  
	return ret%p;  
}  


//判断Mp = 2^p-1 是否为梅森素数
bool lucas_lehmer(int p)
{
	if(p == 2) return true;
	LL m = (1LL<<p)-1LL, tmp = 4LL;
	for(int i = 0; i < p-2; i++)
	{
		tmp = (slow_mul(tmp, tmp, m) - 2 + m) % m;
	}
	if(tmp == 0LL) return true;
	return false;
}

LL witness(LL a,LL b,LL c)
{
	if(b==0)return 1;
	LL x,y,t=0;
	while((b&1)==0)
		b>>=1,t++;
	y=x=pow_mod(a,b,c);
	//二次探测
	while(t--)
	{
		y=slow_mul(x,x,c);
		if(y==1 && x!=1 && x!=c-1)
			return false;
		x=y;
	}
	return y==1;
}
bool miller_rabin(LL n)
//..质数为true, 非质数为false..
{
	if(n==2)return true;
	if(n<2 || (n&1)==0)return false;
	for(int i=0;i<3;i++)
		if(witness(rand()%(n-2)+2,n-1,n)!=1)
			return false;
	return true;
}


LL ans = INF;
LL pollard_rho(LL n,LL c)
//..随机返回一个 n 的约数..
{
	if(n%2==0)return 2;
	LL i=1,k=2,x=rand()%n,y=x,d;
	while(1){
		i++;
		x=(slow_mul(x,x,n)+c)%n;
		d=gcd(y-x,n);
		if(d==n)return n;
		if(d!=n && d>1)return d;
		if(i==k) y=x,k<<=1;
	}
}
void calc(LL n,LL c=240)
//寻找最小的约数..
{
	if(n==1)return;
	if(miller_rabin(n)){
		ans=min(ans,n);
		return;
	}
	LL k=n;
	while(k==n)k=pollard_rho(n,c--);
	calc(k,c),calc(n/k,c);
}


vector<LL> linear_mod_equation(LL a, LL b, LL n)
//线性方程求解
//ax = b (mod n)
{
    LL x, y, d;
    vector<LL> sol;
    sol.clear();
    EXT_GCD(a, n, d, x, y);
    if( b%d ) d = 0;
    else
    {
        sol.push_back(x * (b/d) % n);
        for (int i = 1; i < d; i++)
            sol.push_back((sol[i-1] + n/d + n) % n);
    }
    return sol;
}
LL mega_mod(int n)
//解 n 个一元线性同于方程组
//x ≡ r (mod a)
//求x
{
	LL a1, a2, r1, r2, d, c, x, y, x0,s;
	bool flag = true;
	scanf("%lld%lld", &a1, &r1);
	for(int i = 1; i < n; i++)
	{
		scanf("%lld%lld", &a2, &r2);
		if(!flag) continue;
		c = r2 - r1;
		EXT_GCD(a1, a2, d, x, y);
		if(c%d!=0)
		{
			flag = false;
			continue;
		}
		x0 = x*c/d;
		s = a2/d;
		x0 = (x0%s+s)%s;
		r1=r1+x0*a1;
		a1=a1*a2/d;
	}
	if(flag) return r1;
	else return -1LL;
}

LL CRT(LL *a, LL *m, int n)
//中国剩余定理
//x ≡ a[i] (mod m[i])
//m[i] is coprime
{
	LL M = 1, Mi, x0, y0, d, ret = 0;
	for(int i = 0; i < n; i++)
		M *= m[i];
	for(int i = 0; i < n; i++)
	{
		Mi = M/m[i];
		EXT_GCD(Mi, m[i], d, x0, y0);
		ret = (ret+Mi*x0*a[i]) % M;
	}
	if(ret < 0)
		ret += M;
	return ret;
}

//欧拉函数
LL calphi(LL n)
{
	LL res = n;
	for(LL i = 2; i*i <= n; i++)if(n%i==0)
	{
		res -= res/i;
		while(n%i==0) n/=i;
	}
	if(n > 1)
		res -= res/n;
	return res;
}

//欧拉函数预处理
int phi[maxn];
void getpthi(int n)
{
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	for(int i = 2; i <= n; i++)if(!phi[i])
	{
		for(int j = i; j <= n; j+=i)
		{
			if(!phi[j])
				phi[j] = j;
			phi[j] = phi[j]/i*(i-1);
		}
	}
}



//把整数 n 拆分成几个数相加的形式， 问有多少种拆分方法
int dp[maxn];
void splitint()
{
	memset(dp, 0, sizeof(dp));
	dp[0]=1;
	for(int i = 1; i <= maxn; i++)
	{
		for(int j = 1, r = 1; i - (3*j*j-j)/2 >= 0; j++, r*=-1)
		{
			dp[i] += dp[i-(3*j*j-j)/2]*r;
			dp[i] %= MOD;
			dp[i] = (dp[i]+MOD)%MOD;
			if(i-(3*j*j+j)/2 >= 0)
			{
				dp[i] += dp[i-(3*j*j+j)/2] *r;
				dp[i] %= MOD;
				dp[i] = (dp[i] + MOD)%MOD;
			}
		}
	}
}

//Stirling N的阶乘的长度
const double PI=3.1415926;
int main()
{
	int t,n,a;
	while(scanf("%d",&n)!=EOF)
	{
		a=(int)((0.5*log(2*PI*n)+n*log(n)-n)/log(10));
		printf("%d\n",a+1);
	}
	return 0;
}



/*

Something Tasteless

1.素数个数估算
	设PI(x) 为小于 x 的素数的个数
	当 x 足够大时，PI(x) = x/lnx;
2.n! 的素因子分解中的素数 p 的次数 为
	[n/p] + [n/(p^2)] + [n/(p^3)] + ... +



3.

*/
