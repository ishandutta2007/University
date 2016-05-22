#include <bits/stdc++.h>
using namespace std;

class SimilarUserDetection
{
public:

  bool hcmp(string a, string b)
  {
    if (a.length() != b.length())
      return false;
    for (int i = 0, len = a.length(); i < len; i++)
      if (!(a[i] == b[i] 
              || ((a[i] == '0' || a[i] == 'O') && (b[i] == '0' || b[i] == 'O')) 
              || ((a[i] == '1' || a[i] == 'I' || a[i] == 'l') && (b[i] == '1' || b[i] == 'I' || b[i] == 'l'))
              ))
        return false;
    return true;
  }



  string haveSimilar(vector <string> handles)
  {
    for (int i = 0, len = handles.size(); i < len; i++)
      for (int j = i + 1; j < len; j++)
        if (hcmp(handles[i], handles[j]))
          return "Similar handles found";
    return "Similar handles not found";
  }
};
