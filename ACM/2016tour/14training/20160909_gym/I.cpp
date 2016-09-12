#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 1e6+10;
const int oo = 1e9+7;

typedef pair<int,int> pii;
typedef long long ll;

deque<char> q1, q2;
char bf[maxn];
int n;

int main()
{
  int T;
  scanf("%d", &T);
  getchar();
  while (T--)
  {
    gets(bf);
    n = strlen(bf);
    q1.clear();q2.clear();
    for (int i = 0; i < n; i++)
    {
      if (bf[i] == '-')
      {
        /*
        for (auto ch : q1)
          printf("%c", ch);
        printf("\n");
        */
        if (!q1.empty())
          q1.pop_back();
        /*
        cout << "!!!" << endl;
        for (auto ch : q1)
          printf("%c", ch);
        printf("\n");
        */
      }
      else if (bf[i] == '<')
      {
        if (!q1.empty())
        {
          char tmp = q1.back();
          q1.pop_back();
          q2.push_front(tmp);
        }
      }
      else if (bf[i] == '>')
      {
        if (!q2.empty())
        {
          char tmp = q2.front();
          q2.pop_front();
          q1.push_back(tmp);
        }
      }
      else
      {
        q1.push_back(bf[i]);
      }
    }
    for (auto ch : q1)
      printf("%c", ch);
    for (auto ch : q2)
      printf("%c", ch);
    printf("\n");
  }
  return 0;
}
