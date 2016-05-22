#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int> tii;

tii totii(int x)
{
  int c2 = 0, c3 = 0;
  while (x%2==0)
  {
    c2++;
    x /= 2;
  }
  while (x%3==0)
  {
    c3++;
    x /= 3;
  }
  return make_tuple(c2, c3);
}

set< vector<int> > st;

void dfs(vector<int> &p)
{
 // for (int i = 0; i < 9; i++)
    //printf("%d%c", p[i], i == 8 ? '\n' : ' ');
  if (st.count(p)) return;
  st.insert(p);

  for (int a = 0; a < 3; a++)
    for (int b = 0; b < 3; b++) if (p[a*3+b] != 0)
      for (int c = 0; c < 3; c++)
        for (int d = 0; d < 3; d++) if (p[c*3+d] != 0)
        {
          for (int i = 0; i < 2; i++)
          {
            vector<int> tmp = p;
            tmp[a*3 + b]--;
            tmp[c*3 + d]--;
            if (tmp[a*3 + b] < 0) continue;
            int c2, c3;

            if (i == 0)
            {
              c2 = min(a, c);
              c3 = min(b, d);
            }
            else
            {
              c2 = max(a, c);
              c3 = max(b, d);
            }
            tmp[c2*3 + c3]++;
            if (st.count(tmp) == 0)
              dfs(tmp);
          }
        }
}





class LCMGCD
{
public:
  string isPossible(vector <int> x, int t)
  {
    int w2, w3, p2, p3;
    tie(w2, w3) = totii(t);
    vector<int> p(9);
    for (auto y: x)
    {
      tie(p2, p3) = totii(y);

      if (p2 == w2) p2 = 1;
      else if (p2 > w2) p2 = 2;
      else p2 = 0;
      if (p3 == w3) p3 = 1;
      else if (p3 > w3) p3 = 2;
      else p3 = 0;

      if (p2 == 1 && p3 == 1)
        p[p2*3+p3] ++;
      else 
        p[p2*3+p3] = 1;

    }

    dfs(p);

    vector<int> dest(9, 0);
    dest[1*3+1] = 1;

    return st.count(dest)? "Possible":"Impossible";

  }
};
