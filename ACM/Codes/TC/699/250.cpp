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
const int maxn = 1e4+20;


class OthersXor {
public:
  ll minSum(vector <int> x) {
      
    int n = x.size();
    vector<ll> vi;


    bool has1 = false;
    for (int i = 0; i < n; i++)
      if (x[i] != -1)
        vi.push_back(x[i]);
      else
        has1 = true;
    
    n = vi.size();
    if (n % 2 == 0) {
      ll ysum = 0;
      for (int i = 0; i < n; i++)
        ysum ^= vi[i];
      ll ret = 0;
      for (int i = 0; i < n; i++)
        ret += ysum ^ vi[i];
    }
    else {
      ll ret = 0;
      ll ysum = 0;
      for (int i = 0; i < n; i++) {
        ysum ^= vi[i];
        ret = max(ysum, ret);
      }
      if (ysum != 0 && !has1) return -1;
      return ysum + ret;
    }
  }
};

