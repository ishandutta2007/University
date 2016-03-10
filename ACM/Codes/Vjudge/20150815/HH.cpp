#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

#define maxn 50020

using namespace std;


int a[maxn], sum[maxn];
int n, m;


int cal(int l, int r){
    int ans = -0x7f7f7f7f;
    int pos = l;
    int tmp = 0;
    for(int i = l; i <= r; i++){
        if(a[i] < 0){
            ans = max(ans, a[i]);
            if(tmp + a[i] > 0) tmp += a[i];
            else{
                tmp = 0;

            }
        }


    }

}




int main(){

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    scanf("%d", &m);

    int x, y;
    while(m--){
        scanf("%d%d",&x,&y);
        printf("%d\n", cal(x, y));
    }



    return 0;
}
