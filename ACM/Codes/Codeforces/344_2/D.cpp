#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 200020;
// char src[maxn],substring[maxn];
int nxt[maxn];

int n, m;
int lens, lent;
int len;
pair<long long ,char> PCIs[200020], PCIt[200020], PCItmp[200020];
void get_nxt(pair<long long ,char> substring[200020])
{
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int j = -1;
	for(int i = 1; i < lens; i++)
	{
		while(j > -1 && substring[i] != substring[j + 1])
			j = nxt[j];
		if(substring[j+1] == substring[i])
			j = j + 1;
		nxt[i] = j;
	}
}

//process src & substring to get the position
long long kmp(pair<long long ,char> src[200020], pair<long long ,char> substring[200020])
{
	int j = -1;
	int ans = 0;
	for(int i = 0; i < lent; i++)
	{
		while(j > -1 && src[i] != substring[j + 1])
			j = nxt[j];

		// cout << "prej :" << j << endl;
		// cout << src[i].first << src[i].second << endl;
		// cout << substring[j+1].first << substring[j+1].second << endl;
		if(src[i] == substring[j + 1])
			j++;
		// cout << "aftj :" << j << endl;
		if(j == lens -1)
		{
			if(i + 2 - lens - 2 >= 0 && src[i+2-lens-2].second == PCIs[0].second && i + 1 < lent && src[i+1].second == PCIs[len-1].second
			&& src[i+2-lens-2].first >= PCIs[0].first 
			&& src[i+1].first >= PCIs[len-1].first)
				ans ++;
	        // printf("From position %d to position %d\n", i + 2 - lens, i+1);
			j = nxt[j];
		}
	}
	return ans;
}

int sim(pair<long long ,char> PCI[200020], int l)
{
	int len = 1;
	for (int i = 1; i < l; i++) {
		if(PCI[i].second == PCI[len-1].second) {
			PCI[len-1].first += PCI[i].first;
		} else {
			PCI[len++] = PCI[i];
		}
	}
	return len;
}


int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%I64d-%c", &PCIt[i].first, &PCIt[i].second);
	for (int i = 0; i < m; i++)
		scanf("%I64d-%c", &PCIs[i].first, &PCIs[i].second);

	lens = sim(PCIs, m);
	lent = sim(PCIt, n);

	long long ans;

	// for(int i = 0; i < lent; i++)
	// 	printf("%I64d-%c\n", PCIt[i].first, PCIt[i].second);

	// cout << "==========" << endl;
	// for(int i = 0; i < lens; i++)
	// 	printf("%I64d-%c\n", PCIs[i].first, PCIs[i].second);
	if(lens == 1) {
		ans = 0;		
		for(int i = 0; i < lent; i++) if(PCIt[i].second == PCIs[0].second && PCIt[i].first >= PCIs[0].first)
			ans += PCIt[i].first - PCIs[0].first + 1;
	} else if (lens == 2) {
		ans = 0;
		for(int i = 0; i < lent - 1; i++)
			if(PCIt[i].second == PCIs[0].second && PCIt[i+1].second == PCIs[1].second
				&& PCIt[i].first >= PCIs[0].first && PCIt[i+1].first >= PCIs[1].first)
				ans ++;
	} else {
		for(int i = 1; i < lens-1; i++)
			PCItmp[i-1] = PCIs[i];

		len = lens;
		lens -= 2;
		// cout << "==========" << endl;
		// for(int i = 0; i < lens; i++)
		// 	printf("%I64d-%c\n", PCItmp[i].first, PCItmp[i].second);

		get_nxt(PCItmp);

		// for(int i = 0; i < lens; i++)
		// 	printf("%d ", nxt[i]);
		// cout << endl;

		ans = kmp(PCIt, PCItmp);
	}

	cout << ans << endl;
	return 0;
}


// 5 3
// 1-a 1-b 1-a 1-b 1-a
// 1-a 1-b 1-a