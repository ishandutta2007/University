#include<stdio.h>  
#include<math.h>  
#define mod 1000000007  
#define ll long long
ll get_phi(ll x)// 就是公式     
{    
	ll i, res=x;    
	for (i = 2; i <(ll)sqrt(x * 1.0) + 1; i++)    
		if(x%i==0)    
		{    
			res = res / (ll)i * (i - 1);    
			while (x % i == 0) x /= i;
		}    
		if (x > 1) res = res / (ll)x * (x - 1); 
		return res;    
}
int main()
{  
	ll n,ans;  
	while(scanf("%I64d",&n)!=EOF)  
	{  
		if(!n) break;  
		ans=((ll)(1+n-1)*(n-1)/2-(ll)n*get_phi(n)/2)%mod;
		printf("%I64d\n",ans%mod);  
	}  
	return 0;  
}  