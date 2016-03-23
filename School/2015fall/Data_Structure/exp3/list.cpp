#include <bits/stdc++.h>


typedef int TP;

using namespace std;
const int maxn = 10000;
int n, m;

struct Node
{
    TP data;
    Node *next;
    Node():next(NULL){}
    Node(TP data, Node*next):data(data), next(next){}
    void show()
    {
        cout << data << " ";
    }
    void del()
    {
        delete this;
    }
}head[maxn];

void addedge(TP data, int p)
{
    head[p].next = new Node(data, head[p].next);
}

void showadj()
{
    Node *ptr;
    for(int i = 1; i <= n; i++)
    {
        cout << "head " << i << ": ";
        ptr = head[i].next;
        while(ptr != NULL)
        {
            ptr->show();
            ptr = ptr->next;
        }
        cout << endl;
    }
}

void deladj()
{
    Node *ptr;
    for(int i = 1; i <= n; i++)
    {
        cout << "head " << i << ": ";
        ptr = head[i].next;
        head[i].next = NULL;
        while(ptr != NULL)
        {
            ptr->del();
            ptr = ptr->next;
        }
        cout << endl;
    }
}


int main()
{
    scanf("%d%d", &n,&m);
    int u, v;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }

    showadj();
    return 0;
}


