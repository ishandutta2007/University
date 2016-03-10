#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define __maxn 100005

using namespace std;

char ss[10001];
char s[130];
int tot;
deque<int>q;
vector<int>v;
struct Trie{
    short fail, next[100], id;
}trie[__maxn];
bool vis[520];

void __insert(char *s1, int id)
{
    int cur = 1;
    for(int i = 0; s1[i]; i++)
    {
        if(!trie[cur].next[s1[i]-' '])
            trie[cur].next[s1[i]-' '] = ++tot;
        cur = trie[cur].next[s1[i]-' '];
    }
    trie[cur].id = id;
}

void build_acauto()
{
    q.clear();
    q.push_back(1);
    trie[1].fail = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop_front();
        for(int i = 0;i<100;i++)if(trie[cur].next[i])
        {
            int next = trie[cur].next[i];
            if(cur == 1)
            {
                trie[next].fail = 1;
            }
            else
            {
                int tmp = trie[cur].fail;
                while(tmp != 1 && trie[tmp].next[i] == 0) tmp = trie[tmp].fail;
                if(trie[tmp].next[i])
                {
                    trie[next].fail = trie[tmp].next[i];
                }
                else
                {
                    trie[next].fail = 1;
                }
            }
            q.push_back(next);
        }
    }
}

void __query(char *s, vector<int>&v)
{   
    memset(vis, 0, sizeof(vis));
    int cur = 1,tmp = 0;
    for(int i = 0; s[i]; i++)
    {
        // printf("%d\n", i);
        if(trie[cur].next[s[i]-' ']) cur = trie[cur].next[s[i]-' '];
        else
        {
            while(cur != 1 && trie[cur].next[s[i]-' '] == 0) {cur = trie[cur].fail;}
            if(trie[cur].next[s[i]-' ']) cur = trie[cur].next[s[i]-' '];
        }
        // tmp = cur;
        // while(tmp != 1 && trie[tmp].id)
        // {
        //     v.push_back(trie[tmp].id);
        //     tmp = trie[tmp].fail;
        //     // printf("tmp = %d\n", tmp);
        // }
        // // printf("%d\n", i);
        if(trie[cur].id && !vis[trie[cur].id])
        {
            tmp++;
            v.push_back(trie[cur].id);
            vis[trie[cur].id] = true;
        }
        if(tmp >= 3) return;
    }
}



void __clear()
{
    memset(trie, 0, sizeof(trie));
    tot = 1;
}

int main()
{
    // printf("%d\n", sizeof(trie) / 1024);
    __clear();
    int viru, web;

    scanf("%d", &viru);
    getchar();
    for(int i = 1; i <= viru; i++)
    {
        gets(s);
        __insert(s, i);
    }
    scanf("%d", &web);
    getchar();
    int ans = 0;
    // return 0;
    build_acauto();
    for(int i = 1; i <= web; i++)
    {
        gets(ss);
        v.clear();
        __query(ss, v);
        if(v.size())
        {
            ans ++;
            sort(v.begin(), v.end());
            printf("web %d:", i);
            for(int i = 0, len = v.size(); i < len; i++)
                printf(" %d", v[i]);
            printf("\n");
        }
    }
    printf("total: %d\n", ans);
    return 0;
}