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

int ans[maxn];

int main(){

    int n;
    while(scanf("%d", &n) != EOF){
        bit.clear();
        bit.n = n;
        memset(ans, 0, sizeof(ans));
        int x, y;
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &x, &y);
            x++;

            ans[bit.getsum(x)]++;
            bit.add(x, 1);
        }

        for(int i = 0; i < n; i++)
            printf("%d\n", ans[i]);

    }


    return 0;
}

