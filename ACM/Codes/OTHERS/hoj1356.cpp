#include"iostream"
#include"cstdio"
#include"cmath"
#define MAXN 50001

bool isprime[MAXN];
int prime[MAXN], nprime;


void doprime() //É¸·¨É¸Ñ¡ËØÊý
{
    long long i,j;
    nprime = 0;
    memset(isprime, true, sizeof(isprime));
    isprime[1] = 0;
    for(i = 2; i < MAXN; i++)
    {
        if(isprime[i]){
            prime[nprime++] = i;
            for(j = i * i; j < MAXN; j += i)
                isprime[j] = false;
        }
    }
    return;
}

bool isPrime(long long n)
{

    if(n % 2 == 0)
        return false;

    int k = sqrt(n);
    for(int i = 0; prime[i] <= k; i ++)
        if(n % prime[i] == 0)
            return false;
    return true;
}





int main(){

    unsigned n;
    doprime();
    while(scanf("%u", &n) == 1)
    {
        if(n == 1)
            printf("NO\n");
        else if(n < MAXN)
        {
            isprime[n] ? printf("YES\n") : printf("NO\n");
        }
        else
        {
            if(isPrime(n))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
