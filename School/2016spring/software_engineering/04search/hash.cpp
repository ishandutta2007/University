#include <bits/stdc++.h>
using namespace std;
class AVL
{
public:
    struct Node
    {
      unsigned int data;
      int height;
      Node *lson, *rson;
      void show() { printf("%u(%u,%u):|%d|\n", data, lson? lson->data:0,rson? rson->data:0, height); }
      Node(){}
      Node(unsigned int d):data(d),height(1),lson(NULL),rson(NULL){}
    };
    Node *root;
    AVL() { root = NULL; }
    void show(Node *now)
    {
      if(now == NULL) return;
      show(now->lson);
      now->show();
      show(now->rson);
    }
    void update_height(Node *r){ r->height = max(r->lson==NULL? 0:r->lson->height, r->rson==NULL? 0:r->rson->height) + 1; }
    int get_height(Node *r){return r == NULL? 0:r->height;}
    void rotate_right(Node *Ro, Node *Pi)
    {
      Node *tmp = Pi->lson;
      Pi->lson = Pi->rson;
      Pi->rson = Ro->rson;
      Ro->rson = Ro->lson;
      Ro->lson = tmp;
      swap(Ro->data, Pi->data);
      update_height(Pi);
      update_height(Ro);
    }
    void rotate_left(Node *Ro, Node *Pi)
    {
      Node *tmp = Pi->rson;
      Pi->rson = Pi->lson;
      Pi->lson = Ro->lson;
      Ro->lson = Ro->rson;
      Ro->rson = tmp;
      swap(Ro->data, Pi->data);
      update_height(Pi);
      update_height(Ro);
    }
    void rotate(Node *now)
    {
      update_height(now);
      if(abs(get_height(now->lson) - get_height(now->rson)) <= 1) return;
      int b1 = get_height(now->lson) - get_height(now->rson);
      int b2 = b1 > 0? (get_height(now->lson->lson) - get_height(now->lson->rson)):(get_height(now->rson->lson) - get_height(now->rson->rson));
      if(b1 > 0 && b2 >= 0) rotate_right(now, now->lson);
      else if(b1 < 0 && b2 <= 0) rotate_left(now, now->rson);
      else if(b1 > 0 && b2 <= 0)
      {
        rotate_left(now->lson, now->lson->rson);
        rotate_right(now, now->lson);
      }
      else
      {
        rotate_right(now->rson, now->rson->lson);
        rotate_left(now, now->rson);
      }
    }
    void insert(Node *&now, unsigned int d)
    {
      if(now == NULL)
      {
        now = new Node(d);
        return ;
      }
      if(now->data == d) return;
      if(now->data > d)
        insert(now->lson, d);
      else 
        insert(now->rson, d);
      rotate(now);
    }
    bool search(Node *now, unsigned int d) {return now == NULL? false:(now->data == d? true:(now->data > d? search(now->lson,d):search(now->rson,d)));}
    unsigned int getMinData(Node *now)
    {
      while(now->lson) now = now->lson;
      return now->data;
    }
    void del(Node *&now, unsigned int d)
    {
      if (now == NULL) return;
      if (d == now->data)
      {
        if (now->lson && now->rson)
        {
          now->data = getMinData(now->rson);
          del(now->rson, now->data);
        }
        else if (now->lson != NULL)
          now = now->lson;
        else if (now->rson != NULL)
          now = now->rson;
        else
          now = NULL;
      }
      else if (d < now->data) del(now->lson, d);
      else del(now->rson, d);
      if (now != NULL) rotate(now);
    }
    bool del_data(unsigned int d)
    {
      if(!search(root, d)) return false;
      del(root, d);
      return true; 
    }
}avl;

// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}

char str[1000];


int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%s", str);
      unsigned int H = BKDRHash(str);

      if(avl.search(avl.root, H))
      {
        printf("%s existed!\n", str);
      }
      else
      {
        avl.insert(avl.root, H);
        printf("%s inserted!\n", str);
      }
    }

    return 0;
}
