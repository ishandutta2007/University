#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;
        printf("%s\n", n%2? "ailyanlu":"8600");
    }


    return 0;
}