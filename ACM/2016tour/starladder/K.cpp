#include <bits/stdc++.h>
#define first X
#define second Y


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;


struct Node
{
  int d;
  int lc, rc;
  Node(int d, int lc, int rc):d(d), lc(lc), rc(rc){}
  Node(){}
}node[50];



int ldr[50], dlr[50];
int n;
int tot = 0;
int pos = 1;
deque<int> deq;
vector<int> ans;

int build(int l, int r)
{
  if (l > r) return -1;
  int p;
  int d = dlr[pos++];
  for (int i = l; i <= r; i++)
  {
    if (ldr[i] == d)
      p = i;
  }
  int id = tot++;
  node[id].d = d;
  node[id].lc = build(l,p-1);
  node[id].rc = build(p+1, r);
  return id;
}


int main()
{
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    scanf("%d", &ldr[i]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &dlr[i]);

  int root = build(1, n);
  
  deq.push_back(root);
  int id;
  while(!deq.empty())
  {
    id = deq.front();
    deq.pop_front();
    if (id == -1) continue;
    ans.push_back(node[id].d);
    deq.push_back(node[id].rc);
    deq.push_back(node[id].lc);
  }
  
  for (int i = 0, len = ans.size(); i < len; i++)
    printf("%d%c", ans[i], i == len-1? '\n' : ' ');
  return 0;
}
