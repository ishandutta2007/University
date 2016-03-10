#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 5e6 + 60;
const int M = 6e5+ 600;
const int oo = 0x7fffffff;
const int MAXNUM[] = {1, 10, 100,1000,10000,100000,1000000};
struct node{
    int x, y, next, vis;
}e[N];

int n, tot, head[N], stk[N], top, path[N], cnt = 0;

inline void addEdge(int x,int y)
{
    tot++; e[tot].x = x; e[tot].y = y; e[tot].vis = 0;
    e[tot].next = head[x]; head[x] = tot;
}

void dfs()
{
    bool flag;
    stk[top++] = 0;         //搜索的起点
    while (1){
        flag = 0;
        int now = stk[top - 1];
        for(int p = head[now]; p != -1; p = e[p].next)
            if (!e[p].vis){
                flag = 1;
                e[p].vis = 1;
                stk[top++] = e[p].y;
                break;
            }
        if (!flag){
            top--;
            path[++cnt] = stk[top] % 10;
        }
        if(top == 0) return;
    }
}
int main()
{
  // freopen("test.in", "r", stdin);
    while(scanf("%d", &n)!= EOF && n){
        if(n == 1){
            printf("0123456789\n");
            continue;
        }
        memset(head, -1, sizeof(head));
        tot = 0; top = 0; cnt = 0;
        int maxt = MAXNUM[n - 1];
        for(int i = 0; i < maxt; i++){      //枚举前n-1位做起点
            int next = i % (maxt / 10);
            for(int j = 9; j >= 0; j--)
                addEdge(i, next * 10 + j);
        }
//        cout << tot << endl;
        dfs();
        for(int i = 1; i <= MAXNUM[n - 1] * 10 + n - 1 - cnt; i++) printf("0");
        for(int i = cnt; i > 0; i--) printf("%d", path[i]);
        printf("\n");
//        cout << cnt << endl;
    }
}
