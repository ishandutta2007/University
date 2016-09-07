#include <bits/stdc++.h>
using namespace std;

int n,m,k;

int main()
{
  freopen("data.out", "w", stdout);


	int Case;
  for (int n = 1; n <= 4; n++)
    for (int m = 1; m <= 4; m++)
      for (int k = 1; k <= 4; k++)
	//scanf("%d",&Case);
	//for (int o=1;o<=Case;o++)
	{
		//scanf("%d%d%d",&n,&m,&k);
		//printf("Case #%d:\n",o);
    printf("(%d, %d, %d) : ", n, m, k);
		if (k<=2 || n<=2)
		{
			if (m!=n) printf("Impossible\n");
			else
			{
				for (int i=1;i<=n;i++) printf("A");
				printf("\n");
			}
		}
		else
		{
			if (m<3||m>n) printf("Impossible\n");
			else
			{
				int tmp=m-3;
				for (int i=1;i<=n-tmp;i++) printf("%c",'A'+i%3);
				for (int i=n-tmp+1;i<=n;i++) printf("%c",'A'+(n-tmp)%3);
				printf("\n");
			}
		}
	}
	return 0;
}
