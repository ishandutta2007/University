#include<map>
#include<queue>
#include<stack>
#include<stdio.h>
#include<ctype.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int n, k, p, x, y;
int marks[1020];
int ans[1020];

int main(){

    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
    int sum = 0;
    for(int i = 1; i <= k; i++)
    {
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    int rest = x - sum;

    if(rest < n - k){
        printf("-1\n");
        return 0;
    }

    rest -= n-k;
    y -= 1;
    for(int i = k + 1; i <= n; i++){
        if(rest >= y){
            marks[i] = ans[i] = y;
            rest -= y;
        }
        else{
            marks[i] = ans[i] = rest;
            rest = 0;
        }
        ans[i] ++;
        marks[i] ++;
    }
    sort(marks + 1, marks + n + 1);
    if(marks[(n + 1) / 2] >= y + 1){
        for(int i = k + 1; i <= n; i++)
            printf("%d%c", ans[i], i == n? '\n' : ' ');
    }
    else printf("-1\n");

    return 0;
}
