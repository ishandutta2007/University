#include <bits/stdc++.h>
using namespace std;
class AVL
{
public:
    struct Node
    {
      int data, height;
      int pos;
      Node *lson, *rson;
      void show() { printf("%d(%d,%d):|%d|\n", data, lson? lson->data:-1,rson? rson->data:-1, height); }
      Node(){}
      Node(int d, int he, int pos):data(d),height(he),pos(pos),lson(NULL),rson(NULL){}
      Node(int d, int pos):data(d),height(1),pos(pos),lson(NULL),rson(NULL){}
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
    void sa(Node *now, FILE *fp)
    {
      if (now == NULL)
      {
        fprintf(fp, "-1 -1 -1\n");
      }
      else
      {
        fprintf(fp, "%d %d %d\n", now->data, now->height, now->pos);
      }
    }
    void save(Node *now, FILE *fp)
    {
      if (now == NULL)
      {
        sa(now, fp);
        return;
      }
      sa(now, fp);
      save(now->lson, fp);
      save(now->rson, fp);
    }
    void load(Node *&now, FILE *fp, int &pos, int &tid)
    {
      int da, he, po;
      fscanf(fp, "%d%d%d", &da, &he, &po);
      if (da == -1 && he == -1 && po == -1)
        now = NULL;
      else
      {
        if (pos < po)
        {
          pos = po;
          tid = da;
        }
        now = new Node(da, he, po);
        load(now->lson, fp, pos, tid);
        load(now->rson, fp, pos, tid);
      }
    }
    void update_height(Node *r){
      r->height = max(r->lson==NULL? 0:r->lson->height, r->rson==NULL? 0:r->rson->height) + 1; 
    }
    int get_height(Node *r){return r == NULL? 0:r->height;}
    void rotate_right(Node *Ro, Node *Pi)
    {
      Node *tmp = Pi->lson;
      Pi->lson = Pi->rson;
      Pi->rson = Ro->rson;
      Ro->rson = Ro->lson;
      Ro->lson = tmp;
      swap(Ro->data, Pi->data);
      swap(Ro->pos, Pi->pos);
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
      swap(Ro->pos, Pi->pos);
      update_height(Pi);
      update_height(Ro);
    }
    void rotate(Node *now)
    {
      update_height(now);
      if(abs(get_height(now->lson) - get_height(now->rson)) <= 1) return;
      int b1 = get_height(now->lson) - get_height(now->rson);
      int b2 = b1 > 0? (get_height(now->lson->lson) - get_height(now->lson->rson)):
                      (get_height(now->rson->lson) - get_height(now->rson->rson));
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
    void insert(Node *&now, int d, int pos)
    {
      if(now == NULL)
      {
        now = new Node(d, pos);
        return ;
      }
      if(now->data == d) return;
      if(now->data > d)
        insert(now->lson, d, pos);
      else 
        insert(now->rson, d, pos);
      rotate(now);
    }
    Node* search(Node *now, int d) {return now == NULL? NULL:(now->data == d? now:(now->data > d? search(now->lson,d):search(now->rson,d)));}
    int getMinData(Node *now)
    {
      while(now->lson) now = now->lson;
      return now->data;
    }
    void del(Node *&now, int d)
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
    bool del_data(int d)
    {
      if(!search(root, d)) return false;
      del(root, d);
      return true; 
    }
};


/*

int main()
{
    int x;
    for (int i = 0; i < 50; i++)
    {
      x = rand() % 50;
      // scanf("%d", &x);
      avl.insert(avl.root, x, 1);
    }

    cout << "=========" << endl;
    avl.show(avl.root);
    cout << "=========" << endl;
    while(true)
    {
      scanf("%d", &x);
      printf("%s\n", avl.del_data(x)? "deleted":"not found");
      cout << "=========" << endl;
      avl.show(avl.root);

      cout << "=========" << endl;
    }


    return 0;
}

*/

/*
1 2 3 4 5 6 7 8 9 10
*/
