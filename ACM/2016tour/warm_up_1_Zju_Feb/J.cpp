#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int data[5];
long long c[10020], f[10020];


deque<string> deq;

map<string , int> mp;


long long ans;
long long MOD = 1000000007;

string tostring()
{
	// for(int i = 0; i < 5; i++)
	// 	cout << data[i] ;
	// cout << endl;
	string ret;
	for(int i = 4; i >= 0; i--)
		for(int j = 0; j < 5; j++)
		{
			string tmp;
			tmp.push_back(data[i] % 10 + '0');
			ret = tmp + ret;
			data[i] /= 10;
		}
	// cout << ret << " ret " << endl;

	return ret;
}

void todata(string str)
{
	// cout << str << " str " << endl;

	memset(data, 0, sizeof(data));
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
		{
			data[i] = data[i]*10 + (str[i*5+j]-'0');
		}

}

void updata_ans()
{

	long long tmp = c[n];

	// for(int i = 0; i < 5; i++)
	// 	cout << data[i] << " ";
	// cout << endl;

	for(int i = 0; i < 5; i++)
		tmp = (tmp * f[data[i]]) % MOD;

	ans = (ans + tmp) % MOD;
}



void solve()
{
	ans = 0;
	string tmp, now;
	mp.clear();
	deq.clear();
	tmp = tostring();
	deq.push_back(tmp);
	mp[tmp] = 1;
	while(!deq.empty())
	{
		now = deq.front();
		deq.pop_front();
		todata(now);
		// cout << now << endl;
		updata_ans();

		int sdata[5];
		for(int i = 0; i < 5; i++)
			sdata[i] = data[i];

		for(int i = 0; i < 4; i++)
			for(int j = 1; j < 5; j++)
			{

				for(int k = 0; k < 5; k++)
					data[k] = sdata[k];


				if((data[i] >= 2 && data[j] >= 1 && i != j) || (data[i] >= 3 && i == j))
				{
					data[i] -= 2;
					data[i+1] += 1;
					data[j] -= 1;
					data[j-1] +=2;

					tmp = tostring();
					if(mp.find(tmp) == mp.end())
					{
						// cout << "tmp" << tmp << endl;
						mp[tmp] = 1;
						deq.push_back(tmp);
					}
				}
			}
	}
	cout << ans << endl;

}

long long inv(long long x, long long m)    
{    
    if (x == 1) return x;    
    return inv(m % x, m)*(m - m / x) % m;    
}    
  
void init()  
{  
    c[0]=f[0]=1;  
    for (int i=1;i<10002;i++)   
    {  
        c[i] = c[i-1] * i%MOD;  
        f[i] = inv(c[i], MOD);  
    }  
}  


int main()
{
	init();
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &m, &k, &n);
		int a[10] = {0};
		a[0] = 16*m - 4*k;
		int tmp = a[0];
		int pos = 0;
		// for(int i = 0; i < 5; i++)
		// 	cout << a[i] << endl;
		while(tmp > n && pos < 5)
		{
			a[pos] -= 2;
			a[pos+1] += 1;
			if(a[pos] < 2) pos++;
			tmp--;
		}
		if(a[0] + a[1] + a[2] + a[3] + a[4] == n) {
			for(int i = 0; i < 5; i++)
				data[i] = a[i];
			solve();
		}
		else cout << 0 << endl;

	}

	return 0;
}