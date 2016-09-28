/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int oo = 1e9+7;
const int maxn = 1e5+20;

char bf[maxn];
int n;


int cnt1, cnt2, ans1, ans2;

int main()
{
  scanf("%d", &n);
  scanf("%s", bf);
  
  cnt1 = cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (bf[i] == 'b' && i%2 == 0)
      cnt1++;
    if (bf[i] == 'r' && i%2 == 1)
      cnt2++;
  }
  ans1 = max(cnt1, cnt2);
  cnt1 = cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (bf[i] == 'b' && i%2 == 1)
      cnt1++;
    if (bf[i] == 'r' && i%2 == 0)
      cnt2++;
  }
  ans2 = max(cnt1, cnt2);
  cout << min(ans1, ans2) << endl;
  return 0;
}

