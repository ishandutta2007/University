#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<map>

#define LL long long

using namespace std;

int t[20020];
map<int, int> mp;
bool slash[20020];


int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        memset(t, 0, sizeof(t));
        memset(slash, 0, sizeof(slash));
        mp.clear();
        int n,l;
        scanf("%d%d", &n, &l);
        int H, M, S;
        for(int i = 1; i <= n; i++){
            scanf("%d:%d:%d",&H, &M, &S);
            t[i] = H * 3600 + M * 60 + S;
            mp[t[i]] = i;
        }

        sort(t + 1, t + n + 1);
        int time = -1;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(t[i] >= time){
                cnt ++;
                slash[mp[t[i]]] = 1;
                time = t[i] + l;
            }
        }


        printf("%d\n", cnt);
        int first = 1;
        for(int i = 1; i <= n; i++){
            if(slash[i]) {
                if(first != 1) printf(" ");
                printf("%d", i);
                first = 0;
            }
        }
        printf("\n");
    }

    return 0;
}


