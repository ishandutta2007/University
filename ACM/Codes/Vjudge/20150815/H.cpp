#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#define maxn 50020
using namespace std;
struct BIT{
    int c[maxn];
    int n;

    void clear(){
        memset(c, 0, sizeof(c));
        n = 0;
    }
    inline int lowbit(int x){
        return x & (-x);
    }
    void add(int pos, int delta){

        printf("n = %d\n", n);
        while(pos < maxn){
            c[pos] += delta;
            pos += lowbit(pos);
        }
    }
    int getsum(int pos){
        int ans = 0;
        while(pos > 0){
            ans += c[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }
}bit;
int a[maxn];
int main(){

    int n;
    while(scanf("%d", &n) != EOF){
        bit.clear();
        bit.n = n;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            bit.add(i, x);
        }
        int m;
        int x, y;
        scanf("%d", &m);
        while(m--){
            scanf("%d%d",&x,&y);
            int ans = a[x];
            int pre = 0;
            int l = x, r = x;
            for(int i = x; i <= y; i++){
                if()


            }
        }
    }
    return 0;
}
