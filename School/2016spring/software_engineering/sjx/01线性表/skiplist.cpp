#define ONLINE_JUDGE
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

const int MAXP = 10111, MAXK = 511;

template < typename T, T INF, T NINF >
class SkipList
{
public:
    struct Node
    {
        T value; Node *next, *down;
        inline Node() { next = down = NULL; }
        inline Node(const T& _value, Node *_next, Node *_down)
        { value = _value, next = _next, down = _down; }
    }Npool[MAXP], *Nptr, *adj[MAXK]; int NK;

    inline SkipList() { init(); }

    static int randomLevel()
    {
        int K = 1;
        while (rand() % 2)
            K++;
        if (K >= MAXK)
            K = MAXK - 1;
        return K;
    }

    inline void init()
    {
        Nptr = Npool;
        Node *TAIL = new(Nptr++)Node(INF, NULL, NULL);

        adj[0] = new(Nptr++)Node(NINF, TAIL, NULL);
        for (int i = 1; i < MAXK; i++)
            adj[i] = new(Nptr++)Node(NINF, TAIL, adj[i - 1]);
        NK = 0;
    }

    inline void insert(const T& value)
    {
        int K = randomLevel();

        Node *preLevel = NULL;
        Node *p = adj[K - 1];

        while (p)
        {
            while (p->value != INF)
            {
                if (value >= p->value && value < p->next->value)
                {
                    Node *tmp = new(Nptr++)Node(value, p->next, NULL);
                    p->next = tmp;

                    if (preLevel)
                        preLevel->down = tmp;
                    preLevel = tmp;
                    break;
                }
                p = p->next;
            }
            p = p->down;
        }
        if (K > NK)
            NK = K;
    }

    inline bool remove(const T& value)
    {
        bool ret = false;

        Node *p = adj[NK - 1];
        while (p)
        {
            while (p->next->value < value)
                p = p->next;
            if (p->next->value == value)
            {
                Node *tmp = p->next;
                p->next = tmp->next;
                delete tmp;
                ret = true; //At least one Node removed.
            }
            p = p->down;
        }
        while (NK > 0 && adj[NK - 1]->next->value == INF)
            NK--;
        return ret;
    }

    inline bool query(const T& value)
    {
        Node *p = adj[NK - 1];
        while (p)
        {
            while (p->next->value < value)
                p = p->next;
            if (p->next->value == value)
                return true;
            p = p->down;
        }
        return false;
    }
};

SkipList < int, 0x7f7f7f7f, 0x80808080 > sl;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //srand(time(0));
    srand(0);

    int N;
    scanf("%d", &N);

    while (N--)
    {
        int op, value;
        scanf("%d%d", &op, &value);

        switch (op)
        {
        case 1:
            sl.insert(value);
            printf("Inserting succeeded.\n");
            break;
        case 2:
            if (sl.remove(value))
                printf("Removing succeeded.\n");
            else
                printf("Value doesn't exists.\n");
            break;
        case 3:
            if (sl.query(value))
                printf("Found.\n");
            else
                printf("Not found.\n");
            break;
        default:
            printf("Unknown command.\n");
            break;
        }
    }

    return 0;
}
