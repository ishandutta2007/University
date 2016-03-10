#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

template < typename T >
class BinaryTree
{
private:

    typedef enum { CHILD, THREAD } PointerTag;
    struct Node
    {
        T data; //Assumed
        Node* Father;
        Node* Lchild;
        Node* Rchild;

        PointerTag LTag, RTag;
    }*root;
    typedef Node* ptr;

    ptr _createTree(const T A[], int I, int N, ptr Father)
    {
        if (I > N || A[I] == 0) return NULL;
        ptr p = new Node;
        p->data = A[I];
        p->Father = Father;
        p->LTag = (p->Lchild = _createTree(A, I << 1, N, p)) ? CHILD : THREAD;
        p->RTag = (p->Rchild = _createTree(A, I << 1 | 1, N, p)) ? CHILD : THREAD;
        return p;
    }

    void Visit(ptr p, char chr)
    { cout << p->data; if (chr) cout << chr; }
    void TreeEmptyOutput()
    { cout << "Tree is Empty."; }

    ptr pre;
    void _PreOrderThreading(ptr p)
    {
        if (!p) return;
        if (pre && pre->RTag == THREAD)
            pre->Rchild = p;
        if (p->LTag == THREAD)
            p->Lchild = pre;
        pre = p;
        if (p->LTag == CHILD)
            _PreOrderThreading(p->Lchild);
        if (p->RTag == CHILD)
            _PreOrderThreading(p->Rchild);
    }
    void _GeneralizedListDisplay(ptr p)
    {
        cout << '(' << p->data << ',';
        if (p->LTag == THREAD)
        {
            cout << '[';
            if (p->Lchild) cout << p->Lchild->data;
            else cout << '#';
            cout << ']';
        }
        else _GeneralizedListDisplay(p->Lchild);
        cout << ',';
        if (p->RTag == THREAD)
        {
            cout << '['; // Data in "[]" means THREAD-Node-Data not CHILD
            if (p->Rchild) cout << p->Rchild->data;
            else cout << '#';
            cout << ']';
        }
        else _GeneralizedListDisplay(p->Rchild);
        cout << ')';
    }

    ptr getFirstInOrder(ptr p)
    {
        while (p->LTag == CHILD)
            p = p->Lchild;
        return p;
    }

    struct SearchNode
    {
        ptr p; int Tab, H;
        inline SearchNode() { }
        inline SearchNode(ptr _p, int _Tab, int _H)
        { p = _p, Tab = _Tab, H = _H; }
    };

public:
    void createTree(const T A[], int N)
    {
        root = _createTree(A, 1, N, NULL);
    }
    void VerticalDisplay()
    {
        if (!root)
        {
            TreeEmptyOutput();
            return;
        }
        stack < SearchNode > Stack;
        Stack.push(SearchNode(root, 0, 0));

        while (!Stack.empty()) //DFS
        {
            SearchNode ip = Stack.top(); Stack.pop();

            while (ip.H > ip.Tab)
            {
                cout << '\t';
                ip.Tab++;
            }
            Visit(ip.p, '\t');

            if (ip.p->LTag == CHILD && ip.p->RTag == CHILD)
            {
                Stack.push(SearchNode(ip.p->Rchild, 0, ip.H + 1));
                Stack.push(SearchNode(ip.p->Lchild, ip.Tab + 1, ip.H + 1));
            }
            else if (ip.p->LTag == CHILD)
                Stack.push(SearchNode(ip.p->Lchild, ip.Tab + 1, ip.H + 1));
            else if (ip.p->RTag == CHILD)
                Stack.push(SearchNode(ip.p->Rchild, 0, ip.H + 1));
            if (ip.p->LTag != CHILD)
                cout << '\n';
        }
    }

	void PreOrderThreading()
	{
        pre = NULL;
        _PreOrderThreading(root);
	}

	void GeneralizedListDisplay()
	{
        if (!root)
        {
            TreeEmptyOutput();
            return;
        }
	    _GeneralizedListDisplay(root);
	}

	void PreThreadingInOrderTraversal()
	{
        if (!root)
        {
            TreeEmptyOutput();
            return;
        }

	    ptr p = getFirstInOrder(root);
	    bool Final = false;
	    while (!Final)
        {
            if (p->Rchild == NULL)
                Final = true;
            ptr tmp = p->Rchild;
            Visit(p, ' ');
            while (p->Father && (p->RTag == THREAD || p->Rchild != tmp))
            {
                if (p->Father->Rchild != p || p->Father->RTag != CHILD)
                    Visit(p->Father, ' ');
                p = p->Father;
            }
            if (!Final)
                p = getFirstInOrder(p->Rchild);
        }
	}
};

BinaryTree < int > bt;
const int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, N = 11;
//const int A[] = {0, 1, 2, 3, 4, 0, 0, 0, 8}, N = 8; // '0' means empty tree
int main()
{
	//Tree Input
	//Const Array Instead of Inputting

    //Tree created & displayed
    cout << "\n";
    bt.createTree(A, N);
    cout << "\nDisplayed in Vertical Mode:\n";
	bt.VerticalDisplay();

    //Pre order threading & displayed (in generalized list)
    bt.PreOrderThreading();
    cout << "\n\nAfter PreOrder Threading:\n";
    bt.GeneralizedListDisplay(); //guang yi biao

    cout << "\n\nInOrder Traversal after PreOrder Threading:\n";
    bt.PreThreadingInOrderTraversal();

    cout << "\n";
    return 0;
}
