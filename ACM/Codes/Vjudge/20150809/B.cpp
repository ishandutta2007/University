#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

#define ll long long
#define maxn 1000020


using namespace std;


int fa[maxn];
bool appe[maxn];
int vec[maxn];
int cnt = 0;

int root(int a){
    while(a != fa[a])
        a = fa[a] = fa[fa[a]];
    return a;
}


int main(){

    int x, y;
    int ka = 0;
    while(scanf("%d%d", &x, &y) != EOF){
        if(x < 0) return 0;

        ka++;
        cnt = 0;
        memset(vec, 0 ,sizeof(vec));
        for(int i = 1; i <= maxn; i++)
        {
            fa[i] = i;
            appe[i] = false;
        }

        bool flag = true;
        while(x != 0 && y != 0){
            if(!appe[x]){
                appe[x] = true;
                vec[cnt++] = x;
            }
            if(!appe[y]){
                appe[y] = true;
                vec[cnt++] = y;
            }
            int rx = root(x);
            int ry = root(y);
            if(rx == ry) flag = false;
            else fa[ry] = rx;


            scanf("%d%d",&x,&y);
        }
        if(cnt == 0){printf("Case %d is a tree.\n", ka);continue;}
        if(!flag){printf("Case %d is not a tree.\n", ka);continue;}

        int R = root(vec[cnt - 1]);
        for(int i = 1; i < cnt; i++){
            if(root(vec[i]) != R) flag = false;
        }

        if(flag) printf("Case %d is a tree.\n", ka);
        else printf("Case %d is not a tree.\n", ka);
    }

    return 0;
}
