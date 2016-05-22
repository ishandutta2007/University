#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

map<int, int> xx;
map<int, int> yy;
map< pair<int,int>, int> F;


int n;
LL ans;

int main()
{
	cin >> n;


	int x, y;
	LL cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		pair<int, int> tmpp = ,make_pair(x, y);

		if(F.find(tmpp) == F.end()) F[tmpp] = 0;
		F[tmpp] ++;

		if(xx.find(x) == xx.end()) xx[x] = 0;
		xx[x] ++;
		if(yy.find(y) == yy.end()) yy[y] = 0;
		yy[y] ++;
	}


	for (pair<int, int> tmp : xx) {
		ans += (LL)tmp.second * (tmp.second - 1) / 2;
	}

	for (pair<int, int> tmp : yy) {
		ans += (LL)tmp.second * (tmp.second - 1) / 2;
	}

	for (pair< pair<int,int>, int> tmp : F) if(tmp.second > 1) {
		ans -= (LL)tmp.second * (tmp.second - 1) / 2;
	}
	
	cout << ans - cnt << endl;


	return 0;
}