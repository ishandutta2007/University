#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;


struct block{
    int x,y,z;
}b[120];

bool cmp(struct block a, struct block b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int ans[120];

int main(){

    int ka = 0;
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0) return 0;
        ka++;
        int x,y,z;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d",&x,&y,&z);

            b[i*3].x = min(x, y);
            b[i*3].y = max(x, y);
            b[i*3].z = z;
            b[i*3+1].x = min(y, z);
            b[i*3+1].y = max(y, z);
            b[i*3+1].z = x;
            b[i*3+2].x = min(x, z);
            b[i*3+2].y = max(x, z);
            b[i*3+2].z = y;

        }

        sort(b, b + n * 3, cmp);


        memset(ans, 0, sizeof(ans));

        ans[0] = b[0].z;

        for(int i = 1; i < n * 3; i++){

            ans[i] = b[i].z;
            for(int j = 0; j < i; j++){
                if(((b[j].x < b[i].y && b[j].y < b[i].x)||(b[j].x < b[i].x && b[j].y < b[i].y)) && ans[i] < ans[j] + b[i].z)
                    ans[i] = ans[j] + b[i].z;
            }
        }
        int aa = 0;
        for(int i = 0; i < 3 * n; i++){
//            printf("%d\n",ans[i]);
            aa = max(aa, ans[i]);
        }


        printf("Case %d: maximum height = %d\n", ka, aa);
    }










    return 0;
}
