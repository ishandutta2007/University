#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    struct Node
    {
        bool end;
        Node *next[26];
    };
    Node *head;
    void clear(Node *p)
    {
        if (!p)
            return ;
        for (int i = 0; i < 26; i++)
            if (p->next[i] != NULL)
                clear(p->next[i]);
        delete p;
    }
    void clear()
    {
        clear(head);
        head = new Node();
        memset(head->next, 0, sizeof(head->next));
        head->end = false;
    }
    void insert(char *s)
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
            if (i == len - 1)
                now->end = true;
        }
    }
    bool query(char *s)
    {
        int len = strlen(s);
        Node *now = head;
        for (int i = 0; i < len; i++)
        {
            int x = s[i] - 'a';
            if (now->next[x] == NULL)
                return false;
            now = now->next[x];
            if (i == len - 1)
                return now->end;
        }
        return false;
    }
} t;
int main()
{



    t.clear();
    char s[1111];
    int cmd;
    while (cin >> cmd >> s)
        if (cmd == 1)
            t.insert(s);
        else
            cout << (int)t.query(s) << endl;
}
