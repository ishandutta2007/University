/*
 * Author: Gatevin
 * Created Time:  2015/5/4 22:34:28
 * File Name: Rin_Tohsaka.cpp
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int T;
int N, K;

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d %d", &N, &K);
        printf("Case %d: ", cas);
        if(K == 1)
        {
            if(N & 1) puts("first");
            else puts("second");
        }
        else
        {
            if(N <= K) puts("first");
            else puts("second");
        }
    }
    return 0;
}
