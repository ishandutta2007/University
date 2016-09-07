#include <bits/stdc++.h>
#define first X
#define second Y


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;


int ma, mb;
int nowa, nowb;
int a, b;
int pa, pb;


int main()
{
  scanf("%d%d", &ma, &mb);
  int n;
  scanf("%d", &n);

  while(nowa <= ma && nowb <= mb)
  {
    scanf("%d%d%d%d", &a, &pa, &b, &pb);  
    int sum = a + b;
    if (pa == pb || (pa != sum && pb != sum))
      continue;
    if (pa == sum) nowa++;
    else nowb++;
  }

  if (nowa > ma)
  {
    cout << "A" << endl << nowb << endl;
  }
  else
    cout << "B" << endl << nowa << endl;
  return 0;
}
