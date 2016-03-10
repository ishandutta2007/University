#include<iostream>
#include<stdio.h>
#include<string.h>


char s1[1000];
char s2[1000];


void get_nextval(const char *T, int next[])
{
    int j = 0, k = -1;
    next[0] = -1;
    while ( T[j] != '\0' )
    {
        if (k == -1 || T[j] == T[k])
        {
           ++j; ++k;
           if (T[j]!=T[k])
               next[j] = k;
           else
               next[j] = next[k];
        }
        else
            k = next[k];
   }
}
int KMPTimes(const char *Text,const char* Pattern)
{
    if( !Text || !Pattern ||  Pattern[0]=='\0' || Text[0]=='\0' )//
        return -1;//空指针或空串，返回-1。
    int len = strlen(Pattern);
    int *next=new int[len+1];
    get_nextval(Pattern,next);//求Pattern的next函数值
    int index=0,i=0,j=0;
    int ans = 0;
    while(Text[i]!='\0')
    {

        if(Pattern[j] == '\0')
        {
            ans ++;
            j = 0;
            i -= len - 1;
            continue;
        }
        if(Text[i]== Pattern[j])
        {
            ++i;// 继续比较后继字符
            ++j;
        }
        else
        {
            index += j-next[j];
            if(next[j]!=-1)
                j=next[j];// 模式串向右移动
            else
            {
                j=0;
                ++i;
            }
        }
    }
    if(Pattern[j] == '\0')
        ans ++;
    delete []next;
    return ans;
}
int main()//abCabCad
{
    int n;
    scanf("%d",&n);
    while(n --){
        scanf("%s%s",s1,s2);
        printf("%d\n",KMPTimes(s2, s1));
    }
    return 0;
}
