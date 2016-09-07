#include <bits/stdc++.h>
#define first X
#define second Y


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;

int hh, mm;


int main()
{
  scanf("%d:%d", &hh, &mm);
  

  if (hh < 12 || (hh == 12 && mm == 0))
  {
    printf("Only %02d:%02d.  Too early to Dang.\n", hh, mm);
    return 0;
  }
  

  int cnt = 0;
  if (mm == 0) cnt = 0;
  else cnt = 1;
  
  cnt += hh - 12;
  
  for (int i = 0; i < cnt; i++)
    cout << "Dang";
  
  cout << endl;
  return 0;
}
