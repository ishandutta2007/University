#include <bits/stdc++.h>
using namespace std;

int n, k, q;
int t[150002];
set<int, greater<int> > st;

int main()
{
	scanf("%d%d%d", &n, &k, &q);

	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);

	st.clear();
	int cmd, id;
	while(q--)
	{
		scanf("%d%d", &cmd, &id);
		if(cmd == 1) {
			st.insert(t[id]);
		}
		else
		{
			if(st.find(t[id]) == st.end())
			{
				cout << "NO" << endl;
			}
			else
			{
				int i = 1;
				for (int x : st)
				{
					if(i > k)
					{
						cout << "NO" << endl;
						break;
					}
					if(x == t[id])
					{
						cout << "YES" << endl;
						break;
					}
					i++;
				}
			}
		}
	}
	return 0;
}