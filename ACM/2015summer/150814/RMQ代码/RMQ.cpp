#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

#define dprint(expr) fprintf(stderr, #expr " = %d\n", expr)
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int N = 1e5 + 7;
const int D = 20;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

int f[N][D], g[N][D], num[N];

inline int bit(int x) {
	int len = 0;
	while (x) {
		++len;
		x >>= 1;
	}
	return len;
}

int main(void){
	int n, Q;
//	for (int i = 1; i <= 10; ++i)
//		cout << i << " = " << bit(i) << endl;
	while (scanf("%d%d", &n, &Q) == 2) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &num[i]);
			f[i][0] = g[i][0] = num[i];
		}
		for (int j = 1; j < D; ++j) {
			for (int i = 1; i <= n - (1 << (j - 1)); ++i) {
				f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
				g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
			}
		}
		while (Q--) {
			int u, v;
			scanf("%d%d", &u, &v);
//			printf("In : %d %d\n", u, v);
			int k = bit(v - u + 1) - 1;
//			printf("Get %d %d\n", v - (1 << k) + 1, k);
			printf("%d\n", max(g[u][k], g[v - (1 << k) + 1][k]) -
							 min(f[u][k], f[v - (1 << k) + 1][k]));
		}
	}
	return 0;
}
