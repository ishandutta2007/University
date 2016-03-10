#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>


using namespace std;

int n;
int a[10];

int ans[1000000][10];
int tmp[10];
bool vis[10];
int cnt;


bool check(int s, int e){
    int rs = (s - 1) / 3 + 1, cs = (s - 1) % 3 + 1;
    int re = (e - 1) / 3 + 1, ce = (e - 1) % 3 + 1;

    if(rs == re && cs + ce == 4 && vis[(rs - 1) * 3 + 2] == false) return false;
    if(cs == ce && rs + re == 4 && vis[3 + cs] == false) return false;
    if(((s == 1 && e == 9) || (s == 3 && e == 7)) && vis[5] == false) return false;
    if(((e == 1 && s == 9) || (e == 3 && s == 7)) && vis[5] == false) return false;



    return true;
}


void dfs(int depth){

    if(depth >= n)
    {

        for(int i = 0; i < n;i++)
            ans[cnt][i] = tmp[i];
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++)if(!vis[a[i]] && check(tmp[depth - 1], a[i])){
        tmp[depth] = a[i];
        vis[a[i]] = true;
        dfs(depth + 1);
        vis[a[i]] = false;
    }
}



int main(){


    int T;
    scanf("%d", &T);

    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);

        memset(vis, 0, sizeof(vis));
        cnt = 0;

        for(int i = 0; i < n; i++){
            tmp[0] = a[i];
            vis[a[i]] = true;
            dfs(1);
            vis[a[i]] = false;
        }

        printf("%d\n", cnt);

        for(int i = 0; i < cnt; i++)
            for(int j = 0; j < n; j++)
                printf("%d%c", ans[i][j], j == n - 1 ? '\n' : ' ');
    }

    return 0;
}
