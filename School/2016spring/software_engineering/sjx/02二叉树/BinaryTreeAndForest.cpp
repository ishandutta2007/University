#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

const int MAXV = 1011;
template < typename T >
class BinaryTree
{
public:
    struct Node
    {
        int id; T data; //Assumed
        Node *Lchild, *Rchild;
        inline Node() { Lchild = Rchild = NULL; }
    };
    typedef Node* ptr;

    ptr _createTree(const T A[], int I, int N)
    {
        if (I > N || A[I] == 0) return NULL;
        ptr p = new Node;
        p->data = A[I];
        p->Lchild = _createTree(A, I << 1, N);
        p->Rchild = _createTree(A, I << 1 | 1, N);
        return p;
    }

    void Visit(ptr p, char chr)
    { cout << p->data; if (chr) cout << chr; }
    void TreeEmptyOutput()
    { cout << "Tree is Empty."; }
    void _GeneralizedListDisplay(ptr p)
    {
        if (!p)
        {
            cout << '#';
            return;
        }
        cout << '(' << p->data << ',';
        _GeneralizedListDisplay(p->Lchild);
        cout << ',';
        _GeneralizedListDisplay(p->Rchild);
        cout << ')';
    }

    ptr root;
    BinaryTree() { root = NULL; }
    void createTree(const T A[], int N)
    { root = _createTree(A, 1, N); }

	void GeneralizedListDisplay()
	{
        if (!root)
        {
            TreeEmptyOutput();
            return;
        }
	    _GeneralizedListDisplay(root);
	    printf("\n\n");
	}
};

int father[MAXV];
queue < int > q;

template < typename T >
class Forest
{
public:
    struct Arc
    {
        int dest; Arc *next;
        inline Arc() { next = NULL; }
        inline Arc(int _dest, Arc *_next)
        { dest = _dest, next = _next; }
    }*adj[MAXV]; T data[MAXV];
    int root[MAXV], Nroot;

    inline Forest() { clear(); }
    inline void clear()
    {
        Nroot = 0;
        memset(adj, 0, sizeof(adj));
    }
    inline void insert(int i, int j)
    {
        adj[i] = new Arc(j, adj[i]);
        adj[j] = new Arc(i, adj[j]);
    }
    inline void Display()
    {
        memset(father, 0xff, sizeof(father));
        while (!q.empty())
            q.pop();

        printf("Roots:\n");
        for (int i = 1; i <= Nroot; i++)
        {
            printf("%d ", root[i]);
            q.push(root[i]);
        }

        printf("\n\nArcs:\n");
        while (!q.empty())
        {
            int i = q.front(); q.pop();
            for (Arc *p = adj[i]; p; p = p->next)
                if (p->dest != father[i])
                {
                    printf("%d %d\n", i, p->dest);
                    q.push(p->dest);
                    father[p->dest] = i;
                }
        }

        printf("\n");

    }
};

BinaryTree < int > :: ptr *nowp[MAXV];
BinaryTree < int > ForestToBinaryTree(Forest < int > f)
{
    BinaryTree < int > ret;
    memset(father, 0, sizeof(father));
    memset(nowp, 0, sizeof(nowp));
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= f.Nroot; i++)
        q.push(f.root[i]);

    nowp[0] = &ret.root;
    while (!q.empty())
    {
        int i = q.front(); q.pop();
        BinaryTree < int > :: ptr p = *nowp[father[i]] = new BinaryTree < int > :: Node;
        nowp[father[i]] = &((*nowp[father[i]])->Rchild);
        p->id = i, p->data = f.data[i];
        nowp[i] = &(p->Lchild);

        for (Forest <int> :: Arc *p2 = f.adj[i]; p2; p2 = p2->next)
            if (p2->dest != father[i])
            {
                father[p2->dest] = i;
                q.push(p2->dest);
            }
    }
    return ret;
}

void _BinaryTreeToForest(BinaryTree < int > :: ptr p, int father, Forest < int > &ret)
{
    if (father == -1)
        ret.root[++ret.Nroot] = p->id;
    else
        ret.insert(p->id, father);
    ret.data[p->id] = p->data;
    if (p->Lchild)
        _BinaryTreeToForest(p->Lchild, p->id, ret);
    if (p->Rchild)
        _BinaryTreeToForest(p->Rchild, father, ret);
}

Forest < int > BinaryTreeToForest(BinaryTree < int > b)
{
    Forest < int > ret;
    _BinaryTreeToForest(b.root, -1, ret);
    return ret;
}

Forest < int > forest;
BinaryTree < int > bt;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("BinaryTreeAndForest.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int V, E;
    scanf("%d%d", &V, &E);
    for (int i = 1; i <= V; i++)
        scanf("%d", &forest.data[i]);

    for (int i = 1; i <= E; i++)
    {
        int s, t;
        scanf("%d%d", &s, &t);
        forest.insert(s, t);
    }
    scanf("%d", &forest.Nroot);
    for (int i = 1; i <= forest.Nroot; i++)
        scanf("%d", &forest.root[i]);

    bt = ForestToBinaryTree(forest);
    printf("Forest Converted to BinaryTree:\n");
    bt.GeneralizedListDisplay();

    forest = BinaryTreeToForest(bt);
    printf("BinaryTree Converted to Forest:\n");
    forest.Display();

    return 0;
}
