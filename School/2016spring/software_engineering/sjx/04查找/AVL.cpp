#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX3511

const int MAXINT = 0x7f7f7f7f;
template < typename T, int maxN >
class AVL
{
private:
	struct Node
	{
		T data; int h; Node *lc, *rc;
		inline Node() { h = 1; lc = rc = NULL; }
		inline Node(const T& _data) { data = _data; h = 1; lc = rc = NULL; }
		inline int height() { return this ? h : 0; }
		inline void update() { h = max(lc->height(), rc->height()) + 1; }
	}Npool[maxN], *Nptr;
	typedef Node* ptr;

	inline void RL(ptr &p) { ptr tmp = p->rc->lc; p->rc->lc = p; p = p->rc; p->lc->rc = tmp; p->lc->update(); p->update(); }
	inline void RR(ptr &p) { ptr tmp = p->lc->rc; p->lc->rc = p; p = p->lc; p->rc->lc = tmp; p->rc->update(); p->update(); }
	inline void lf(ptr &p) { if (p->rc->rc->height() < p->rc->lc->height()) RR(p->rc); RL(p); }
	inline void rf(ptr &p) { if (p->lc->lc->height() < p->lc->rc->height()) RL(p->lc); RR(p); }

	inline void rotate(ptr &p)
	{
		p->update();
		if (p->lc->height() + 1 < p->rc->height()) lf(p);
		if (p->rc->height() + 1 < p->lc->height()) rf(p);
	}

    inline void _GeneralizedListDisplay(ptr p)
    {
        if (!p)
        {
            cout << '#';
            return;
        }
        cout << '(' << p->data << ',';
        _GeneralizedListDisplay(p->lc);
        cout << ',';
        _GeneralizedListDisplay(p->rc);
        cout << ')';
    }

public:
	ptr root;

	inline AVL() { clear(); }
	inline void clear() { Nptr = Npool; root = NULL; }
	inline void printTree() { _GeneralizedListDisplay(root); }
	inline T getMinData(ptr p)
	{
		while (p->lc != NULL)
			p = p->lc;
		return p->data;
	}
	inline void _insert(const T& data, ptr &p)
	{
		if (p == NULL)
			p = new(Nptr++)Node(data);
		else if (data < p->data)
			_insert(data, p->lc);
		else
			_insert(data, p->rc);
		rotate(p);
	}
	inline void _remove(const T& data, ptr &p)
	{
		if (p == NULL)
			return;
		if (data == p->data)
			if (p->lc && p->rc)
			{
				p->data = getMinData(p->rc);
				_remove(p->data, p->rc);
			}
			else if (p->lc != NULL)
				p = p->lc;
			else if (p->rc != NULL)
				p = p->rc;
			else
				p = NULL;
		else if (data < p->data)
			_remove(data, p->lc);
		else
			_remove(data, p->rc);
		if (p != NULL)
			rotate(p);
	}
    inline bool query(const T& data)
	{
	    ptr p = root;
	    while (p)
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
AVL < int, MAXN > avl; int M;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("BIT.in", "r", stdin);
	//freopen("BIT.out", "w", stdout);
#endif
	scanf("%d", &M);

	for (int i = 1; i <= M; ++i)
	{
	    int method, num;
		scanf("%d%d", &method, &num);

		if (method == 1)
        {
            printf("Now inserting %d.\n", num);
            avl._insert(num, avl.root);
        }
        else if (method == 2)
        {
            printf("Now removing %d. ", num);
            if (avl.query(num))
            {
                avl._remove(num, avl.root);
                printf("It succeeds.");
            }
            else
                printf("It doesn't exist.");
            printf("\n");
        }
        else
        {
            printf("Query %d: %s.\n", num, avl.query(num) ? "Exist" : "Not exist");
        }
		avl.printTree();
		printf("\n\n");
	}

	printf("Finally the AVL Tree acts:\n");
	avl.printTree();
	return 0;
}
