#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define M 100010
#define N 1010
#define inf 0x3fffffff
struct edge{
    int to,w,next;
}e[M];
int pre[N],dist[N][2],cnt[N][2],b[N][2];
int cnt0,n,m;
void add(int a,int b,int w)
{
    e[cnt0].next=pre[a];
    e[cnt0].to=b;
    e[cnt0].w=w;
    pre[a]=cnt0++;
}
struct node{
    int w,u,flag;
    bool operator <(const node &x)const
    {
        return w>x.w;
    }
};
int dijstra(int start,int end)
{
    priority_queue<node> q;
    node in;
    for(int i=1;i<=n;i++){
        dist[i][0]=dist[i][1]=inf;
        cnt[i][0]=cnt[i][1]=0;
        b[i][0]=b[i][1]=0;
    }
    dist[start][0]=0;
    cnt[start][0]=1;
    in.w=0;in.u=start;in.flag=0;
    q.push(in);
    while(!q.empty())
    {
        int u=q.top().u;
        int flag=q.top().flag;
        q.pop();
        if(b[u][flag])continue;
        b[u][flag]=1;
        for(int edg=pre[u];edg!=0;edg=e[edg].next)
        {
            int v=e[edg].to;int w=dist[u][flag]+e[edg].w;
            if(dist[v][0]>w)
            {
                if(dist[v][0]!=inf)
                {
                    dist[v][1]=dist[v][0];
                    cnt[v][1]=cnt[v][0];
                    in.w=dist[v][1];
                    in.flag=1;
                    in.u=v;
                    q.push(in);
                }
                dist[v][0]=w;
                cnt[v][0]=cnt[u][flag];
                in.w=dist[v][0];
                in.u=v;
                in.flag=0;
                q.push(in);
            }
            else if(dist[v][0]==w)
            {
                cnt[v][0]+=cnt[u][flag];
            }
            else if(dist[v][1]>w)
            {
                dist[v][1]=w;
                cnt[v][1]=cnt[u][flag];
                in.w=dist[v][1];
                in.flag=1;
                in.u=v;
                q.push(in);
            }
            else if(dist[v][1]==w)
            {
                cnt[v][1]+=cnt[u][flag];
            }
        }
    }
    if(dist[end][0]==dist[end][1]-1)return cnt[end][0]+cnt[end][1];
    else return cnt[end][0];
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        cnt0=1;
        memset(pre,0,sizeof(pre));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            add(a,b,w);
        }
        int start,end;
        scanf("%d%d",&start,&end);
        printf("%d\n",dijstra(start,end));
        //for(int i=1;i<=n;i++)
        //cout<<cnt[i][0]<<":"<<dist[i][0]<<endl;
    }
    return 0;
}
