#include<map>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define LL long long




using namespace std;
int n[2],t1,t2,T;
char st[2][10],ed[2][10];
bool s[2][10];
char A[10004];
int Ans;
int Dfs(char c,int pl)
{
    int res;
    for(int i=1;i<=n[pl];i++)
    {
        if(!s[pl][i] && (st[pl][i]==c || c=='#'))
        {
            s[pl][i]=true;
            res=Dfs(ed[pl][i],pl^1);
            //cout<<res<<endl;
            if(res==pl){s[pl][i]=false;return pl;}
        }
    }
    //cout<<pl<<' '<<(pl^1)<<endl;
    return (pl^1);
}
int main()
{
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&n[0]);getchar();
        for(int j=1;j<=n[0];j++)
        {
            gets(A);
            //printf("%s\n",A);
            t1=strlen(A);
            st[0][j]=A[0];
            ed[0][j]=A[t1-1];
        }
        scanf("%d",&n[1]);getchar();
        for(int j=1;j<=n[1];j++)
        {
            gets(A);
            t1=strlen(A);
            st[1][j]=A[0];
            ed[1][j]=A[t1-1];
        }
        memset(s,0,sizeof(s));
        Ans=Dfs('#',0);
        printf("Game %d: player%d\n",i,Ans+1);
    }
    return 0;
}
