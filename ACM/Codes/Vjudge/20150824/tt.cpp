#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>v,cnt;


bool __check(int x)
{
    while(x)
    {
        if(x % 100 == 13) return true;
        x /= 10;
    }
    return false;
}

void init()
{
    int tot = 0;
    for(int i = 13; i <= 1000000; i += 13)
    {
        if(__check(i))
        {
            v.push_back(i);
            cnt.push_back(++tot);
        }
    }


}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    #endif
    init();
    int n;
    for(n = 1; n <= 1000; n++)
    {
        int pos = lower_bound(v.begin(), v.end(), n) - v.begin();
        if(v[pos] > n) pos--;
        printf("%d %d\n",n, cnt[pos]);
    }



    return 0;
}