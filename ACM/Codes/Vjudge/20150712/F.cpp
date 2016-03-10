#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<map>

#define LL long long
#define maxn 10000000

using namespace std;

//
//int f2[4] = {1, 2, 4, 1};
//int f3[7] = {1, 3, 2, 6, 4, 5, 1};
//int f4[4] = {1, 4, 2, 1};
//int f5[7] = {1, 5, 4, 6, 2, 3, 1};
//int f6[3] = {1, 6, 1};

int f[7][7] = {{0},{1, 1, 1, 1},{1, 2, 4, 1},{1, 3, 2, 6, 4, 5, 1},{1, 4, 2, 1},{1, 5, 4, 6, 2, 3, 1},{1, 6, 1}};
int m[7] = {0, 1, 3, 6, 3, 6, 2};


inline int pow(int a, int b){
    if(a == 0) return 0;
    if(a == 1) return 1;

    return f[a][b % m[a]];
}


int main(){
//    for(int i = 0; i < 7; i++)
//        for(int j = 0; j < 7; j++)
//            printf("%d%c",f[i][j], j == 6? '\n' : ' ');
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
//        n = (sum[n] + 5) % 7;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += pow(i % 7, i);
//            printf("%d\n", sum);
        }
        n = (sum + 5) % 7;
        if(n == 0) printf("Monday\n");
        else if(n == 1) printf("Tuesday\n");
        else if(n == 2) printf("Wednesday\n");
        else if(n == 3) printf("Thursday\n");
        else if(n == 4) printf("Friday\n");
        else if(n == 5) printf("Saturday\n");
        else if(n == 6) printf("Sunday\n");

    }

    return 0;
}


