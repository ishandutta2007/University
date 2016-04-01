#include <cstdio>
#include <algorithm>

using namespace std;

struct Time
{
	int sh, sm, eh, em;
}t[120];

bool cmp(Time a, Time b)
{
	if(a.eh == b.eh) return a.em < b.em;
	return a.eh < b.eh;
}

bool cmp2(Time a, Time b)
{
	if(a.eh == b.sh) return a.em <= b.sm;
	return a.eh <= b.sh;
}

int main()
{
	int T;
	scanf("%d", &T);
	int n;
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d:%d-%d:%d", &t[i].sh,&t[i].sm,&t[i].eh,&t[i].em);

		sort(t, t + n, cmp);

		bool isok = 1;

		for (int i = 1; i < n; i++)
		{
			if(!cmp2(t[i-1], t[i])) isok = 0;
		}

		printf("%s\n", isok? "no conflict":"conflict");
	}




	return 0;
}