#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>

using namespace std;

struct Trie
{
    struct Node
    {
        bool end;
        int id;
        Node *next[26];
    };
    Node *head;
    void clear()
    {
        head = new Node();
    }

    void insert(char *s, int id)
    {
        int len = strlen(s);
        Node *now = head;
        for (int i = 0; i < len; i++)
        {
            int x = s[i] - 'a';
            if (now->next[x] == NULL)
            {
                now->next[x] = new Node();
                now->next[x]->end = false;
                memset(now->next[x]->next, 0, sizeof(now->next[x]->next));
            }
            now = now->next[x];
            if (i == len - 1){
                now->end = true;
                now->id = id;
            }
        }
    }
    int query(char *s)
    {
        int len = strlen(s);
        Node *now = head;
        for (int i = 0; i < len; i++)
        {
            int x = s[i] - 'a';
            if (now->next[x] == NULL)
                return false;
            now = now->next[x];
            if (i == len - 1){
                if(now->end) return now->id;
                else return 0;
            }
        }
        return 0;
    }
} t;


int fa[500020];
int tot = 1;
int divs[500020];

int root(int i){
    if(fa[i] == i)
        return i;

    fa[i] = root(fa[i]);
    return fa[i];
}
void unionset(int a, int b){
    int ra = root(a);
    int rb = root(b);

    if(ra == rb) return;

    fa[ra] = rb;

}


int main(){
    t.clear();
    char s1[24], s2[24];

    for(int i = 0; i < 500000; i++)
        fa[i] = i;
    int id1, id2;
    while(scanf("%s%s", s1, s2) == 2){
        if(s1[0] == '!') break;
        if(!t.query(s1)) t.insert(s1, tot++);
        if(!t.query(s2)) t.insert(s2, tot++);
        id1 = t.query(s1);
        id2 = t.query(s2);
//        printf("%s %d\n", s1, id1);
//        printf("%s %d\n", s2, id2);
        divs[id1]++;
        divs[id2]++;
        unionset(id1, id2);
    }

    bool flag = true;
    int rot = root(1);

    for(int i = 1; i < tot; i++)
        if(root(i) != rot) flag = false;

//    for(int i = 1; i < tot; i++)
//        printf("%d %d\n", i, root(i));

    int cnt = 0;
    for(int i = 1; i < tot; i++)
        if(divs[i] % 2 == 1) cnt++;
    if(cnt != 2 && cnt != 0) flag = false;

    if(flag) printf("Possible\n");
    else printf("Impossible\n");

    return 0;
}

