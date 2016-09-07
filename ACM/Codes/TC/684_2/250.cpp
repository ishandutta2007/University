#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int> pq;

int cnt[30];

class Istr
{
  public:
    int count(string str, int k)
    {
      for (int i = 0, len = str.length(); i < len; i++)
        cnt[str[i]-'a']++;
      
      for (int i = 0; i < 26; i++) if (cnt[i] > 0)
        pq.push(cnt[i]);
      
      while(k-- && !pq.empty())
      {
        int tmp = pq.top();
        pq.pop();
        if (tmp > 1)
          pq.push(tmp-1);
      }
      
      int ret = 0;
      while(!pq.empty())
      {
        ret += pq.top()*pq.top();
        pq.pop();
      }
      return ret;
    }
};
