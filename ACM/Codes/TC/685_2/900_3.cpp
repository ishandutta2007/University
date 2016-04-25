#include <bits/stdc++.h>
using namespace std;



class RGBTree
{
public:
	int dp[1<<13][5][5][5];
	string exist(vector <string> G)
	{
		memset(dp, -1, sizeof(dp));
		
		dp[1][0][0][0] = 1;


		int N = G.size();
		int m = (N-1)/3;


		for (int k = 1; k <= N; k++)
		{
			int mask = (1 << k) - 1;
			while (!(mask & 1 << k))
			{
				if(mask >= (1<<k)) break;
				for (int r = 0; r <= m; r++)
					for (int g = 0; g <= m; g++)
						for (int b = 0; b <= m; b++)if(dp[mask][r][g][b] = 1)
						{
							for (int i = 0; i < N; i++) if (mask & (1<<i))
							{
								for (int j = 0; j < N; j++) if(!(mask & (1<<j)) && (G[i][j] != '.'))
								{
									int tr = r, tg = g, tb = b;
									if(G[i][j] == 'R') tr++;
									else if(G[i][j] == 'G') tg++;
									else tb++;
									if(tr == m && tg == m && tb == m)
										return "Exist";
									if(tr <= m && tg <= m && tb <= m)
										dp[mask|(1<<j)][tr][tg][tb] = 1;
								}

							}


						}
			    int lo = mask & ~(mask - 1);       // lowest one bit
			    int lz = (mask + lo) & ~mask;      // lowest zero bit above lo
			    mask |= lz;                     // add lz to the set
			    mask &= ~(lz - 1);              // reset bitmask below lz
			    mask |= (lz / lo / 2) - 1;      // put back right number of bitmask at end
			}
		}
		return "Does not exist";
	}
};
