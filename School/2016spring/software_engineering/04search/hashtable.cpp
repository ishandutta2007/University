#include <bits/stdc++.h>
using namespace std;


const int mod = 200000;

vector<string> data;
void datamaker(int n, int l)
{
  srand((unsigned)time(NULL));
  data.clear();
  for (int i = 0; i < n; i++)
  {
    string tmp = "";
    for (int i = 0; i < l; i++)
      tmp.push_back(rand()%94 + 33);
    data.push_back(tmp);
  }
}

class HashTable
{
public:
  vector <string> tb[mod];
  // BKDR Hash Function
  unsigned int BKDRHash(string str)
  {
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    for (int i = 0, len = str.length(); i < len; i++)
      hash = hash * seed + str[i];
    return (hash & 0x7FFFFFFF) % mod;
  }
  void insert(string str)
  {
    unsigned int hashvalue = BKDRHash(str);
    tb[hashvalue].push_back(str);
  }
  bool search(string str)
  {
    unsigned int hashvalue = BKDRHash(str);
    for (int i = 0, len = tb[hashvalue].size(); i < len; i++)
      if(tb[hashvalue][i] == str) return true;
    return false;
  }
  void clear()
  {
    for (int i = 0; i < mod; i++)
      tb[i].clear();
  }
  HashTable()
  {
    clear();
  }
}hashtable;



int main()
{
  int n = 100000, l = 10;
  datamaker(n, l);
  int stime = clock();
  for (int i = 0; i < n; i++)
    hashtable.insert(data[i]);

  int etime = clock();
  cout << etime - stime << endl;
  system("pause");

  stime = clock();

  for (int i = 0; i < n; i++)
  {
    hashtable.search(data[i]);
    // if (hashtable.search(data[i]))
    //   cout << (data[i] + " found !") << endl;
    // else
    //   cout << (data[i] + " not found !") << endl;
  }
  etime = clock();
  cout << etime - stime << endl;
  return 0;
}