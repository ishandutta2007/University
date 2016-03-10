#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

#define __maxn 0x3f3f3f3f3f
using namespace std;

int n,a[1500],ans,m;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    m=a[1];
    sort(a+1,a+1+n,greater<int>());
    ans=0;
    if (m>a[2]) {printf("0\n");return 0;}
    while (m<=a[1]) {m++;ans++;a[1]--;sort(a+1,a+1+n,greater<int>());}
    printf("%d\n",ans);

    return 0;
}