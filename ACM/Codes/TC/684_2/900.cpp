#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dist[100][100];
class Autohamil
{
  public:
    string check(vector<int> z0, vector<int> z1)
    {
      int n = z0.size();
      for (int i = 0; i < n; i++)
        dist[i][z0[i]] = dist[i][z1[i]] = 1;
      
      for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
          for (int j = 0; j < n; j++)
            dist[i][j] = (dist[i][j] || (dist[i][k] && dist[k][j]));

      for (int i = 0; i < n; i++)
      {
        if (i != 0 && dist[0][i] == 0)
          return "Does not exist";
        for (int j = 0; j < n; j++)
          if (i != j && dist[i][j] == 0 && dist[j][i] == 0)
            return "Does not exist";
      }
      return "Exists";
    }
};
