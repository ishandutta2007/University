#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long LL;
const int N = 10006;
const int M = 100006;
const int oo = 0x7fffffff;
struct node{
    int x, y, w, next;
}e[N];
queue <int> Q;
stack <int> S;

int head[N], n, m, x, y, w, du[N], ve[N], vl[N], ans, tot;

inline void addEdge(int x,int y, int w)
{
    tot++; e[tot].x = x; e[tot].y = y; e[tot].w = w;
    e[tot].next = head[x]; head[x] = tot;
}

void work()
{
    memset(ve, 0, sizeof(ve));      //初始化
    memset(vl, 0x3f, sizeof(vl));
    while(!Q.empty()) Q.pop();
    while(!S.empty()) S.pop();

    for(int i = 0; i < n; i++)
        if(du[i] == 0) Q.push(i);
    while(!Q.empty()){          //拓扑排序+最早开始时间
        int now = Q.front(); Q.pop();
        S.push(now);                    //记录逆拓扑序列
		for(int k = head[now]; k != -1; k = e[k].next){
			int ed = e[k].y;
            du[ed]--;
            if(du[ed] == 0) Q.push(ed);
            ve[ed] = max(ve[ed], ve[now] + e[k].w);
            ans = max(ans, ve[ed]);
		}
    }

//    vl[n - 1] = ve[n - 1];        //最晚开始时间
//    while(!S.empty()){
//        int now = S.top(); S.pop();
//        for(int k = head[now]; k != -1; k = e[k].next){
//			int ed = e[k].y;
//            vl[ed] = min(vl[ed], vl[now] + e[k].w);
//		}
//    }
}


int main()
{
   // freopen("test.in", "r", stdin);
    while(scanf("%d%d", &n, &m)!= EOF){
        memset(head, -1, sizeof(head)); tot = 0;
        memset(du, 0, sizeof(du));
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d", &x, &y, &w);
            du[y]++; addEdge(x, y, w);
        }
        ans = 0;
        work();
        printf("%d\n", ans + 1);
    }
}
