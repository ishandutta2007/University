#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
int sg[23333333];
int yy,mm,dd,y,m,num,flag1,flag2;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int leapyears (int ye)
{
    if (ye % 400==0) return 1;
    else if (ye % 100 ==0) return 0;
    else if (ye % 4==0) return 1;
    else return 0;
}

int main()
{
    yy=2001;mm=11;dd=4;
    memset(sg,0,sizeof(sg));
    sg[20011104]=0;
    for (int i=20011105;i<=20011231;i++) sg[i]=1;
    while (yy>=1900)
    {
        //cout<<yy<<mm<<dd<<endl;
        num=yy*10000+mm*100+dd;
        //getchar();
        flag1=sg[num];
        dd--;
        if (dd<1)
        {
            mm--;
            if (m<1) {mm=12;yy--;}
            dd=mon[mm];
            if (mm==2) dd+=leapyears(yy);
        }

        m=mm+1;y=yy;
        if (m>12) {y=yy+1;m=1;}
        if (m!=2 && dd > mon[m]) {sg[yy*10000+mm*100+dd]=1-flag1;continue;}
        if (m==2 && dd > mon[m]+leapyears(yy)) {sg[yy*10000+mm*100+dd]=1-flag1;continue;}
        num=y*10000+m*100+dd;
        //cout<<num<<endl;
        flag2=sg[num];
        if (flag1==1 && flag2==1) sg[yy*10000+mm*100+dd]=0;
        else sg[yy*10000+mm*100+dd]=1;
        //cout<<yy<<mm<<dd<<' '<<flag1<<' '<<flag2<<' '<<sg[yy*10000+mm*100+dd]<<endl;
        //getchar();
    }
    int a,b,c,t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        num=a*10000+b*100+c;
        if (sg[num]) printf("YES\n");
        else printf("NO\n");
    }
}