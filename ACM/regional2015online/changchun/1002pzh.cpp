#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
vector <int> ma[25000];
int in[25000],vis[25000];
int v[25000];
int n,m,t,x,y;
long long int ans,sum,num;
queue <int> q;
int main()
{
    scanf("%d",&t);
    while(t>0)
    {
        t--;
        ans=0;
        sum=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) ma[i].clear();
        while (!q.empty()) q.pop();
        memset(in,0,sizeof(in));
        memset(vis,0,sizeof(vis));

        for (int i=1;i<=n;i++) scanf("%d",&v[i]);
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            in[x]++;
            in[y]++;
            ma[x].push_back(y);
            ma[y].push_back(x);
        }

        for (int i=1;i<=n;i++)
        {
            if (in[i]<=1) q.push(i);
            vis[i]=1;
        }

        while(!q.empty())
        {
            x=q.front();
            q.pop();
            for (int i=0, len = ma[x].size();i<len;i++)
            {
                y=ma[x][i];
                if (vis[y]==1) continue;
                in[y]--;
                if (in[y]<=1) {q.push(y);vis[y]=1;}
            }
        }

        memset(vis,0,sizeof(vis));

        for (int i=1;i<=n;i++)
        {
            if (in[i]>1 && vis[i]==0)
            {
                sum=0;num=0;
                q.push(i);
                vis[i]=1;
                while (!q.empty())
                {
                    x=q.front();
                    q.pop();
                    sum+=v[x];
                    num++;
                    for (int i=0;i<ma[x].size();i++)
                    {
                        y=ma[x][i];
                        if (vis[y]==1) continue;
                        if (in[y]>1) {q.push(y);vis[y]=1;}
                    }
                }
                //cout<<num<<endl;
                if (num%2==1) ans+=sum;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
