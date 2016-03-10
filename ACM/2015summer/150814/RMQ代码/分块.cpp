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
const int D = 400;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

int L[N], R[N], a[N];

int main(void){
	int n, m, Q;
	while (scanf("%d%d", &n, &Q) == 2) {
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		for (int i = 1; i <= n; i += D) {
			int T = (i - 1) / D + 1;
			L[T] = 0;
			R[T] = INF;
			for (int j = i; j < (i + D) && j <= n; ++j) {
				L[T] = max(L[T], a[j]);
				R[T] = min(R[T], a[j]);
			}
		}
		while (Q--) {
			int u, v;
			scanf("%d%d", &u, &v);
			int _Min = INF, _Max = 0;
			int A = (u - 1) / D + 1;
			int B = (v - 1) / D + 1;
			for (int i = A + 1; i < B; ++i) {
				_Min = min(_Min, R[i]);
				_Max = max(_Max, L[i]);
			}
			if (A < B) {
				for (int i = u; i <= A * D; ++i) {
					_Min = min(_Min, a[i]);
					_Max = max(_Max, a[i]);
				}
				for (int i = (B - 1) * D + 1; i <= v; ++i) {
					_Min = min(_Min, a[i]);
					_Max = max(_Max, a[i]);
				}
			} else
				for (int i = u; i <= v; ++i) {
					_Min = min(_Min, a[i]);
					_Max = max(_Max, a[i]);
				}
			printf("%d\n", _Max - _Min);
		}
	}
	return 0;
}
