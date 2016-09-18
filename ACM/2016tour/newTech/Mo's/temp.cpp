#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

struct query {
	int L, R, K, bid, qid;
	bool operator<(const query &other) const;
};

const int max_N = 1e5 + 10;
ll bitA[max_N], bitB[max_N];
ll eqA[max_N], eqB[max_N];
int A[max_N], B[max_N];
query queries[max_N];
ll ans[max_N];
int N;

void update(ll *bit, int p, ll x)
{
	for (; p < max_N; p += (p & -p)) {
		bit[p] += x;
	}
}

ll query(ll *bit, int p)
{
	ll ans = 0;
	for (; p; p -= (p & -p)) {
		ans += bit[p];
	}
	return ans;
}

void add(int idx, int x)
{
	if (A[idx] < max_N) {
		int y = A[idx];
		update(bitA, y, x);
		eqA[y] += x;
	}
	if (B[idx] < max_N) {
		int y = B[idx];
		update(bitB, y, x);
		eqB[y] += x;
	}
}

void update_mo(int &currL, int &currR, int x, int y)
{
	if (currL == currR && currL == 0) {
		for (int i = x; i <= y; ++i) {
			add(i, 1);
		}
		currL = x;
		currR = y;
	}
	while(currR < y) {
		++currR;
		add(currR, 1);
	}
	while(currL > x) {
		--currL;
		add(currL, 1);
	}
	while(currR > y) {
		add(currR, -1);
		--currR;
	}
	while(currL < x) {
		add(currL, -1);
		++currL;
	}
}

bool query::operator<(const query &other) const
{
	if (bid == other.bid) {
		return (R < other.R);
	} else {
		return (bid < other.bid);
	}
}
int main()
{
	int Q;
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", A + i);
	}
	for (int i = 1; i <= N; ++i) {
		scanf("%d", B + i);
	}
	int R = sqrt(N);
	for (int i = 0; i < Q; ++i) {
		scanf("%d%d%d", &queries[i].L, &queries[i].R, &queries[i].K);
		queries[i].bid = queries[i].L / R;
		queries[i].qid = i;
	}
	sort(queries, queries + Q);
	int currL = 0, currR = 0;
	for (int i = 0; i < Q; ++i) {
		struct query temp = queries[i];
		ll ans = 0;
		update_mo(currL, currR, temp.L, temp.R);
		int rootK = sqrt(temp.K);
		ans += query(bitA, rootK) * query(bitB, rootK);
		for (int j = 1; j <= rootK; ++j) {
			ans += eqA[j] * (query(bitB, temp.K / j) - query(bitB, rootK));
			ans += eqB[j] * (query(bitA, temp.K / j) - query(bitA, rootK));
		}
		::ans[temp.qid] = ans;
	}
	for (int i = 0; i < Q; ++i) {
		printf("%lld\n", ans[i]);
	}
}

