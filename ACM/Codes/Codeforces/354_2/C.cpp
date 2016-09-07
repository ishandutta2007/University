#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100002;
const ll oo = (int)1e9+7;

char str[maxn];
int n, k;

int main()
{
  scanf("%d%d", &n,&k);
  scanf("%s", str + 1);
  
  int ans = 0;
  int pre = 0, rest = k;
  for (int i = 1; i <= n; i++)
  {
    if (str[i] == 'a')
    {
      ans = max(ans, i - pre);
      continue;
    }
    rest--;
    if (rest < 0)
    {
      while(str[pre+1] == 'a') pre++;
      while(str[pre+1] == 'b') pre++, rest++;
    }
    ans = max(ans, i - pre);
  }
    
  rest = k;
  pre = 0;
  for (int i = 1; i <= n; i++)
  {
    if (str[i] == 'b')
    {
      ans = max(ans, i - pre);
      continue;
    }
    rest--;
    if (rest < 0)
    {
      while(str[pre+1] == 'b') pre++;
      while(str[pre+1] == 'a') pre++, rest++;
    }
    ans = max(ans, i - pre);
  }
  
  cout << ans << endl;

  return 0;
}
