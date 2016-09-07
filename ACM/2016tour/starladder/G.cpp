#include <bits/stdc++.h>
#define first X
#define second Y


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;

string s;
int cnt[4];
char ch[5] = "GPLT";

int main()
{
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'G' || s[i] == 'g') cnt[0]++;
    if (s[i] == 'P' || s[i] == 'p') cnt[1]++;
    if (s[i] == 'L' || s[i] == 'l') cnt[2]++;
    if (s[i] == 'T' || s[i] == 't') cnt[3]++;
  }
  int sum = cnt[0] + cnt[1] + cnt[2] + cnt[3];
  int pos = 0;
  
  while(sum--)
  {
    while(cnt[pos] == 0) pos = (pos+1) % 4;
    cout << ch[pos];
    cnt[pos]--;
    pos = (pos+1) % 4;
  }
  cout << endl;
  return 0;
}
