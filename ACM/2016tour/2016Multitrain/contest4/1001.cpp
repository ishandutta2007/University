#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll oo = 1e9 + 7;
const int maxn = 200020;
char src[maxn],substring[maxn];
int nxt[maxn], dp[maxn][2];
vector<pii> seg;
vector<int> rp;

void get_nxt(char* substring)
{
	int substring_len = strlen(substring);
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int j = -1;
	for(int i = 1; i < substring_len; i++)
	{
		while(j > -1 && substring[i] != substring[j + 1])
			j = nxt[j];
		if(substring[j+1] == substring[i])
			j = j + 1;
		nxt[i] = j;
	}
}

//process src & substring to get the position
int kmp(char* src, char* substring)
{
	int j = -1;
	int ans = 0;
	int substring_len = strlen(substring);
	int src_len = strlen(src);
	for(int i = 0; i < src_len; i++)
	{
		while(j > -1 && src[i] != substring[j + 1])
			j = nxt[j];
		if(src[i] == substring[j + 1])
			j++;
		if(j == substring_len -1)
		{
			ans ++;
//	        printf("From position %d to position %d\n", i + 2 - substring_len, i+1);
			j = nxt[j];
      rp.push_back(i+1);
      seg.push_back(pii(i+2-substring_len, i+1));
		}
	}
	return ans;
}


int solve()
{
  memset(dp, 0, sizeof(dp));
  int n = rp.size();
  int sublen = strlen(substring);
  if (n == 0) return 1;
/*
  printf("len = %d\n", sublen);
  for (int i = 0; i < n; i++)
    printf("%d ", rp[i]);
  printf("\n=============\n");
*/  
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      dp[i][0] = 1;
      dp[i][1] = 1;
    }
    else
    {
      if (rp[i] - sublen < rp[0])
      {
        dp[i][1] = 1;
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % oo;
      }
      else
      {
        int pos = lower_bound(rp.begin(), rp.end(), rp[i] - sublen + 1) - rp.begin();
//        printf("[%d]\n", pos);
        /*if (pos == 0) 
        {
          dp[i][1] = 1;
          dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % oo;
          continue;
        }*/
        pos--;

        dp[i][1] = (dp[pos][1] + dp[pos][0]) % oo;
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % oo;
      }
   }
//    printf("%d %d\n", dp[i][0], dp[i][1]);
  }
  return (dp[n-1][0] + dp[n-1][1]) % oo;
}



int main()
{
//  freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%s%s", src, substring);
    get_nxt(substring);
    seg.clear();
    rp.clear();
    kmp(src, substring);
    printf("Case #%d: %d\n", ka, solve());
  }
  return 0;
}
