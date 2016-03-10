#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>



using namespace std;

typedef long long LL;

void EXT_GCD(LL a, LL b, LL &d, LL &x, LL &y)
//a , b 任意
{
     if(!b) {d = a, x = 1, y = 0;}
     else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}
int main()
{

	LL a, b, c;
	LL x, y, d;


	while(scanf("%I64d%I64d%I64d", &a, &b, &c) != EOF)
	{
		if(a == 0 && b == 0 && c == 0) break;
		EXT_GCD(a, b, d, x, y);


		x = x * c / d;
		y = y * c / d;

		

	}


	

	return 0;
}