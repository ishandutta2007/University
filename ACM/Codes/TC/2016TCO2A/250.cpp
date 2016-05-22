#include <bits/stdc++.h>

using namespace std;

const int maxn = 52;
typedef long long ll;
typedef pair<int , int > PII;
typedef pair <ll, PII> PPP;

pair <ll, PII> de, vn[maxn];
pair <ll, PII> tonode(int x)
{
  int c2 = 0, c3 = 0;
  while (x % 2 == 0)
  {
    c2++;
    x /= 2;
  }
  while (x % 3 == 0)
  {
    c3++;
    x /= 3;
  }
  return pair<ll, PII>(0LL, PII(c2, c3));
}

PPP Node(ll mask, int c2, int c3)
{

  return PPP(mask, PII(c2,c3));
}

void show(PPP p)
{
  cout << p.first << " " << p.second.first << " " << p.second.second << endl;
}

set<pair<ll, PII> > st;
int n;
deque<PPP> deq;

class LCMGCD
{
public:
  string isPossible(vector <int> x, int t)
  {
    n = x.size();
    de = tonode(t);
    de.first = (1 << n) - 1;
    for (int i = 0; i < n; i++)
      vn[i] = tonode(x[i]);

    deq.push_back(Node(0,0,0));
    PPP now, tmp;
    while(!deq.empty())
    {
      now = deq.front();
      deq.pop_front();
      if (now == de) return "Possible";
      for (int i = 0; i < n; i++) if (((now.first >> i)&1) == 0)
      {
        if (now.first == 0)
        {
          tmp = vn[i];
          vn[i].first = 1 << i;
          deq.push_back(tmp);
          continue;
        }
        tmp = Node(now.first | (1<<i), max(vn[i].second.first, now.second.first), max(vn[i].second.second, now.second.second));
        // show(tmp);
        if (st.find(tmp) == st.end()) {deq.push_back(tmp);st.insert(tmp);}
        tmp = Node(now.first | (1<<i), min(vn[i].second.first, now.second.first), min(vn[i].second.second, now.second.second));
        // show(tmp);
        // cout << "========" << endl;
        if (st.find(tmp) == st.end()) {deq.push_back(tmp);st.insert(tmp);}
      }
    }
    return (st.find(de) != st.end())? "Possible" : "Impossible";
  }
}L;



int main()
{
  vector<int> vi;
  vi.push_back(2);
  vi.push_back(3);  

  cout << L.isPossible(vi, 6) << endl;

  return 0;
}
