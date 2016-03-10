#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

char ss[10][10];


vector<int> CK[20], MK[20];
map<string , int> mp;
int n, m;
bool fb;


void resetkilled(int id)
{
	CK[id].clear();
}

void addkiller(int id, int t)
{
	CK[id].push_back(t);
	int len = CK[id].size();
	if(len == 3) cout << t << ' ' <<  "Killing spree!" << endl;
	if(len == 4) cout << t << ' ' <<  "Dominating!" << endl;
	if(len == 5) cout << t << ' ' <<  "Mega kill!" << endl;
	if(len == 6) cout << t << ' ' <<  "Unstoppable!" << endl;
	if(len == 7) cout << t << ' ' <<  "Wicked sick!" << endl;
	if(len == 8) cout << t << ' ' <<  "Monster kill!" << endl;
	if(len == 9) cout << t << ' ' <<  "God like!" << endl;
	if(len >= 10) cout << t << ' ' <<  "Holy shit!" << endl;
	
	
	MK[id].push_back(t);
	len = MK[id].size();
	int tmp = 1;
	int now = len - 1;
	while(MK[id][now] - MK[id][now-1] <= 12 && now - 1 >= 0)
	{
		tmp++;
		now--;
	}
	if(tmp == 2) cout << t << ' ' <<  "Double kill!" << endl;
	if(tmp == 3) cout << t << ' ' <<  "Triple kill!" << endl;
	if(tmp == 4) cout << t << ' ' <<  "Ultra kill!" << endl;
	if(tmp >= 5) cout << t << ' ' <<  "Rampage!" << endl;
	
}



int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		fb = false;
		for(int i = 0; i < 20; i++)
		{
			CK[i].clear();
			MK[i].clear();
		}
		mp.clear();
		cin >> n >> m;
		
		for(int t = 0; t < 2; t++)
		{
			for(int i = 0; i < n; i++)
			{
				string tmp;
				cin >> tmp;
				mp[tmp] = t*n + i;
			}
		}
		
		
		int t;
		string killer, killed;
		int killerid, killedid;
		for(int i = 0; i < m; i++)
		{
			cin >> t >> killer >> killed;
			killerid = mp[killer];
			killedid = mp[killed];
			
			if(killerid / n == killedid / n)
				continue;
			
			if(fb == false)
			{
				fb = true;
				cout << t << ' ' << "First blood!" << endl;
			}
			resetkilled(killedid);
			addkiller(killerid, t);
		}
		
		cout << endl;
		
	}
	
	return 0;
}