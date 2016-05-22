#include <bits/stdc++.h>
using namespace std;


template <typename T>
class RedBlackTree
{
private:
  typedef enum { BLACK, RED } COLOR;

  struct Node
  {
    T data;
    Node *lc,*rc,*pre;
    COLOR color;
    Node()
    {
      lc = rc = pre = NULL;
      color = BLACK;
    }
    Node(const T& _data, Node *_pre, COLOR _color)
    {
      data = _data;
      pre = _pre;
      lc = rc = NULL;
      color = _color;
    }
  }*nul;
  typedef Node* ptr;
  void show_tree(ptr now)
  {
    if (now == nul) {cout << '#'; return;}
    cout << (now->color == BLACK ? 'B' : 'R');
    cout << '(' << now->data << ',';
    show_tree(now->lc);
    cout << ',';
    show_tree(now->rc);
    cout << ')';
  }
  void rotate_right(ptr x)
  {
    ptr y = x->pre;
    y->lc = x->rc; if (x->rc != nul) x->rc->pre = y;
    x->pre = y->pre; if(y->pre != nul) (y->pre->lc == y ? y->pre->lc:y->pre->rc) = x;
    y->pre = x; x->rc = y;
    if(y == root) root = x;
  }
  void rotate_left(ptr x)
  {
    ptr y = x->pre;
    y->rc = x->lc; if(x->lc != nul) x->lc->pre = y;
    x->pre = y->pre; if(y->pre != nul) (y->pre->lc == y ? y->pre->lc : y->pre->rc) = x;
    y->pre = x; x->lc = y;
    if(y == root) root = x;
  }
public:
  ptr root;
  RedBlackTree() { nul = new Node(); clear(); }
  void clear() { root = nul; }
  void printtree()
  {
    show_tree(root);
  }
  void insert(const T& data)
  {
    ptr y = nul, *x = &root;
    //find the place to insert
    while(*x != nul)
    {
      y = *x;
      if (data < (*x)->data)
        x = &((*x)->lc);
      else
        x = &((*x)->rc);
    }
    //insert
    *x = new Node(data, y, RED);
    ptr p = *x;
    p->lc = p->rc = nul;

    // adjust
    ptr uncle, pa, gpa;
    while (p->pre->color == RED)
    {
      pa = p->pre;
      gpa = p->pre->pre;
      if (gpa->lc == pa)
      {
        uncle = gpa->rc;
        if (uncle->color == RED)
        {
          gpa->color = RED;
          uncle->color = BLACK;
          pa->color = BLACK;
          p = gpa;
          continue;
        }
        if (pa->rc == p)
        {
          rotate_left(p);
          p = p->lc;
        }
        p->pre->color = BLACK;
        p->pre->pre->color = RED;
        rotate_right(p->pre);
      }
      else
      {
        uncle = p->pre->pre->lc;
        if (uncle->color == RED)
        {
          gpa->color = RED;
          uncle->color = BLACK;
          pa->color = BLACK;
          p = gpa;
          continue;
        }
        if (pa->lc == p)
        {
          rotate_right(p);
          p = p->rc;
        }
        p->pre->color = BLACK;
        p->pre->pre->color = RED;
        rotate_left(p->pre);
      }
    }
    if (p->pre == nul)
    {
      p->color = BLACK;
      root = p;
      return;
    }
  }

  bool remove(T data)
  {
    ptr *x = &root;
    while(*x != nul)
    {
      if((*x)->data == data)
      {
        //需要删除的节点有两个孩子节点，将该节点与其左子树中最大的节点交换
        if((*x)->lc != nul && (*x)->rc != nul)
        {
          ptr tmp = (*x)->lc;
          while (tmp->rc != nul)
            tmp = tmp->rc;
          data = (*x)->data = tmp->data;
          x = &((*x)->lc);
        }
        else
        {
          //三种简单情况的处理
          if ((*x)->lc->color == RED)
          {
            (*x)->lc->pre = *x;
            *x = (*x)->lc;
            (*x)->color = BLACK;
            return true;
          }
          if ((*x)->rc->color == BLACK)
          {
            (*x)->rc->pre = *x;
            *x = (*x)->rc;
            (*x)->color = BLACK;
            return true;
          }
          if ((*x)->color == RED)
          {
            *x = nul;
            return true;
          }

          //adjust
          ptr pre = (*x)->pre;
          if ((*x)->lc != nul)
          {
            (*x)->lc->pre = *x;
            *x = (*x)->lc;
          }
          else if ((*x)->rc != nul)
          {
            (*x)->rc->pre = *x;
            *x = (*x)->rc;
          }
          else *x = nul;
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
                rotate_left(tmp);
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
                    rotate_right(tmp->lc);
                    tmp = pre->rc;
                }
                tmp->color = pre->color;
                pre->color = BLACK;
                tmp->rc->color = BLACK;
                rotate_left(tmp);
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
              rotate_right(tmp);
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
                  rotate_left(tmp->rc);
                  tmp = pre->lc;
              }
              tmp->color = pre->color;
              pre->color = BLACK;
              tmp->lc->color = BLACK;
              rotate_right(tmp);
              return true;
            }
            }
          }

        }
      }
      else if (data < (*x)->data)
        x = &((*x)->lc);
      else
        x = &((*x)->rc);
    }
    return false;
  }

  bool query(const T& data)
  {
    ptr p = root;
    while (p != nul)
    {
      if (p->data == data) return true;
      if(p->data > data)
        p = p->lc;
      else
        p = p->rc;
    }
    return false;
  }
};


RedBlackTree <int> rbt;

int main()
{


  for (int i = 0; i < 10; i++)
    rbt.insert(i);

  rbt.printtree();
  cout << endl;
  for (int i = 0; i < 9; i++)
    rbt.remove(i);
  rbt.printtree();
  return 0;
}
