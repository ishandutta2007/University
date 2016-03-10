#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

double f[1005][1005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    #endif
    int n, s;
    // while(scanf("%d%d", &n, &s)!=EOF)
    // {
     scanf("%d%d", &n, &s);
        memset(f, 0, sizeof(f));
        for(int i=n; i>=0; i--)
            for(int j=s; j>=0; j--)
            {
                if(i==n && j==s) continue;
                double p1=(double(s-j)*i)/n/s;
                double p2=(double(n-i)*j)/n/s;
                double p3=(double(n-i)*(s-j))/n/s;
                double p0=1.0-(double(i*j))/n/s;
                f[i][j]=p1*f[i][j+1]+p2*f[i+1][j]+p3*f[i+1][j+1]+1;
                f[i][j]/=p0;
            }
        printf("%.4lf\n", f[0][0]);
    // }
    return 0;
}