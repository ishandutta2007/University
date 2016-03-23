/*
 * 	1.设字符集为字符和数字的集合，字符的顺序为A，
 * 	B，C，…，Z，0，1，2，…，9，请将下列字符串按
 * 	字典顺序排列、存储： PAB ，5C，PABC ，CXY，   
 * 	CRSI,7,B899,B9, 并分析可以采取的存储方案。
 */


/*
 *	可采取的存储方式:
 *	线性表
 *	字符串数组， 二维char数组
 */



#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
char str[200][200];
struct Node
{
	string ss;
	int id;
}nd[200];
bool cmp(Node a, Node b)
{
	return a.ss < b.ss;
}
int main()
{
	int n;
	printf("Input the number of the strings\n");
	scanf("%d", &n);
	printf("Input %d strings\n", n);

	for(int i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
		nd[i].ss.clear();
		nd[i].id = i;
		for(int j = 0, l = strlen(str[i]); j < l; j++)
		{
			if(str[i][j] >= '0' && str[i][j] <= '9')
				nd[i].ss.push_back(str[i][j]-'0'+91);
			else nd[i].ss.push_back(str[i][j]);
		}
	}
	sort(nd, nd + n, cmp);
	printf("After sort\n\n\n");
	for(int i = 0; i < n; i++)
		printf("%s\n", str[nd[i].id]);
	return 0;
}
