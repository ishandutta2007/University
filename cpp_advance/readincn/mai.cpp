#include <bits/stdc++.h>
using namespace std;
string af[10] = {"", "十", "百", "千", "万", "十", "百", "千", "亿", "十"};
string digit[10] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
int pow10(int x)
{
	int ret = 1;
	while(x--) ret *= 10;
	return ret;
}
class ReadInCn
{
public:
	int data;
	void setdata(int d)
	{
		data = d;
	}
	string read()
	{
		string ret = "";
		int fisrt = true;
		int cp = data;
		int pzero = 0, pre = 20;
		for (int i = 9; i >= 0; i--)
		{
			int m = pow10(i);
			int dig = cp / m;
			cp -= dig * m;
			if(dig) {
				pre = i;
				if(fisrt == 1) {
					fisrt = 0;
					if(dig == 1) {
						if(i != 1 && i != 5 && i != 9)
							ret += digit[dig];
					} else ret += digit[dig];
					ret += af[i];
				} else {
					if(pzero == 1) ret += digit[0];
					ret += digit[dig];
					ret += af[i];
				}
				pzero = 0;
			} else {
				pzero = 1;
				if(fisrt == 1 && i == 0) ret += digit[0];
				if(fisrt == 0 && (i == 4 || i == 8) && pre - i < 4) ret += af[i];
			} 
		}
		return ret;
	}
	ReadInCn(){}
	ReadInCn(int data):data(data){}
}rc;

int main()
{
	int n;
	int mod = 1e9;
	while(true)
	{
		// n = rand() % mod;
		// n = n*n*n % mod;
		cin >> n;
		if(!(n >= 0 && n <= 1e9)) continue;
		rc.setdata(n);
		cout << n << endl;
		cout << rc.read() << endl;
		// system("pause");
	}
	return 0;
}