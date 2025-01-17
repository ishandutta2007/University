#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int oo = 0x3f3f3f3f;
const int maxn = 100000;
const double eps=1e-6;

int dcmp(double x)
{
  return fabs(x)<eps?0:(x>0?1:-1);
}


int xx[1020], yy[1020];
int vis[1020][2];
PII pre[1020][2];

int W, n;
double ansx, ansy;
deque<PII> que;

double dist(int p, int x)
{
  return fabs(1.0*x - 1.0*xx[p]);
}
double dist(int p, double x, double y)
// double dist(int p, int x, int y)
{  
  return sqrt((x-xx[p])*(x-xx[p]) + (y-yy[p])*(y-yy[p]));
}


bool check(double w)
{
  memset(vis, 0, sizeof(vis));
  que.clear();
  for (int i = n; i >= 1; i--)
  {
    if(dcmp(w-dist(i, 0))>=0)
    {
      vis[i][0] = 1;
      pre[i][0] = PII(0,-1);
      que.push_back(PII(i, 0));
    }
    else if(dcmp(w*2-dist(i, 0))>=0)
    {
      vis[i][1] = 1;
      pre[i][1] = PII(0,-1);
      que.push_back(PII(i, 1));
    }
  }


  PII now;
  while(!que.empty())
  {
    now = que.front();
    que.pop_front();
    //printf("%d %d\n", now.first, now.second);
    double d;
    {
      d = dist(now.first, W);
      // if (dcmp(w-499999999.5)==0) cout<<d<<endl;
      if((now.second == 1 && dcmp(w-d)>=0) || (now.second == 0 && dcmp(w*2-d)>=0)) 
      {
        if(now.second == 0)
        {
          ansx = 1.0*(W + xx[now.first]) / 2.0;
          ansy = 1.0*yy[now.first];
          //cout << ansx << " ," << ansy << endl;
          // cout << now.first << " : " << now.second << endl;
          // cout << pre[now.first][now.second].first << endl;
          // cout << 1 << endl;
          return true;
        }
        PII tmp = pre[now.first][now.second];
        // cout << "====" << endl;
        while(tmp.second == now.second)
        {
          // cout << now.first << "--" << tmp.first << endl;
          tmp = pre[tmp.first][tmp.second];
          now = pre[now.first][now.second];
        }
        // cout << now.first << "--" << tmp.first << endl;
        // cout << w << endl;
        // cout << "====" << endl;
        if(tmp.first == 0)
        {
          ansx = 1.0*(0 + xx[now.first]) / 2.0;
          ansy = 1.0*yy[now.first];
        }
        else
        {
          ansx = 1.0*(xx[tmp.first] + xx[now.first]) / 2.0;
          ansy = 1.0*(yy[tmp.first] + yy[now.first]) / 2.0;
        }
        // cout << ansx << " ," << ansy << endl;
        // cout << 2 << endl;
        
        return true;
      }
    }

    for (int i = n; i >= 1; i--)
    {
      d = dist(now.first ,xx[i], yy[i]);

      if(now.second == 0)
      {
        if(vis[i][0] == 0 && dcmp(w-d)>=0 && i != now.first)
        {
          pre[i][0] = now;
          vis[i][0] = 1;
          que.push_back(PII(i,0));
        }
        else if(vis[i][1] == 0 && dcmp(w*2-d)>=0 && i != now.first)
        {
          pre[i][1] = now;
          vis[i][1] = 1;
          que.push_back(PII(i,1));
        }
      }
      else
      {
        if(vis[i][1] == 0 && dcmp(w-d)>=0 && i != now.first)
        {
          pre[i][1] = now;
          vis[i][1] = 1;
          que.push_back(PII(i,1));
        }
      }
    }
  }
  return false;

}


int main()
{
    freopen("froggy.in", "r", stdin);
    freopen("froggy.out", "w", stdout);

    scanf("%d%d", &W, &n);

    for (int i = 1; i <= n; i++)
      scanf("%d%d", &xx[i], &yy[i]);

    if(n == 0)
    {
      printf("%.3f 0.000\n", W*1.0 / 2);
      return 0;
    }
    // check(1.0);

    // return 0;

    ansx = W*1.0/2;
    ansy = 0.0;
    double low = 0, high = ansx;
    double mid = (low + high) / 2;
    
    // check(mid);

    while(low - high <= 1e-4)
    {
      double mid = (low + high) / 2;
      // printf("mid = %.5f : ", mid);
      bool flag = check(mid);
      if(flag) high = mid - 1e-4;
      else low = mid + 1e-4;
      // if(flag) printf("true\n");
      // else printf("false\n");
      // system("pause");
    }
    printf("%.5f %.5f\n", fabs(ansx), ansy);
    return 0;
}
