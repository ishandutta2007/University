#include <bits/stdc++.h>

using namespace  std;

int xx[1020], yy[1020];




int main()
{
	int T;
	cin >> T;
	
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		
		for (int i = 0; i < N; i++)
		{
			cin >> xx[i] >> yy[i];
		}
		
		int ans = 1;
		
		for (int s = 0; s < N; s++)
			for (int e = 0; e < N; e++) if(s != e)
			{
				int s1p1x = xx[s], s1p1y = yy[s];
				int s1p2x = xx[(s+1)%N], s1p2y = yy[(s+1)%N];
				int s2p1x = xx[e], s2p1y = yy[e];
				int s2p2x = xx[(e+1)%N], s2p2y = yy[(e+1)%N];

				bool ver1 = (s1p1x - s1p2x == 0);
				bool ver2 = (s2p1x - s2p2x == 0);

				if(ver1 != ver2) continue;




				if(ver1) {
					len1 = s1p2y - s1p1y;
					len2 = s2p2y - s2p1y;
					if(len1 * len2 > 0) continue;

					if(s1p1y -)

				} else {

				}

			}
		
		
	}
	
	
	
	return 0;
}