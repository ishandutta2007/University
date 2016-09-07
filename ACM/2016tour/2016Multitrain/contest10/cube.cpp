#include <bits/stdc++.h>

using namespace std;
const int maxn = 100;
char bf[maxn][maxn];
map<char, char> mp;
struct CB{
  char s[10][10];
  CB(){}
  bool in()
  {
    for (int i = 0; i < 8; i++)
    {
      if (scanf("%s", bf[i]) == EOF) return false;
    }
    s[1][0]=bf[0][0];s[1][1]=bf[0][1];s[1][2]=bf[1][1];s[1][3]=bf[1][0];
    s[2][0]=bf[2][0];s[2][1]=bf[2][1];s[2][2]=bf[3][1];s[2][3]=bf[3][0];
    s[3][0]=bf[2][2];s[3][1]=bf[2][3];s[3][2]=bf[3][3];s[3][3]=bf[3][2];
    s[5][0]=bf[2][4];s[5][1]=bf[2][5];s[5][2]=bf[3][5];s[5][3]=bf[3][4];
    s[6][0]=bf[4][0];s[6][1]=bf[4][1];s[6][2]=bf[5][1];s[6][3]=bf[5][0];
    s[4][0]=bf[6][0];s[4][1]=bf[6][1];s[4][2]=bf[7][1];s[4][3]=bf[7][0];
    return true;
  }
  void show()
  {
    for (int i = 1; i <= 6; i++)
      printf("[%s]\n", s[i]);
    printf("==========\n");
  }
}a,ar,b;

void rotsingle(char *s, bool counter)
{
  if (counter)
  {
    char tmp = s[0];
    for (int i = 0; i < 3; i++)
      s[i] = s[i+1];
    s[3] = tmp;
  }
  else
  {
    char tmp = s[3];
    for (int i = 3; i > 0; i--)
      s[i] = s[i-1];
    s[0] = tmp;
  }
}

void rotx(CB &cb)
{
  // front
  rotsingle(cb.s[3], 0);
  // back
  rotsingle(cb.s[4], 1);
  char tmp[10];
  rotsingle(cb.s[2], 0);
  rotsingle(cb.s[6], 0);
  rotsingle(cb.s[5], 0);
  rotsingle(cb.s[1], 0);
  strcpy(tmp,cb.s[1]);
  strcpy(cb.s[1], cb.s[2]);
  strcpy(cb.s[2], cb.s[6]);
  strcpy(cb.s[6], cb.s[5]);
  strcpy(cb.s[5], tmp);
}
void roty(CB &cb)
{
  rotsingle(cb.s[5], 0);
  rotsingle(cb.s[2], 1);
  char tmp[10];
  strcpy(tmp, cb.s[1]);
  strcpy(cb.s[1], cb.s[3]);
  strcpy(cb.s[3], cb.s[6]);
  strcpy(cb.s[6], cb.s[4]);
  strcpy(cb.s[4], tmp);
}

void rotz(CB &cb)
{
  rotsingle(cb.s[1], 0);
  rotsingle(cb.s[6], 1);
  rotsingle(cb.s[4], 1);
  rotsingle(cb.s[4], 1);
  rotsingle(cb.s[2], 1);
  rotsingle(cb.s[2], 1);
  char tmp[10];
  strcpy(tmp, cb.s[2]);
  strcpy(cb.s[2], cb.s[3]);
  strcpy(cb.s[3], cb.s[5]);
  strcpy(cb.s[5], cb.s[4]);
  strcpy(cb.s[4], tmp);
}
void getrsingle(char *s1, char *s2)
{
  s1[0] = s2[1];
  s1[1] = s2[0];
  s1[2] = s2[3];
  s1[3] = s2[2];
}

void getr()
{
  getrsingle(ar.s[1], a.s[1]);
  getrsingle(ar.s[3], a.s[3]);
  getrsingle(ar.s[6], a.s[6]);
  getrsingle(ar.s[4], a.s[4]);
  getrsingle(ar.s[5], a.s[2]);
  getrsingle(ar.s[2], a.s[5]);
}


bool check(CB &cb)
{
  mp.clear();
  for (int i = 1; i <= 6; i++)
    for (int j = 0; j < 4; j++)
    {
      if (mp.count(cb.s[i][j]))
      {
        if (mp[cb.s[i][j]] != b.s[i][j])
          return false;
      }
      else
        mp[cb.s[i][j]] = b.s[i][j];
    }
  return true;
}

bool rot()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        getr();
        if (check(a) || check(ar)) return true;
        rotz(a);
      }
      roty(a);
    }
    rotx(a);
  }
  return false;
}

int main()
{
  #ifndef ONLINE_JUDGE
  //freopen("data.in", "r", stdin);
  freopen("test.in", "r", stdin);
  a.in();
  a.show();
  getr();
  ar.show();
  return 0;
  #endif
  while(a.in())
  {
    // a.show();
    b.in();
    
    /*
    printf("a\n");
    a.show();
    printf("ar\n");
    ar.show();
    printf("b\n");
    b.show();
    */

    if (rot()) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
