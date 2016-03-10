#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<iostream>

using namespace std;


int fa[10020];
int root(int a){
    while(a != fa[a])
        a = fa[a] = fa[fa[a]];
    return a;
}
void unionset(int x, int y){
    int rx = root(x);
    int ry = root(y);

    fa[rx] = ry;
}

struct point{
    double x, y;
}p[120];

struct line{
    int a, b;
    double lenth;
}l[10020];

double callen(int a, int b){

    double tmp = (p[a].x - p[b].x) * (p[a].x - p[b].x);
    tmp += (p[a].y - p[b].y) * (p[a].y - p[b].y);
    return sqrt(tmp);
}

bool cmp(struct line a, struct line b){
    return a.lenth < b.lenth;
}


int main(){

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;

    int cnt = 0;
    for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++){
        l[cnt].a = i;
        l[cnt].b = j;
        l[cnt].lenth = callen(i, j);
        cnt++;
    }

    sort(l, l + cnt, cmp);

    for(int i = 1; i <= n; i++)
        fa[i] = i;

    double ans = 0;
    for(int i = 0; i < cnt; i++){
        if(root(l[i].a) != root(l[i].b))
        {
            ans += l[i].lenth;
            unionset(l[i].a, l[i].b);
        }
    }

    printf("%.2f\n", ans);

    return 0;
}
