#define maxn 100020
using namespace std;
vector<int>v[maxn];
bool instack[maxn];
int dfn[maxn], low[maxn];
int n, m;
int depth, strongcnt;
int belong[maxn], strongsize[maxn];
int stk[maxn], top;
int inde[maxn], outde[maxn];

void clear(){
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(instack, 0, sizeof(instack));
  memset(belong, 0, sizeof(belong));
  memset(strongsize, 0, sizeof(strongsize));
  memset(inde, 0, sizeof(inde));
  memset(outde, 0, sizeof(outde));
  depth = 0;
  strongcnt = 0;
  for (int i = 1; i <= n; ++i)
  { 
    v[i].clear();
  }
}

void tarjan(int u){
  dfn[u] = low[u] = ++depth;
  instack[u] = true;
  stk[++top] = u;
  int to;
  for (int i = 0; i < v[u].size(); ++i)
  {
    to = v[u][i];
    if(!dfn[to]){
      tarjan(to);
      low[u] = min(low[to], low[u]);
    }else if (instack[to])
    {
      //dfn[i] not low[i];
      low[u] = min(low[u], dfn[to]);
    }

  }
  if (dfn[u] == low[u])
  {
    strongcnt++;
    do
    {
      to = stk[top--];
      instack[to] = false;
      belong[to] = strongcnt;
      strongsize[strongcnt]++;
    } while (to != u);
  }
}
int main()
{
  for (int i = 1; i <= n; ++i)
  {
    if (!dfn[i])
    {
      tarjan(i);
    }
  }
  int to;
  for(int i = 1; i <= n; i++)
  {
    for (int j = 0; j < v[i].size(); ++j)
    {
      to = v[i][j];
      if(belong[i] != belong[to]){
        outde[belong[i]]++;
        inde[belong[to]]++;
      }
    }
  }
  return 0;
}
