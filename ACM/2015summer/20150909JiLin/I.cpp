#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>


using namespace std;


vector<int>pri;
vector<int>ans;
bool npri[1000020];
int d[1020];



void init(int mm)
{
	npri[1] = true;

	for(int i = 2; i <= mm; i++)
	{
		if(!npri[i])
		{
			for(int j = i*2; j <= mm; j+=i)
			{
				npri[j] = true;
			}
		}
	}

	for(int i = 1; i <= 1000; i++)
	{
		d[i] = i * i;
	}

}


int main()
{


	init(1000000);

	int T, n, m;
	cin >> T;

	while(T--)
	{
		cin >> n >> m;

		int ans = 0;
		for(int i = 1; i <= 1000; i++)
			for(int j = i; j <= 1000; j++)
			{
				if(d[i] + d[j] <= m && d[i] + d[j] >= n && npri[d[i]+d[j]] == false)
					ans++;
			}

		cout << ans << endl;
	}



	return 0;
}
