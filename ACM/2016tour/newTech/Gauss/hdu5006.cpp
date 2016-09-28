#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int maxn = 1000;
const int MX = 40020;

double a[maxn][maxn];
double v[maxn];
typedef pair<int, double> edge;

const double eps = 1e-8;

void gauss(int n) {
  int k=1;
  for (int i=1;i<=n;i++) {
    int p=0;
    for (int j=k;j<=n;j++) if (fabs(a[j][i])>eps) {
      p=j; 
      break;
    }
    if (!p) continue;
    for (int l=1;l<=n+1;l++) swap(a[p][l],a[k][l]);
    for (int j=k+1;j<=n;j++) {
      double rate=a[j][i]/a[k][i];
      for (int l=1;l<=n+1;l++) 
        a[j][l]-=a[k][l]*rate;
    }
    k++;
  }
  for (int i=n;i;i--) {
    v[i]=a[i][n+1];
    for (int j=i+1;j<=n;j++)
      v[i]-=v[j]*a[i][j];
    v[i]/=a[i][i];
  }
}

int f[MX];
int n, m;
int S, T;
int U[MX], V[MX], C[MX];
map<int, int> G[MX];
map<int, int> Ha;

void addedge(int u, int v) {
  if (u == v) return;
  if (!G[u].count(v)) G[u][v] = 0;
  G[u][v]++;
  if (!G[v].count(u)) G[v][u] = 0;
  G[v][u]++;
}

int root(int x) {
  if (f[x] != x) {
    f[x] = root(f[x]);
  }
  return f[x];
}

void unionset(int a, int b) {
  int ra = root(a);
  int rb = root(b);
  f[ra] = f[rb];
}

bool found;
int tot;
int vis[MX];

void dfs(int now) {
  vis[now] = 1;
  tot++;
  Ha[now] = tot;
  if (now == T) {
    found = 1;
  }
  for (auto e : G[now]) if (!vis[e.X]) {
    dfs(e.X);
  }
}


int main() {

  #ifndef ONLINE_JUDGE
  freopen("data2.in", "r", stdin);
  #endif
  int TT;
  scanf("%d", &TT);
  while (TT--) {
    scanf("%d%d%d%d", &n,&m,&S,&T);
    int tu,tv,tc;
    for (int i = 1; i <= n; i++) {
      f[i] = i;
      G[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &U[i], &V[i], &C[i]);
      if (C[i] == 0) {
        unionset(U[i], V[i]);
      }
    }
    for (int i = 1; i <= m; i++) {
      if (C[i] == 1) {
        addedge(root(U[i]), root(V[i]));
      }
    }
    found = false;
    tot = 0;
    memset(vis,0,sizeof(vis));
    Ha.clear();
    S = root(S);
    T = root(T);
    if (S == T) {
      printf("0.000000\n");
      continue;
    }
    dfs(S);
    if (!found) {
      printf("inf\n");
      continue;
    }
    memset(a, 0, sizeof(a));
    memset(v, 0, sizeof(v));
    for (auto tmp : Ha) {
      int p = tmp.X;
      int id = tmp.Y;
      if (p == S) {
        a[id][id] = 1.0;
        a[id][tot+1] = 1.0;
      }
      else if (p == T) {
        a[id][id] = 1.0;
        a[id][tot+1] = 0.0;
      }
      else 
      {
        for (auto e : G[p]) {
          int v = e.X;
          double d = 1.0*e.Y;
          a[id][id] += d;
          a[id][Ha[v]] -= d;
        }
      }
    }
    assert(tot < maxn);
    gauss(tot);
    double sum = 0.0;
    for (auto e : G[S]) {
      sum += (v[Ha[S]]-v[Ha[e.X]])*e.Y;
    }
    assert(fabs(sum) > eps);
    double ans = 1.0/sum;
    printf("%.6f\n", ans);
  }
  return 0;
}

