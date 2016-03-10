#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define maxn 32000

typedef long long LL;

bool npri[maxn];
vector<int>pri;
bool seg[1000000020];



// void init()
// {

//     for(int i = 2; i < maxn; i++)
//         if(!npri[i])
//         {
//             pri.push_back(i);
//             for(int j = i * 2; j < maxn; j += i)
//                 npri[j] = true;
//         }
// }
bool isprime[maxn];
LL prime[maxn];
int doprime(LL N)
{
    int nprime = 0;
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for(LL i = 2; i < N; i++)
    {
        if(isprime[i])
        {
            pri.push_back(i);
            prime[++nprime] = i;
            for(LL j = i*i; j < N; j+=i)
                prime[j] = false;
        }
    }
    
    return nprime;
    
}
void getseg(int n, int m)
{
    memset(seg, 0, sizeof(seg));


    for(int i = 0, len = pri.size(); i < len; i++)
    {
        int M = pri[i];
        if(M > m) break;
        int start = ceil(n*1.0/pri[i]), end = floor(m*1.0/pri[i]);

        // printf("!!!!%d %d %d\n", M, start, end);
        // system("pause");
        for(int j = max(start,2); j <= end; j++)
            seg[j*M] = true;
    }

}


int main()
{
    doprime(maxn);
    int T, n , m;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        
        if(n == 1) n++;
        getseg(n, m);

        for(int i = n; i <= m; i++)
            if(seg[i] == 0) printf("%d\n", i);

        printf("\n");
    }

}