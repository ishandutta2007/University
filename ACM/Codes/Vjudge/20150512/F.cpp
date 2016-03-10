#include<map>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define LL long long

using namespace std;
int T;
LL n,m;
LL Ans,B;
int main()
{
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca ++)
    {
        scanf("%I64d%I64d", &n,&m);
        Ans=(LL)((sqrt(1.0+8.0*m)-1.0)/2.0);
        //cout<<Ans<<endl;
        B=(LL)(m)-Ans*(Ans+1)/2;
        if(B==0)
            printf("Case %d: %I64d %I64d\n",ca,Ans-1,Ans-1);
        else
            printf("Case %d: %I64d %I64d\n",ca,Ans,B-1);



    }
}

