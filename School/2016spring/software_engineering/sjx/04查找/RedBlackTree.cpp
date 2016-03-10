#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

template < typename T, int maxN >
class RedBlackTree
{
private:
    typedef enum { BLACK, RED } COLOR;

	struct Node
	{
		T data; int id; Node *lc, *rc, *pre; COLOR color;
		inline Node() { data = 0, id = 0, lc = rc = pre = NULL; color = BLACK; }
		inline Node(int _id, const T& _data, Node *_pre, COLOR _color)
		{ id = _id, data = _data, pre = _pre; lc = rc = NULL; color = _color;}
	}Npool[maxN], *Nptr, *NIL; int top;
	typedef Node* ptr;

    void _GeneralizedListDisplay(ptr p)
    {
        if (p == NIL) { cout << '#'; return; }
        cout << (p->color == BLACK ? 'B' : 'R');
        cout << '(' << p->data << ',';
        _GeneralizedListDisplay(p->lc);
        cout << ',';
        _GeneralizedListDisplay(p->rc);
        cout << ')';
    }

	inline void RR(ptr x)
	{
		ptr y = x->pre;
		y->lc = x->rc; if (x->rc != NIL) x->rc->pre = y;
		x->pre = y->pre; if (y->pre != NIL) (y->pre->lc == y ? y->pre->lc : y->pre->rc) = x;
		y->pre = x; x->rc = y;
		if (y == root) root = x;
	}
	inline void RL(ptr x)
	{
		ptr y = x->pre;
		y->rc = x->lc; if (x->lc != NIL) x->lc->pre = y;
		x->pre = y->pre; if (y->pre != NIL) (y->pre->lc == y ? y->pre->lc : y->pre->rc) = x;
		y->pre = x; x->lc = y;
		if (y == root) root = x;
	}

public:
	ptr root;

	inline RedBlackTree() { NIL = new Node(0, 0, NULL, BLACK); clear(); }
    inline void printTree() { _GeneralizedListDisplay(root); }
    inline void clear() { Nptr = Npool; root = NIL; }

	inline void insert(int id, const T& data)
	{
        ptr y = NIL, *x = &root;
        while (*x != NIL)
        {
            y = *x;
            if (data < (*x)->data)
                x = &((*x)->lc);
            else
                x = &((*x)->rc);
        }
        *x = new(Nptr++)Node(id, data, y, RED);
        ptr p = *x;
        p->lc = p->rc = NIL;

        while (p->pre->color == RED)
        {
            if (p->pre->pre->lc == p->pre)
            {
                ptr tmp = p->pre->pre->rc;
                if (tmp->color == RED)
                {
                    p->pre->pre->color = RED; //grandparent
                    tmp->color = BLACK; //uncle
                    p->pre->color = BLACK; //parent
                    p = p->pre->pre;
                    continue; //?
                }
                if (p->pre->rc == p)
                {
                    RL(p);
                    p = p->lc;
                }
                p->pre->color = BLACK;
                p->pre->pre->color = RED;
                RR(p->pre);
            }
            else
            {
                ptr tmp = p->pre->pre->lc;
                if (tmp->color == RED)
                {
                    p->pre->pre->color = RED;
                    tmp->color = BLACK;
                    p->pre->color = BLACK;
                    p = p->pre->pre;
                    continue;
                }
                if (p->pre->lc == p)
                {
                    RR(p);
                    p = p->rc;
                }
                p->pre->color = BLACK;
                p->pre->pre->color = RED;
                RL(p->pre);
            }
        }

        if (p->pre == NIL)
        {
            p->color = BLACK;
            root = p;
            return;
        }
	}
	inline bool remove(T data)
	{
	    ptr *x = &root;
        while (*x != NIL)
        {
            if ((*x)->data == data)
            {
                if ((*x)->lc != NIL && (*x)->rc != NIL)
                {
                    ptr tmp = (*x)->lc;
                    while (tmp->rc != NIL)
                        tmp = tmp->rc;
                    data = (*x)->data = tmp->data;
                    x = &((*x)->lc);
                }
                else
                {
                    if ((*x)->lc->color == RED)
                    {
                        (*x)->lc->pre = *x;
                        *x = (*x)->lc;
                        (*x)->color = BLACK;
                        return true;
                    }
                    if ((*x)->rc->color == RED)
                    {
                        (*x)->rc->pre = *x;
                        *x = (*x)->rc;
                        (*x)->color = BLACK;
                        return true;
                    }
                    if ((*x)->color == RED)
                    {
                        *x = NIL;
                        return true;
                    }

                    ptr pre = (*x)->pre;
                    if ((*x)->lc != NIL)
                    {
                        (*x)->lc->pre = *x;
                        *x = (*x)->lc;
                    }
                    else if ((*x)->rc != NIL)
                    {
                        (*x)->rc->pre = *x;
                        *x = (*x)->rc;
                    }
                    else
                        *x = NIL;

                    ptr p = *x;
                    while (p != root && p->color == BLACK)
                    {
                        if (pre->lc == p)
                        {
                            ptr tmp = pre->rc;
                            if (tmp->color == RED)
                            {
                                tmp->color = BLACK;
                                pre->color = RED;
                                RL(tmp);
                                tmp = pre->rc;
                            }
                            if (tmp->lc->color == BLACK && tmp->rc->color == BLACK)
                            {
                                tmp->color = RED;
                                p = pre;
                                pre = p->pre;
                            }
                            else
                            {
                                if (tmp->lc->color == RED && tmp->rc->color == BLACK)
                                {
                                    tmp->lc->color = BLACK;
                                    tmp->color = RED;
                                    RR(tmp->lc);
                                    tmp = pre->rc;
                                }
                                tmp->color = pre->color;
                                pre->color = BLACK;
                                tmp->rc->color = BLACK;
                                RL(tmp);
                                return true;
                            }
                        }
                        else
                        {
                            ptr tmp = pre->lc;
                            if (tmp->color == RED)
                            {
                                tmp->color = BLACK;
                                pre->color = RED;
                                RR(tmp);
                                tmp = pre->lc;
                            }
                            if (tmp->rc->color == BLACK && tmp->lc->color == BLACK)
                            {
                                tmp->color = RED;
                                p = pre;
                                pre = p->pre;
                            }
                            else
                            {
                                if (tmp->rc->color == RED && tmp->lc->color == BLACK)
                                {
                                    tmp->rc->color = BLACK;
                                    tmp->color = RED;
                                    RL(tmp->rc);
                                    tmp = pre->lc;
                                }
                                tmp->color = pre->color;
                                pre->color = BLACK;
                                tmp->lc->color = BLACK;
                                RR(tmp);
                                return true;
                            }
                        }
                    }
                    return true;
                }
            }
            else if (data < (*x)->data)
                x = &((*x)->lc);
            else
                x = &((*x)->rc);
        }
        return false;
	}
	inline bool query(const T& data)
	{
	    ptr p = root;
	    while (p != NIL)
        {
            if (p->data == data)
                return true;
            if (data < p->data)
                p = p->lc;
            else
                p = p->rc;
        }
        return false;
	}
};

const int MAXN = 100011;
RedBlackTree < int, MAXN > rbt; int M;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("BIT.in", "r", stdin);
	//freopen("BIT.out", "w", stdout);
#endif
	scanf("%d", &M);

    int TreeN = 0;
	for (int i = 1; i <= M; ++i)
	{
	    int method, num;
		scanf("%d%d", &method, &num);

		if (method == 1)
        {
            printf("Now inserting %d.\n", num);
            rbt.insert(++TreeN, num);
        }
        else if (method == 2)
        {
            printf("Now removing %d. ", num);
            if (rbt.remove(num))
                printf("It succeeds.");
            else
                printf("It doesn't exist.");
            printf("\n");
        }
        else
        {
            printf("Query %d: %s.\n", num, rbt.query(num) ? "Exist" : "Not exist");
        }
		rbt.printTree();
		printf("\n\n");
	}

	printf("Finally the Red Black Tree acts:\n");
	rbt.printTree();
	return 0;
}
