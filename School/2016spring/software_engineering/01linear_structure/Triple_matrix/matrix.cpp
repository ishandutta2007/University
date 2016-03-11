#include <bits/stdc++.h>

using namespace std;

struct Triple
{
	int i, j, data;
	Triple(){}
	Triple(int i, int j, int data):i(i),j(j),data(data){}
	void show() {
		printf("Matrix[%d][%d] = %d\n", i,j,data);
	}
	bool operator < (const Triple& A) const {
		if(i == A.i) return j < A.j;
		return i < A.i;
	}
	Triple swapij()
	{
		return Triple(j, i, data);
	}
};


class Matrix {
public:
	int n, m;	//matrix n * m;
	int cnt;
	int sum[100000], pos[100000];
	Triple matrix[100000];
	void setnm(int n, int m) {
		this->n = n;
		this->m = m;
	}
	void insert(int i, int j, int data) {
		// matrix.push_back(Triple(i, j, data));
		// cnt++;
		matrix[cnt++] = Triple(i, j, data);
	}
	void tsort() {
		sort(matrix, matrix + cnt);
	}
	void adjust() {
		tsort();
	}
	void transpose() {
		for (int i = 0; i < cnt; i++) {
			swap(matrix[i].i, matrix[i].j);
		}
		tsort();
	}
	Matrix qtranspose() {
		memset(sum, 0, sizeof(sum));
		memset(pos, 0, sizeof(pos));
		for (int i = 0; i < cnt; i++)
			sum[matrix[i].j] ++;
		for (int i = 1; i <= m; i++)
			pos[i] = pos[i-1] + sum[i-1];
		Matrix ret = Matrix(m, n, cnt);
		for (int i = 0; i < cnt; i++)
		{
			ret.matrix[pos[matrix[i].j]++] = matrix[i].swapij();
		}
		return ret;
	}
	void show() {
		for (int i = 0; i < cnt; i++) {
			matrix[i].show();
		}
	}
	Matrix(){}
	Matrix(int n, int m, int cnt):n(n), m(m), cnt(cnt){}
}M, N;

int main()
{

	int n, m, c;
	cin >> n >> m >> c;
	M.n = n, M.m = m;
	// cout << M.n << " " << M.m << " " << M.cnt << endl;
	int ti, tj, tdata;
	for (int i = 0; i < c; i++) {
		cin >> ti >> tj >> tdata;
		M.insert(ti, tj, tdata);
	}
	// cout << M.n << " " << M.m << " " << M.cnt << endl;
	M.adjust();
	M.show();
	N = M.qtranspose();
	N.show();
	return 0;
}