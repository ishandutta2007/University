#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;


struct Trie{
    struct Node{
        bool end;
        char words[20];
        Node *next[26];
    };
    Node *head = new Node();

    void insert(char *s1, char *s2)
    {
        int len = strlen(s1);
        Node *now = head;
        for (int i = 0; i < len; i++)
        {
            int x = s1[i] - 'a';
            if (now->next[x] == NULL)
            {
                now->next[x] = new Node();
                now->next[x]->end = false;
                memset(now->next[x]->next, 0, sizeof(now->next[x]->next));
            }
            now = now->next[x];
            if (i == len - 1){
                now->end = true;
                strcpy(now->words, s2);
            }
        }
    }
    void query(char *s, char *s2)
    {
        int len = strlen(s);
        Node *now = head;
        for (int i = 0; i < len; i++)
        {
            int x = s[i] - 'a';
            if (now->next[x] == NULL){
                strcpy(s2, s);
                return;
            }
            now = now->next[x];
            if (i == len - 1){
                if(now->end) strcpy(s2, now->words);
                else strcpy(s2, s);
                return;
            }
        }
        strcpy(s2, s);
        return;
    }

}T;




int main(){


    char s1[20], s2[20];
    scanf("%s", s1);

    while(scanf("%s", s1) != EOF){
        if(s1[0] == 'E'){
            scanf("%s", s1);//omit the START
            break;
        }

        scanf("%s", s2);
        T.insert(s2, s1);

    }
    getchar();
    char ch;
    int p = 0;
    while(true){
        scanf("%c", &ch);
        if(ch < 'a' || ch > 'z'){
            if(ch == 'E') return 0;
            if(p > 0){
                s1[p] = '\0';
                T.query(s1, s2);
                printf("%s", s2);
            }
            printf("%c", ch);
            p = 0;
        }
        else{
            s1[p++] = ch;
        }
    }




    return 0;
}
