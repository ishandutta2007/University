#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node
{
    int swi_state;
    int x, y;
    int lev;
    int depth;
    Node(){}
    Node(int sta, int x, int y, int l, int d):swi_state(sta), x(x), y(y), lev(l), depth(d){}
}now, tmp, nex;
char swi[11][60][60], origin[60][60], nowmap[60][60];
int vis[2][60][60][1<<11], sx, sy, ex, ey;
int mx[4] = {0, 0, -1, 1};
int my[4] = {1, -1, 0, 0};
int W, H, cnt_swi;
deque<Node> deq;

void cl(){ memset(vis, 0, sizeof(vis)); }
void getpos()
{
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
        {
            if(origin[i][j] == '%')
            {
                sx = i, sy = j;
                origin[i][j] = '_';
            }
            else if(origin[i][j] == '&')
            {
                ex = i, ey = j;
                origin[i][j] = '_';
            }
        }
}


int callevel(int x, int y, int state)
{

    char ch = origin[x][y];
    if(ch == '|') return 2;
    int ret = 0;
    if((ch >= 'a' && ch <= 'j') || ch == '_') ret = 0;
    else ret = 1;

    for(int i = 0; i < 10; i++)
    {
        if(state&(1<<i) && swi[i][x][y] == '*')
        {
            ret ^= 1;
        }
    }
    return ret;
}

void show_nod(struct Node tmp)
{
    cout << tmp.swi_state << "  " << tmp.x << " " << tmp.y << " " << tmp.depth << " " << tmp.lev << endl;
}

int bfs()
{
    deq.clear();
    vis[0][sx][sy][0] = 1;
    deq.push_back(Node(0, sx, sy, 0, 0));
    int nowx, nowy, nowstate, nowlevel;
    int tmpx, tmpy, tmpstate, tmplevel;
    while(!deq.empty())
    {
        now = deq.front();
        deq.pop_front();
        nowx = now.x, nowy = now.y, nowstate = now.swi_state, nowlevel = now.lev;
        if(nowx == ex && nowy == ey) return now.depth;
        if((origin[nowx][nowy] >= 'a' && origin[nowx][nowy] <= 'j') || (origin[nowx][nowy] >= 'A' && origin[nowx][nowy] <= 'J'))
        {
            if(origin[nowx][nowy] >= 'a' && origin[nowx][nowy] <= 'j')
            {
                tmpx = nowx , tmpy = nowy , tmpstate = nowstate ^ (1 << (origin[nowx][nowy] - 'a')), tmplevel = callevel(tmpx, tmpy, tmpstate);
                if(vis[tmplevel][tmpx][tmpy][tmpstate] == 0)
                {
                    vis[tmplevel][tmpx][tmpy][tmpstate] = 1;
                    deq.push_back(Node(tmpstate, tmpx, tmpy, tmplevel, now.depth + 1));
                }
            }
            else
            {
                tmpx = nowx , tmpy = nowy , tmpstate = nowstate ^ (1 << (origin[nowx][nowy] - 'A')), tmplevel = callevel(tmpx, tmpy, tmpstate);
                if(vis[tmplevel][tmpx][tmpy][tmpstate] == 0)
                {
                    vis[tmplevel][tmpx][tmpy][tmpstate] = 1;
                    deq.push_back(Node(tmpstate, tmpx, tmpy, tmplevel, now.depth + 1));
                }
            }
        }
        if(origin[nowx][nowy] == '|')
        {
            tmpx = nowx, tmpy = nowy, tmpstate = nowstate, tmplevel = nowlevel ^ 1;

            if(vis[tmplevel][tmpx][tmpy][tmpstate] == 0)
            {
                vis[tmplevel][tmpx][tmpy][tmpstate] = 1;
                deq.push_back(Node(tmpstate, tmpx, tmpy, tmplevel, now.depth + 1));
            }
        }
        for(int i = 0; i < 4; i++)
        {
            tmpx = nowx + mx[i], tmpy = nowy + my[i];
            tmpstate = nowstate;
            if(tmpx < 0 || tmpx >= H || tmpy < 0 || tmpy >= W || origin[tmpx][tmpy] == '#') continue;
            tmplevel = callevel(tmpx, tmpy, tmpstate);
            if(tmplevel == 2 || tmplevel == nowlevel)
            {
                if(tmplevel == 2) tmplevel = nowlevel;
                if(vis[tmplevel][tmpx][tmpy][tmpstate] == 0)
                {
                    vis[tmplevel][tmpx][tmpy][tmpstate] = 1;
                    deq.push_back(Node(tmpstate, tmpx, tmpy, tmplevel ,now.depth + 1));
                }
            }
        }
    }
    return -1;
}

int main()
{
    while(scanf("%d%d", &W, &H) != EOF)
    {
        cl();
        for(int i = 0; i < H; i++)
            scanf("%s", origin[i]);
        getpos();
        scanf("%d", &cnt_swi);
        for(int k = 0; k < cnt_swi; k ++)
        {
            for(int i = 0; i < H; i++)
                scanf("%s", swi[k][i]);
        }
        printf("%d\n", bfs());
    }
    return 0;
}
