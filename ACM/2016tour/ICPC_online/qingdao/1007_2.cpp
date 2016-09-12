#include <bits/stdc++.h>
#define LL long long
template <class T>
inline void rd(T &x) { char c = getchar(); x = 0;while(!isdigit(c)) c = getchar();
while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }}
template <class T> void Out(T a) { if(a < 0){putchar('-');a = -a;}if(a >= 10)Out(a / 10);putchar(a % 10 + '0');  }
using namespace std;
LL n,x,y,tmp,m;
LL ans[10]={0,0,1,2,4,6};
int main()
{
    while (scanf("%I64d%I64d",&n,&m)!=EOF)
    {
        if (n<6)
        {
            tmp=ans[n];
        }
        else
        {

            LL r = n%4;
            n-=r;
            x=(n-4)/2;
            y=n/2;
            tmp=x*y+n;
            
          if (r == 1)
          {
            tmp += n/2;
          }
          if (r == 2)
          {
            tmp += n;
          }
          if (r == 3)
          {
            tmp += 3*n/2+1;
          }
        }
        if (tmp<=m) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
