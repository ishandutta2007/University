#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define maxn 100200
#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
struct SegTree{
    ll segsum[maxn<<2];
    ll lazy[maxn<<2];
    void clear()
    {
        memset(segsum, 0, sizeof(segsum));
        memset(lazy, 0, sizeof(lazy));
    }
    void pushup(int rt)
    {
        segsum[rt] = max(segsum[rt<<1] , segsum[rt<<1|1]);
    }
    void build(int l, int r, int rt)
    {
        if(l == r)
        {
            scanf("%lld",&segsum[rt]);
            return;
        }
        int m = (l+r)>>1;
        build(lson);
        build(rson);
        pushup(rt);
    }
    void pushdown(int rt, int m)
    {
    	lazy[rt << 1] = max(lazy[rt << 1] , lazy[rt]);
    	lazy[rt << 1 | 1] = max(lazy[rt << 1 | 1] , lazy[rt]);
        segsum[rt << 1] = max(segsum[rt<<1], lazy[rt]);
        segsum[rt << 1 | 1] = max(lazy[rt], segtree[rt<<1|1]);
        lazy[rt] = 0;
    }
    void update(int L, int R, int c, int l, int r, int rt)
    {
        if(L <= l && r <= R)
        {
            lazy[rt] = max(lazy[rt], c);
            segsum[rt] = max(segsum[rt], c);
            return;
        }
        if(lazy[rt] != 0)
            pushdown(rt, r - l + 1);
        int m = (l + r) >> 1;
        if(L <= m) update(L, R, c, lson);
        if(R > m) update(L, R, c, rson);
        pushup(rt);
    }
    void check(int l, int r, int rt)
    {

        printf("l=%d r=%d rt=%d sum=%lld\n", l,r,rt,segsum[rt]);
        if(l == r)
        {
            return;
        }
        int m = (l+r)>>1;
        check(lson);
        check(rson);
    }
    ll querysum(int L, int R, int l, int r, int rt){
        if(L <= l && R >= r) 
        {
            return segsum[rt];
        }
        if(lazy[rt] != 0)
            pushdown(rt, r - l + 1);
        int m = (l+r)>>1;
        ll tmp = 0;
        if(L <= m) tmp = max(tmp, querysum(L, R, lson));
        if(R > m) tmp += max(tmp, querysum(L, R, rson));
        return tmp;
    }
}segtree;



class SettingShield
{
public:

	vector<LL> protection, left, right;



	long long getOptimalCost(int n, int h, int t, vector <int> val0, vector <int> a, vector <int> b, vector <int> m)
	{
		protection.push_back(val0[0]);

		for (int i = 1; i < n; i++)
			protection.push_back(a[0]*protection[i-1] + b[0]) % m[0];

		left.push_back(val0[1]);
		right.push_back(val0[2]);

		for (int i = 1; i <	h; i++)
		{
			left.push_back(min(n-1,(a[1]*left[i-1]+b[1])%m[1]));
			LL dist = right[i-1]-left[i-1];
			right.push_back(min(n-1,left[i]+(a[2]*dist+b[2])%m[2]));
		}





	}

};
