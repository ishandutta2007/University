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


struct line{
    int a, b;
    int c;
}l[20020];

bool cmp(struct line a, struct line b){
    return a.c > b.c;
}


int main(){

    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
        fa[i] = i;

    for(int i = 0; i < m; i++)
        scanf("%d%d%d", &l[i].a, &l[i].b, &l[i].c);

    sort(l, l + m, cmp);


    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(root(l[i].a) != root(l[i].b))
        {
            ans += l[i].c;
//            cout << l[i].c << endl;
            unionset(l[i].a, l[i].b);
            cnt++;
        }
    }

    if(cnt == n - 1) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}

