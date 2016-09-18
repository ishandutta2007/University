#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL l, r;

int main()
{
	while (scanf("%I64d%I64d",&l, &r)!=EOF) {
		LL ans=0;
		if (l==0) {
			if (r>1) {
				ans++;
				if (r>2)
					ans+=(r-l-1)/2;
			}
		}
		else {
			if (r>1) {
				ans++;
				if (l<2*r-3) {
					ans++;
					if (r>l+3)
						ans+=(r-l-2)/2;
				}
			}
		}
		printf("%I64d\n",ans);
	}

	return 0;
}
