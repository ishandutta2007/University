#include <bits/stdc++.h>
#define first X
#define second Y


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;

set<int> tot, tmp, vis;
vector<int> ans;

int main()
{
  int n, k, x;
  scanf("%d",&n);

  for (int i = 0; i < n; i++)
  {
    tmp.clear();
    scanf("%d", &k);
    for (int j = 0; j < k; j++)
    {
      scanf("%d", &x);
      tmp.insert(x);
    }
    if (tmp.size() <= 1) continue;
    for (int x : tmp) tot.insert(x);
  }
  
  scanf("%d", &n);
  int flag = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    if (tot.count(x) == 0 && vis.count(x) == 0)
    {
      flag = 1;
      // printf("%05d ", x);
      vis.insert(x);
      ans.push_back(x);
    }
  }
  if (flag == 0)
    printf("No one is handsome\n");
  for (int i = 0, len = ans.size(); i < len; i++)
    printf("%05d%c", ans[i], i == len-1? '\n' : ' ');
  return 0;
}
