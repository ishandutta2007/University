#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
//#include <map>
#include <queue>
#include <utility>
#include <iomanip>
#include <stack>
#include <list>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
// #include <ctime>
#include <ctype.h>
using namespace std;

void Egcd (int a, int b, int &x, int &y)    //扩展欧几里得【无返回版】求x
{
	if (b == 0)
	{
		x = 1, y = 0;
		return ;
	}
	Egcd (b, a%b, x, y);
	int tp = x;
	x = y;
	y = tp - a/b*y;
}
void EXT_GCD(int a, int b, int &d, int &x, int &y)
//a , b 任意
{
     if(!b) {d = a, x = 1, y = 0;}
     else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}
// int CRT (int n[], int b[], int nn)
// {
// 	int res = 0, x, y, i;
// 	for (i = 0; i < 3; i++)
// 	{
// 		int a = nn / n[i];
// 		Egcd (a, n[i], x, y);    //求x
// 		res += a * x * b[i];    //把所有组成部分加起来【加性】
// 	}        //其中*b[i]是利用了同余的乘性
// 	return res;
// }
int CRT(int *m, int *a, int n)
{
	int M = 1, Mi, x0, y0, d, ret = 0;
	for(int i = 0; i < n; i++)
		M *= m[i];
	for(int i = 0; i < n; i++)
	{
		Mi = M/m[i];
		EXT_GCD(Mi, m[i], d, x0, y0);
		// Egcd(Mi, m[i], x0, y0);
		ret = (ret+Mi*x0*a[i]) % M;
	}
	if(ret < 0)
		ret += M;
	return ret;
}

int main()
{
	int n[5] = {23, 28, 33}, b[5], i, date, k = 1, x0;
	while (1)
	{
		for (i = 0; i < 3; i++)
			scanf ("%d", b+i);
		scanf ("%d", &date);
		if (date == -1)
			break;
		x0 = (CRT (n, b, 3) - date) % 21252; //使解不大于21252
		if (x0 <= 0)
			x0 += 21252;  //负数或0特殊考虑
		printf ("Case %d: the next triple peak occurs in %d days.\n", k++, x0);
	}
	return 0;
}
