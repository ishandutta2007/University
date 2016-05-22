#include <bits/stdc++.h>

using namespace std;
const int char_lenth = 10;
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
unsigned int BKDRHash(string str)
{
  unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
  unsigned int hash = 0;
  for (int i = 0, len = str.length(); i < len; i++)
    hash = hash * seed + str[i];
  return (hash & 0x7FFFFFFF) % mod;
}
class HashTableInterface
{
public:
  virtual void clear() = 0;
  virtual int insert(const string&) = 0;
  virtual int query(const string&) = 0;
};

class HashTableClose : public HashTableInterface
{
private:
  vector<string> tb[mod];
public:
  void clear()
  {
    for (int i = 0; i < mod ; i++)
      tb[i].clear();
  }
  HashTableClose(){ clear(); }
  int insert(const string& str)
  {
    int h = BKDRHash(str);
    tb[h].push_back(str);
    return h;
  }
  int query(const string &str)
  {
    int h = BKDRHash(str);
    for (int i = 0, len = tb[h].size(); i < len; i++)
      if(tb[h][i] == str) return h;
    return -1;
  }
};

class HashTableOpen : public HashTableInterface
{
private:
  string tb[mod];
public:
  int insert(const string &str)
  {
    int h = BKDRHash(str);
    while(tb[h] != "")
      if(++h >= mod)
        h = 0;
    tb[h] = str;
    return h;
  }
  int query(const string &str)
  {
    int h = BKDRHash(str);
    while(tb[h] != "" && tb[h] != str)
      if(++h >= mod)
        h = 0;
    if(tb[h] == "") return -1;
    return h;
  }
  void clear()
  {
    for (int i = 0; i < mod; i++)
      tb[i].clear();
  }
  HashTableOpen(){clear();}
};

void DoHash(HashTableInterface *ht, const string hint, int n)
{
  cout << "operations on " + hint << endl;
  // system("pause");
  ht->clear();
  int stime, dtime;
  stime = clock();
  for (int i = 0; i < n; i++)
    ht->insert(data[i]);
  dtime = clock() - stime;
  cout << "insert " << n << " strings in " << dtime << " ms" << endl;
  // system("pause");
  stime = clock();
  for (int i = 0; i < n; i++)
  {
    int h = ht->query(data[i]);
    if(h) cout << "found at " << h << endl;
    else cout << "not found" << endl;
  }
  dtime = clock() - stime;
  cout << "query " << n << " strings in " << dtime << " ms" << endl;
  // system("pause");
}
HashTableClose hc;
HashTableOpen ho;
int main()
{
  freopen("data.out", "w", stdout);
  int n = 100000;
  datamaker(n, char_lenth);

  // DoHash((HashTableInterface *)(&hc), "HashTableClose", n);
  DoHash((HashTableInterface *)(&ho), "HashTableCOpen", n);

  return 0;
}
