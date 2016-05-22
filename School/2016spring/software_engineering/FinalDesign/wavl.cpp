#include <bits/stdc++.h>

using namespace std;

template< typename T >
class wavl {
private:
  struct Node {
    T data;
    int rank, pos;
    Node *lc, *rc;
    Node(){}
    Node(T _data, int _rank, int _pos):
    data(_data),rank(_rank),pos(_pos),lc(nul),rc(nul){}
  };
  Node *root, *nul;

  void RL(Node *Ro, Node *Pi)
  {
    Node *tmp = Pi->lc;
    Pi->lc = Pi->rc;
    Pi->rc = Ro->rc;
    Ro->rc = Ro->lc;
    Ro->lc = tmp;
    swap(Ro->data, Pi->data);
    swap(Ro->pos, Pi->pos);
    // update_height(Pi);
    // update_height(Ro);
  }
  void RR(Node *Ro, Node *Pi)
  {
    Node *tmp = Pi->rc;
    Pi->rc = Pi->lc;
    Pi->lc = Ro->lc;
    Ro->lc = Ro->rc;
    Ro->rc = tmp;
    swap(Ro->data, Pi->data);
    swap(Ro->pos, Pi->pos);
    // update_height(Pi);
    // update_height(Ro);
  }

public:


  wavl()
  {
    nul = NULL;
    nul = Node(0, 0, -1);
    root = nul;
  }
};

int main()
{

  return 0;
}
