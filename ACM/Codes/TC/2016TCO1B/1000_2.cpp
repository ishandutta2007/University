#include <bits/stdc++.h>
#define PUB push_back
#define POB pop_back
#define FI first
#define SE second

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

class SettingShield
{
public:
	LL getOptimalCost(int n, int h, int t, vector <int> val0, vector <int> a, vector <int> b, vector <int> m);
};
vector<LL> prot, Left, Right;
vector<PII> vp;
int h, n, t;
int down[100020];
bool cmp(PII a, PII b)
{
	if(a.FI == b.FI) return a.SE < b.SE;
	return a.FI < b.FI;
}
LL calc(int hh)
{
	LL ret = (LL)t * hh;
	memset(down, 0, sizeof(down));
	int now = hh;
	for (int i = 0, j = 0, R = vp[0].SE; i < n; i++)
	{
		now -= down[i];
		if(now < prot[i])
		{
			while(j < h && vp[j].FI <= i) R = vp[j++].SE;
			down[R+1] += prot[i] - now;
			ret += prot[i] - now;
			now = prot[i];
		}
	}
	return ret;
}
LL SettingShield::getOptimalCost(int tn, int th, int tt, vector <int> val0, vector <int> a, vector <int> b, vector <int> m)
{
	h = th, n = tn, t = tt;
	prot.PUB(val0[0]);
	for (int i = 1; i < n; i++) prot.PUB(((LL)a[0] * prot[i-1] + b[0]) % m[0]);
	Left.PUB(val0[1]);
	Right.PUB(val0[2]);
	for (int i = 1; i < h; i++)
	{
		Left.PUB(min(n-1LL, ((LL)a[1] * Left[i-1] + b[1]) % m[1]));
		LL dist = Right[i-1] - Left[i-1];
		Right.PUB(min(n-1LL, Left[i] + (a[2]*dist + b[2]) % m[2]));
	}
	vp.clear();
	for (int i = 0; i < h; i++)
		vp.PUB(PII(Left[i], Right[i]));

	sort(vp.begin(), vp.end(), cmp);
	{
		vector<PII> tmp;
		tmp.PUB(vp[0]);
		for (int i = 1, R = vp[0].SE; i < h; i++)
		{
			if(vp[i].SE > R)
			{
				R = vp[i].SE;
				tmp.PUB(vp[i]);
			}
		}
		vp = tmp;
		h = vp.size();
	}
	int L = 0, R = prot[0];
	for (int i = 0,j=0; i < n; i++)
	{
		R=max(R,int(prot[i]));
		while(j<h && vp[j].second<i) ++j;
		if(j==h || vp[j].first>i) L = max(L, int(prot[i]));
	}
	while(R-L > 2)
	{
		int s1 = (2 * L + R) / 3;
		int s2 = (L + 2 * R) / 3;
		LL h1 = calc(s1);
		LL h2 = calc(s2);
		if(h1 < h2) R = s2; else L = s1;
	}
	LL ans = 1e18;
	for (int i = L; i <= R; i++)
		ans = min(ans, calc(i));
	return ans;
}
