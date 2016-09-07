#include <bits/stdc++.h>
#define F1 first
#define F2 second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 100002;
const int oo = (int)1e9+7;

set<char> st;

class DNASequence
{
public:
  int longestDNASequence(string s)
  {
    st.insert('A');
    st.insert('T');
    st.insert('C');
    st.insert('G');
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < s.length(); i ++)
    {
      if (st.count(s[i]))
      {
        tmp++;
      }
      else
        tmp = 0;
      ans = max(ans, tmp);
    }
    return ans;
  }

};

