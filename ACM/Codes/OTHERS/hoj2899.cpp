#include<stdio.h>
#include<string.h>
#include<stdlib.h>


bool t[10000009];
int s, e;


int main(){
    int n;
    int a,b;
    while(scanf("%d",&n) == 1){
        s = 10000000;
        e = 1;
        memset(t, 0, sizeof(t));
        while(n --){
            scanf("%d%d", &a, &b);
            if(s > a)
                s = a;
            if(e < b)
                e = b;
            for(int i = a; i < b; i++)
                t[i] = true;
        }
        int ans1 = 0;
        int ans2 = 0;
        int tmp = 0;
        for(int i = s; i <= e; i++){
            if(t[i] != t[i - 1]){
                if(t[i - 1] == true && tmp > ans1)
                    ans1 = tmp;
                else if(t[i - 1] == false && tmp > ans2)
                    ans2 = tmp;
                tmp = 1;
            }
            else
                tmp ++;
        }
        printf("%d %d\n", ans1, ans2);

    }
    return 0;
}
