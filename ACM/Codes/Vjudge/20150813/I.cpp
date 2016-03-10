#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;


struct point{
    int x, y;
}p[5020];


bool cmp(struct point a, struct point b){
    if(a.y == b.y) return a.x > b.x;
    return a.y > b.y;
}

int ans[5020];

int main(){


    int t;
    int n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d%d",&p[i].x,&p[i].y);

        memset(ans, 0, sizeof(ans));
        sort(p + 1, p + n + 1, cmp);
//
//        for(int i = 1; i <= n; i++)
//            printf("%d %d\n", p[i].x, p[i].y);

        int maxl = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i; j++)if((p[j].x < p[i].x || p[j].y < p[i].y) && ans[j] + 1 > ans[i]){
                ans[i] = ans[j] + 1;
                maxl = max(maxl, ans[i]);

        }

        printf("%d\n", maxl);



    }




    return 0;
}
