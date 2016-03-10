#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

typedef long long LL;

const int N = 1e4 + 7, INF = 0x7fffffff, MOD = 1e9 + 7;

using namespace std;

vector <int> e[N], edge[N];

map <pair<int, int>, bool> dict;

queue <int> Q;

int dfn[N], low[N], stack[N], fa[N], g[N], in[N], out[N], popular[N], top, times, cnt;

bool used[N], ins[N];

void tarjin(int x) {
	used[x] = ins[x] = true;
	dfn[x] = low[x] = ++times;
	stack[++top] = x;
	for (int i = 0; i < e[x].size(); i++) {
		if (!used[e[x][i]]) {
			tarjin(e[x][i]);
			low[x] = min(low[x], low[e[x][i]]);
		} else
		if (ins[e[x][i]]) {
			low[x] = min(low[x], dfn[e[x][i]]);
		}
	}
	if (low[x] == dfn[x]) {
		++cnt;
		//printf("Graph #%d:\n", cnt);
		int tot = 0, u;
		do {
			u = stack[top--];
			//printf("This is %d\n", u);
			fa[u] = cnt;
			ins[u] = false;
			++tot;
		} while (u != x);
		g[cnt] = tot;
	}
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			edge[i].clear();
		}
		int u, v;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
		}
		
		memset(fa, 0, sizeof(fa));
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(used, 0, sizeof(used));
		memset(popular, 0, sizeof(popular));
		top = times = cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (!used[i]) {
				tarjin(i);
			}
		}
		//cout << cnt << endl;
		
		dict.clear();
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < e[i].size(); ++j)
				if (fa[i] != fa[e[i][j]] && dict.find(make_pair(fa[i], fa[e[i][j]])) == dict.end()) {
					edge[fa[i]].push_back(fa[e[i][j]]);
					dict[make_pair(fa[i], fa[e[i][j]])] = true;
					//printf("Add edge %d - > %d\n", fa[i], fa[e[i][j]]);
					++in[fa[e[i][j]]];
					++out[fa[i]];
				}
		}
		while (!Q.empty()) {
			Q.pop();
		}
		for (int i = 1; i <= cnt; ++i) {
			popular[i] = 1;
			if (in[i] == 0) {
				Q.push(i);
			}
		}
		
		while (!Q.empty()) {
			int u = Q.front();
			//printf("Popular %d of %d\n", popular[u], u);
			Q.pop();
			for (int i = 0; i < edge[u].size(); ++i) {
				v = edge[u][i];
				--in[v];
				popular[v] += popular[u];
				if (in[v] == 0) {
					Q.push(v);
				}
			}
		}
		m = 0;
		for (int i = 1; i <= cnt; ++i) {
			if (out[i] == 0) {
				++m;
			}
		}
		if (m > 1) {
			printf("%d\n", 0);
			return 0;
		}
		
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (out[fa[i]] == 0) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}