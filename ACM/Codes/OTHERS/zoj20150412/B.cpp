#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>


using namespace std;

bool vis[10];
bool num[10];
int _cnt;
int ans[10000000][10];
int n;
int tans[10];

void ans_get(){
    for(int i = 0; i < n; i++)
        ans[_cnt][i] = tans[i];
    _cnt ++;
}

bool checkseg(int a, int b){
    int rowa = (a - 1) / 3;
    int rowb = (b - 1) / 3;
    int cowa = (a - 1) % 3 + 1;
    int cowb = (b - 1) % 3 + 1;
    if(abs(rowa - rowb) == 1 || abs(cowa - cowb) == 1)
        return true;
    int rowmid = (rowa + rowb) / 2;
    int cowmid = (cowa + cowb) / 2;
    int id = rowmid * 3 + cowmid;
    if(num[id] && vis[id])
        return true;
    return false;
}




void dfs(int t){
    if(t >= n){
        ans_get();
        return;
    }
    for(int i = 1; i <= 9; i++)if(num[i] && (!vis[i])){
        if(t == 0){
            tans[t] = i;
            vis[i] = 1;
            dfs(t + 1);
            vis[i] = 0;
        }
        else if(checkseg(tans[t - 1], i)){
            tans[t] = i;
            vis[i] = 1;
            dfs(t + 1);
            vis[i] = 0;
        }
    }
}




int main(){
    int t;
    scanf("%d", &t);
    while(t --){
        memset(vis, 0, sizeof(vis));
        memset(num, 0, sizeof(num));
        memset(ans, 0, sizeof(ans));
        scanf("%d", &n);
        int tmp;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            num[tmp] = 1;
        }
        _cnt = 0;
        dfs(0);
        printf("%d\n", _cnt);
        for(int i = 0; i < _cnt; i++)
            for(int j = 0; j < n;j++)
                printf("%d%c",ans[i][j], j == (n - 1) ? '\n' : ' ');

    }
    return 0;
}
