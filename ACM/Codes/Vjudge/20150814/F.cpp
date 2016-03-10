#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<map>

#define maxn 1000200

using namespace std;

map<int,int>mp;


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

//        printf("n = %d\n", n);
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

int a[maxn], b[maxn];
int aaa[maxn];
int n;

int main(){

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &aaa[i]);

    mp.clear();
    for(int i = 1; i <= n; i++){
        mp[aaa[i]]++;
        a[i] = mp[aaa[i]];
    }
    mp.clear();
    for(int i = n; i >= 1; i--){
        mp[aaa[i]]++;
        b[i] = mp[aaa[i]];
    }

    long long ans = 0;
    bit.clear();
    for(int i = n; i >= 1; i--){
        ans += bit.getsum(a[i] - 1);
        bit.add(b[i], 1);
    }

    printf("%I64d\n", ans);


    return 0;
}

