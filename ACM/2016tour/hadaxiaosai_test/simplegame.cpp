#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	int n, w, b;
	while(T--)
	{
		scanf("%d%d%d", &n, &w, &b);

		if(w > b) swap(w, b);
		if((b - w) % 2 == 0) printf("Mike\n");
		else printf("John\n");
	}



	return 0;
}