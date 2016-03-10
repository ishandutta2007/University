#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>

#define maxn 100020

using namespace std;


int c[maxn];
struct Point{
    int x, y, id, ans;
}p[maxn];

inline int lowbit(int x){
    return x & (-x);
}


void add(int pos, int delta){

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

bool cmp1(struct Point a, struct Point b){
    if(a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}
bool cmp2(struct Point a, struct Point b){
    return a.id < b.id;
}



int n;

int main(){

    while(scanf("%d", &n) != EOF){
        if(n == 0) return 0;
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &p[i].x, &p[i].y);
            p[i].x ++;
            p[i].y ++;
            p[i].id = i;

        }
        sort(p + 1, p + n + 1, cmp1);

        memset(c, 0, sizeof(c));
        p[1].ans = 0;
        int pre = 1;
        add(p[1].x, 1);

        for(int i = 2; i <= n; i++){
            if(p[i].x == p[pre].x && p[i].y == p[pre].y) p[i].ans = p[pre].ans;
            else{
                pre = i;
                p[i].ans = getsum(p[i].x);
            }
            add(p[i].x, 1);
        }
        sort(p + 1, p + n + 1, cmp2);


        for(int i = 1; i <= n; i++)
            printf("%d%c", p[i].ans, i == n? '\n' : ' ');

    }


    return 0;
}


