#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;


const int maxm = 362880;
const int mod = 1e9;

int ans[4];

int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
int flag[5][maxm+100];
int tp[10] = {0, 3, 1, 3, 2, 3, 1, 3, 0, 4};
int ids[10];
int line[10][10], cow[10][10];


int cantor(int* a,int len)
{
	int ret = 0;
	for(int i = 0; i < len; i++)
	{
		int tmp = 0;
		for(int j = i+1; j < len; j++)if(a[i] > a[j]) tmp++;
		ret += tmp * fact[len-i-1];
	}
	return ret;
}
void cantorrev(int* a,int d, int len)
{
	int vis[10] = {0}, tmp, tt;
	for(int i = 0; i < len; i++)
	{
		tmp = d / fact[len-i-1];
		d %= fact[len-i-1];
		//the min
		tt = 1;
		while(tmp || vis[tt])
		{
			if(vis[tt] == 0)
				tmp--;
			tt++;
		}
		vis[tt] = 1;
		a[i] = tt;
	}
}


void output()
{
	for(int i = 0; i < 9; i++)
	{
		printf("%d ", ids[i]);
	}
	printf("\n");
}



void addans()
{

	output();

	ans[0]++;
	for(int i = 0; i < 3; i++)
	{
		if(ans[i] >= mod)
		{
			ans[i+1] += 1;
			ans[i] %= mod;
		}
	}
}

bool __check(int d, int depth)
{
	int L = depth / 3, C = depth % 3;
	int a[10] = {0};
	cantorrev(a, d, 9);
	for(int i = 0; i < 9; i++)
	{
		int l = i / 3, c = i % 3;
		if(line[L + l][a[i]] == 1) return false;
		if(cow[C + c][a[i]] == 1) return false;
	}
	return true;
}

void add(int d, int depth)
{
	int L = depth / 3, C = depth % 3;
	int a[10] = {0};
	cantorrev(a, d, 9);
	for(int i = 0; i < 9; i++)
	{
		int l = i / 3, c = i % 3;
		line[L + l][a[i]] = 1;
		cow[C + c][a[i]] = 1;
	}
}
void sub(int d, int depth)
{
	int L = depth / 3, C = depth % 3;
	int a[10] = {0};
	cantorrev(a, d, 9);
	for(int i = 0; i < 9; i++)
	{
		int l = i / 3, c = i % 3;
		line[L + l][a[i]] = 0;
		cow[C + c][a[i]] = 0;
	}
}

void dfs(int depth)
{
	// if(depth > 3)
	// cout << depth << endl;
	if(depth == 10)
	{
		addans();
		return;
	}

	for(int i = 0; i < maxm; i++)if(flag[tp[depth]][i] != 1)
	{
		if(__check(i, depth))
		{
			add(i, depth);
			ids[depth] = i;
			dfs(depth + 1);
			sub(i, depth);
		}
	}
}

void prepro()
{
	int a[10] = {0};
	for(int i = 0; i < maxm; i++)
	{
		cantorrev(a, i, 9);
		if(a[0] == 1 || a[4] == 1 || a[8] == 1)
			flag[0][i] = 1;
		if(a[2] == 1 || a[4] == 1 || a[6] == 1)
			flag[1][i] = 1;
		if(flag[0][i] || flag[1][i]) flag [2][i] = 1;
	}
}




int main()
{

	// freopen("out.txt", "w", stdout);

	memset(ans, 0, sizeof(ans));
	memset(ids, 0, sizeof(ids));
	memset(line, 0, sizeof(line));
	memset(cow, 0, sizeof(cow));
	prepro();
	dfs(0);


	for(int i = 0; i < 4; i++)
		printf("%d\n", ans[i]);


	return 0;
}