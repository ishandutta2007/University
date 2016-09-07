#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;

vector<int> hp;
int n, m;

int main()
{
  scanf("%d%d", &n, &m);
  
  int x;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    push_heap(hp.begin(), hp.end(), greater<int>);
  }
  





  return 0;
}
