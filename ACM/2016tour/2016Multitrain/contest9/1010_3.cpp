#include <bits/stdc++.h>
#define inf 2147483647
#define maxn 100020
using namespace std;
struct node
{
    node *pre,*ch[27];
    int mx,v;
}sam[4*maxn],*rot,*now,*r[4*maxn];
char s[maxn];
int n,m,num,tot;
int t[2*maxn];

inline void insert(int w)
{
    node *p=now,*np=&sam[++num];
    for (int i=0;i<27;i++) np->ch[i]=NULL;
    np->pre=NULL;
    np->mx=p->mx+1; np->v=1;
    while (p!=NULL && p->ch[w]==NULL) p->ch[w]=np,p=p->pre;
    if (p==NULL) np->pre=rot;
    else
    {
        node *q=p->ch[w];
        if (q->mx==p->mx+1) np->pre=q;
        else
        {
            node *nq=&sam[++num];
            *nq=*q;
            nq->v=0;
            nq->mx=p->mx+1;
            np->pre=q->pre=nq;
            while (p&&p->ch[w]==q) p->ch[w]=nq,p=p->pre;
        }
    }
    now=np;
}

inline int query(char *s)
{
    now=rot;
    int len=strlen(s);
    for (int i=0;i<len;i++)
    {
        int w=s[i]-'a';
        if (now->ch[w]==NULL) return -1;
        else now=now->ch[w];
    }
    return now->v;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    #endif
    int Case;
    scanf("%d",&Case);
    for (int o=1;o<=Case;o++)
    {
        scanf("%d%d",&n,&m);
        tot=0;
        rot=&sam[num=1];
        for (int i=0;i<27;i++) rot->ch[i]=NULL;
        rot->mx=rot->v=0;
        now=rot;
        for (int i=1;i<=n;i++)
        {
            scanf(" %s",s);
            int len=strlen(s);
            for (int i=0;i<len;i++) insert(s[i]-'a');
            insert(26);
            tot+=len+1;
        }

        //for (int i=2;i<=num;i++) cout<<sam[i].pre->id<<endl;

        for (int i=0;i<=tot;i++) t[i]=0;
        for (int i=1;i<=num;i++) t[sam[i].mx]++;
        for (int i=1;i<=tot;i++) t[i]+=t[i-1];
        for (int i=num;i>=1;i--) r[t[sam[i].mx]--]=&sam[i];

        for (int i=num;i>=2;i--)
            r[i]->pre->v+=r[i]->v;

        //for (int i=1;i<=num;i++) cout<<i<<' '<<sam[i].v<<endl;

        printf("Case #%d:\n",o);

        for (int i=1;i<=m;i++)
        {
            scanf(" %s",s);
            int k=query(s);
            if (k==-1)
            {
                printf("%d\n",0);
                continue;
            }
            int ls=strlen(s);
            int l=1, r=ls,ans=ls;
            while (l<=r)
            {
                int mid=(l+r)>>1;
                if (query(s+ls-mid)==k)
                {
                    ans=min(ans, mid);
                    //ans = mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            printf("%d\n",ls-ans+1);
        }
    }
    return 0;
}
