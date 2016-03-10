#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

#define ll long long

using namespace std;


ll ans[20];

bool lx[25], rx[25], line[25];

int n;
ll tmp;

void dfs(int step){

    if(step > n){
        tmp++;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(line[i] == false && lx[step + i] == false && rx[step - i + 10] == false)
        {
            line[i] = lx[step + i] = rx[step - i + 10] = true;
            dfs(step + 1);
            line[i] = lx[step + i] = rx[step - i + 10] = false;
        }
    }
}







int main(){

    while(~scanf("%d", &n)){
        if(n == 0) return 0;


        if(ans[n] == 0LL){

            memset(lx, 0, sizeof(lx));
            memset(rx, 0, sizeof(rx));
            memset(line, 0, sizeof(line));
            tmp = 0LL;
            dfs(1);
            ans[n] = tmp;
        }


        printf("%I64d\n", ans[n]);
    }
    return 0;
}
