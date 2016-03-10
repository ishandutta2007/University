#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;

int a[50][50], b[50][50], c[50][50];
int n, m, p;


int main()
{
	int T;
	
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> p;
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		
		for(int i = 0; i < m; i++)
			for(int j = 0; j < p; j++)
				cin >> b[i][j];
		
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < p; j++)
			{
				c[i][j] = 0;
				for(int k = 0; k < m; k++)
					c[i][j] += a[i][k] * b[k][j];
			}
		
		
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < p; j++)
				printf("%d ", c[i][j]);
		
		printf("\n");
		
		
	}	
	return 0;
}