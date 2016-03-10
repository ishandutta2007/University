#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define pb push_back
#define LL long long
using namespace std;

LL ans;
vector<int> p[10];
int h[7][7][7][7][7][7][7][5];
queue<int> q[8];
int head[8];
int chg[8];
struct nd{
    int w,p;
}a[233];

bool cmp1(nd x,nd y){
    return x.w<y.w;
}
bool cmp2(nd x,nd y){
    return x.p<y.p;
}

void memchg(){
    for(int i=0;i<=7;i++){
        chg[i]=q[i].front();
    }
}

void init(){
    int tim=0;
    memset(h,0,sizeof(h));
    for(int i=0;i<=4;i++)h[0][1][2][3][4][5][6][i]=1;
    for(int ti=0;ti<=4;ti++){for(int i=0;i<7;i++)q[i].push(i);q[7].push(ti);}
    while(!q[7].empty()){
        int maxm=q[7].front()+3;
        for(int i=0;i<maxm;i++){head[i]=10000;}
        for(int i=0;i<maxm;i++){
            if(head[q[i].front()]>i)head[q[i].front()]=i;
        }
        for(int i=0;i<maxm;i++){
            if(i==0){
                if(head[0]<head[1]){
                    memchg();
                    chg[head[0]]=1;
                    if(!h[chg[0]][chg[1]][chg[2]][chg[3]][chg[4]][chg[5]][chg[6]][chg[7]]){
                        h[chg[0]][chg[1]][chg[2]][chg[3]][chg[4]][chg[5]][chg[6]][chg[7]]=h[q[0].front()][q[1].front()][q[2].front()][q[3].front()][q[4].front()][q[5].front()][q[6].front()][q[7].front()]+1;
                        for(int i=0;i<=7;i++)q[i].push(chg[i]);
                    }
                }
            }else if(i==(maxm-1)){
                if(head[maxm-1]<head[maxm-2]){
                    memchg();
                    chg[head[maxm-1]]=maxm-2;
                    if(!h[chg[0]][chg[1]][chg[2]][chg[3]][chg[4]][chg[5]][chg[6]][chg[7]]){
                        h[chg[0]][chg[1]][chg[2]][chg[3]][chg[4]][chg[5]][chg[6]][chg[7]]=h[q[0].front()][q[1].front()][q[2].front()][q[3].front()][q[4].front()][q[5].front()][q[6].front()][q[7].front()]+1;
                        for(int i=0;i<=7;i++)q[i].push(chg[i]);
                    }
                }
            }else{
                if(head[i]<head[i+1]){
                    memchg();
                    chg[head[i]]=i+1;
                    if(!h[chg[0]][chg[1]][chg[2]][chg[3]][chg[4]][chg[5]][chg[6]][chg[7]]){
                        h[chg[0]][chg[1]][chg[2]][chg[3]][chg[4]][chg[5]][chg[6]][chg[7]]=h[q[0].front()][q[1].front()][q[2].front()][q[3].front()][q[4].front()][q[5].front()][q[6].front()][q[7].front()]+1;
                        for(int i=0;i<=7;i++)q[i].push(chg[i]);
                    }
                }
                if(head[i]<head[i-1]){
                    memchg();
                    chg[head[i]]=i-1;
                    if(!h[chg[0]][chg[1]][chg[2]][chg[3]][chg[4]][chg[5]][chg[6]][chg[7]]){
                        h[chg[0]][chg[1]][chg[2]][chg[3]][chg[4]][chg[5]][chg[6]][chg[7]]=h[q[0].front()][q[1].front()][q[2].front()][q[3].front()][q[4].front()][q[5].front()][q[6].front()][q[7].front()]+1;
                        for(int i=0;i<=7;i++)q[i].push(chg[i]);
                    }

                }
            }
        }
        for(int i=0;i<=7;i++)q[i].pop();
    }
}


int main(){
    freopen("G.in", "r", stdin);
    freopen("g2.out", "w", stdout);
    init();
    int T;scanf("%d",&T);
while(T--){
    ans=0;int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i].w);a[i].p=i-1;}
    if(n==1){printf("0\n");continue;}
    if(n==2){
        if(a[1].w<a[2].w)printf("0\n");
        if(a[1].w>a[2].w)printf("-1\n");
        continue;
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++)a[i].w=i;
    if(n==3){
        printf("%d\n",h[a[1].p][a[2].p][a[3].p][3][4][5][6][0]-1);
    }
    if(n==4){
        printf("%d\n",h[a[1].p][a[2].p][a[3].p][a[4].p][4][5][6][1]-1);
    }
    if(n==5){
         printf("%d\n",h[a[1].p][a[2].p][a[3].p][a[4].p][a[5].p][5][6][2]-1);
    }
    if(n==6){
        printf("%d\n",h[a[1].p][a[2].p][a[3].p][a[4].p][a[5].p][a[6].p][6][3]-1);
    }
    if(n==7){
        printf("%d\n",h[a[1].p][a[2].p][a[3].p][a[4].p][a[5].p][a[6].p][a[7].p][4]-1);
    }
}
    return 0;
}
