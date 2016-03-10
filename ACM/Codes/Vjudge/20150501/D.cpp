#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;


char s[20000];


int main(){

    int t;
    scanf("%d", &t);
    for(int k = 1; k <= t; k++)
    {
        scanf("%s", s);
        if(strlen(s) % 2 == 0)
            printf("Case %d: Even\n", k);
        else
            printf("Case %d: Odd\n", k);
    }



    return 0;
}

