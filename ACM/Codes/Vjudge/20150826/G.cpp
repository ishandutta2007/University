#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define __maxn 200020
#define EPS 1e-10
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;

int a[__maxn], cp[__maxn];

struct SegTree{


    int segmax[__maxn<<2];
    void clear(){
        memset(segmax, 0, sizeof(segmax));
    }
    void pushup(int rt){
        segmax[rt] = max(segmax[rt<<1], segmax[rt<<1|1]);
    }
    void update(int pos, int c, int l, int r, int rt)
    {
	    if(l == r){
	//        printf("l:%d r:%d add:%d\n", l, r, c);
	        segmax[rt] = max(segmax[rt] , c);
	        return;
	    }
	    int m = (l + r) >> 1;
	    if(pos <= m) update(pos, c, lson);
	    else update(pos, c, rson);
	    pushup(rt);
	}
    int querymax(int L, int R, int l, int r, int rt){

        if(L <= l && R >= r) {
            return segmax[rt];
        }

        int m = (l+r)>>1;
        int tmp = -0x7f7f7f7f;
        if(L <= m) tmp = max(querymax(L, R, lson),tmp);
        if(R > m) tmp = max(querymax(L, R, rson),tmp);
        return tmp;
    }
}segtree;



int n, d;



int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	while(scanf("%d%d", &n, &d) == 2)
	{
		segtree.clear();
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			cp[i] = a[i];
		}

		sort(a + 1, a + n + 1);
		int tmp = 0;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			tmp = 0;
			int pos = lower_bound(a + 1, a + n + 1, cp[i]) - a;
			int l = lower_bound(a + 1, a + n + 1, cp[i] - d) - a;
			int r = lower_bound(a + 1, a + n + 1, cp[i] + d) - a;
			if(r > n || a[r] != cp[i] + d) r--;

			// printf("%d %d %d\n", l, pos, r);

			tmp = segtree.querymax(l, r, 1, n, 1) + 1;
			// printf("i:%d %d\n", i, dp[i]);
			ans = max(ans, tmp);
			segtree.update(pos, tmp, 1, n, 1);
		}
		printf("%d\n", ans);
	}


	return 0;
}