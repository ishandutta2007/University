#include <bits/stdc++.h>
#define F1 first
#define F2 second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn =2000+7;
const int oo = (int)1e9+7;

set<string> st[20];

string ans;
int len;
char ch[4] = {'A', 'T', 'C', 'G'}; 
void dfs(string now)
{
  if (now.length() == len)
  {
    if (st[len].count(now) == 0)
      ans = now;
    return;
  }
  
  for (int i = 0; i < 4; i++)
  {
    dfs(now+ch[i]);
  }
}


class TopBiologist
{
public:
  string findShortestNewSequence(string src)
  {
    int n = src.length();
    string tmp = "";
    for (int s = 0; s < n; s++)
    {
      tmp.clear();
      for (int i = s; i < n; i++)
      {
        tmp.push_back(src[i]);
        if (i-s+1 <= 11)
	      st[i-s+1].insert(tmp);
      }
    }
    
    len = 1;
    while( st[len].size() == (1<<(2*len)) )
      len++;
    
    tmp.clear();
    dfs(tmp);
    
    return ans;
  }


};
