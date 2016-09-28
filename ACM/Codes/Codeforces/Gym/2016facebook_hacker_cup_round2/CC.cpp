#include<stdio.h>
#include<algorithm>

#define MOD 1000000007

using namespace std;

struct data{
    long long x, h;
} ladder[200005];

long long sta[200005][4];
long long ans;
int top;

bool comp(data X, data Y)
{
    if(X.x<Y.x)
        return 1;
    return 0;
}

int main(void)
{
    int T;
    int test_case;
    int n, i;

    freopen("data2.in","r",stdin);
    scanf("%d",&T);
    for(test_case = 1 ; test_case <=T ; test_case++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%lld %lld ",&ladder[i].x, &ladder[i].h);

        sort(ladder+1, ladder+n+1, comp);

        top=0;
        sta[0][0]=1000000005;
        ans=0;
        for(i=1;i<=n;i++)
        {
            while(1)
            {
                if(sta[top][0]<ladder[i].h)
                    top--;
                else
                    break;
            }
            if(sta[top][0]>ladder[i].h)
            {
                ++top;
                sta[top][0] = ladder[i].h;
                sta[top][1] = ladder[i].x;
                sta[top][2] = ladder[i].x * ladder[i].x % MOD;
                sta[top][3] = 1;
            }
            else if(sta[top][0] == ladder[i].h)
            {
                ans += (ladder[i].x * ladder[i].x % MOD) * sta[top][3];
                ans %= MOD;
                ans += sta[top][2];
                ans -= (sta[top][1]*ladder[i].x % MOD) * 2;
                ans %= MOD;
                sta[top][1] += ladder[i].x;
                sta[top][1] %= MOD;
                sta[top][2] += ladder[i].x * ladder[i].x % MOD;
                sta[top][2] %= MOD;
                sta[top][3] ++;
            }
        }
        ans%=MOD;
        ans+=MOD;
        ans%=MOD;
        printf("Case #%d: %lld\n",test_case,ans);
    }
}
