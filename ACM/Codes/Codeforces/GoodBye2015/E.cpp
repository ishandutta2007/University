#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int n;

int T[3];
int a[200020];
int cnt[3];


struct Node
{
	int sum;
	int cnt;
	vector<int> v;
	Node(){v.clear();}
	Node(int sum):sum(sum){v.clear();}
	void calsum()
	{
		sum = 0;
		cnt = 0;
		for(int i = 0, len = v.size(); i < len; i++)
			sum += T[v[i]];
	}
};

vector<Node> VN;


bool cmp(Node a, Node b)
{
	if(a.sum == b.sum)
	{
		return a.v.size() < b.v.size();
	}
	return a.sum < b.sum;
}


bool check(int x)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(VN[j].sum >= a[i])
			{
				VN[j].cnt++;
				break;
			}
		}
	}
	
	cnt[0] = cnt[1] = cnt[2] = x;
	int tmp[3];
		
	
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			tmp[j] = cnt[j];
		}
		
		Node node = VN[i];
		
		
		
		
	}
	
	
	
}



int main()
{
	
	scanf("%d", &n);
	scanf("%d%d%d", T[0], T[1], T[2]);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	sort(T, T + 3);
	sort(a, a + n);
	
	
	for(int i = 0; i < 3; i++)
	{
		Node tmp = Node();
		tmp.v.push_back(i);
		tmp.calsum();
		VN.push_back(tmp);
	}
	
	for(int i = 0; i < 3; i++)
	{
		Node tmp = Node();
		for(int j = 0; j < 3; j++)
		{
			if(j != i)
			{
				tmp.v.push_back(j);
			}
		}
		tmp.calsum();
		VN.push_back(tmp);
	}
	Node tmp = Node();
	for(int i = 0; i < 3; i++)
	{
		tmp.v.push_back(i);
	}
	tmp.calsum();
	VN.push_back(tmp);
	
	
	sort(VN.begin(), VN.end());
	
	
	
	int low = 0, high = n;
	int mid;
	while(low <= high)
	{
		mid = (low + high) /2;
		
		if(check(mid))
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	
	
	
	
	return 0;
}
