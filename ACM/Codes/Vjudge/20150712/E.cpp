#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

#define LL long long

using namespace std;


int cal(int a, int b, char oper){
    if(oper == '+')
        return a + b;
    if(oper == '-')
        return a - b;
    if(oper == '*')
        return a * b;
    if(oper == '/')
        return a / b;
    return a % b;

}


int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        int num[3];
        char s[2][5];
        scanf("%d%s%d%s%d", &num[0], s[0], &num[1], s[1], &num[2]);

        int ans = 0;
        if(s[0][0] == '+' || s[0][0] == '-'){
            if(s[0][0] == '-' && (s[1][0] == '-' || s[1][0] == '+')){
                num[2] = -num[2];
            }
            ans = cal(num[1], num[2], s[1][0]);
            ans = cal(num[0], ans, s[0][0]);
        }
        else{
            ans = cal(num[0], num[1], s[0][0]);
            ans = cal(ans, num[2], s[1][0]);
        }

        printf("%d\n", ans);

    }

    return 0;
}

