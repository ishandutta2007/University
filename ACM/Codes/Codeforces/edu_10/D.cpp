#include <bits/stdc++.h>
using namespace std;
const int maxn = 400020;
typedef long long ll;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1


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
        segsum[rt] = segsum[rt<<1] + segsum[rt<<1|1];
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
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        segsum[rt << 1] += lazy[rt] * (m - (m >> 1));
        segsum[rt << 1 | 1] += lazy[rt] * (m >> 1);
        lazy[rt] = 0;
    }
    void update(int L, int R, int c, int l, int r, int rt)
    {
        if(L <= l && r <= R)
        {
            lazy[rt] += c;
            segsum[rt] += (r - l + 1) * c;
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
        if(L <= m) tmp += querysum(L, R, lson);
        if(R > m) tmp += querysum(L, R, rson);
        return tmp;
    }
}segtree;


struct Seg
{
	int l, r,id;
	bool operator < (const Seg& a) const
	{
		return r < a.r;		
	}
}seg[200020];

int n;
int Hash[400020];
int ans[200020];


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &seg[i].l, &seg[i].r);
		seg[i].id = i;
		Hash[i*2 + 1] = seg[i].l;
		Hash[i*2 + 2] = seg[i].r;
	}

	sort(Hash + 1, Hash + 2*n + 1);
	// sort(Hash + 1, Hash + 2*n + 1);
	sort(seg, seg + n);

	segtree.clear();

	for (int i = 0; i < n; i++)
	{
		int l = lower_bound(Hash+1, Hash + 2*n+1, seg[i].l) - Hash;
		int r = lower_bound(Hash+1, Hash + 2*n+1, seg[i].r) - Hash;

		// cout << l << "   " << r << endl;

		ans[seg[i].id] += segtree.querysum(l, r, 1, n*2, 1);
		segtree.update(l,l,1,1,n*2,1);
		// cout << "hello" << endl;
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);

	return 0;
}