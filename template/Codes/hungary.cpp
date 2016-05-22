#include "string.h"
#include "queue"
#include "iostream"
#include "algorithm"
#include "stdio.h"
#include <cmath>
#define __maxNodes 4020
using namespace std;
struct Edge
{
  int from,to,weight;
  Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};
vector<Edge> G[__maxNodes]; /* G[i] 存储顶点 i 出发的边的编号 */
int matching[__maxNodes]; /* 存储求解结果 */
int check[__maxNodes];
int n, m, sum;
/*DFS*/
bool dfs(int u)
{
  for (int i = 0; i < G[u].size(); i++) { 
    int v = G[u][i].to;
    if (!check[v]) {     // 要求不在交替路中
      check[v] = true; // 放入交替路
      if (matching[v] == -1 || dfs(matching[v])) {
        // 如果是未盖点，说明交替路为增广路，则交换路径，并返回成功
        matching[v] = u;
        matching[u] = v;
        return true;
      }
    }
  }
  return false; // 不存在增广路，返回失败
}
int hungarian()
{
  int ans = 0;
  memset(matching, -1, sizeof(matching));
  for (int u=1; u <= n; ++u) {
    if (matching[u] == -1) {
      memset(check, 0, sizeof(check));
      if (dfs(u))
        ++ans;
    }
  }
  return ans;
}
