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
};


class Matrix {
private:
	int n, m;	//matrix n * m;
	int cnt;
	vector<Triple> matrix;
public:
	void setnm(int n, int m) {
		this->n = n;
		this->m = m;
	}
	void insert(int i, int j, int data) {
		matrix.push_back(Triple(i, j, data));
		cnt++;
	}
	void tsort() {
		sort(matrix.begin(), matrix.end());
	}
	void adjust() {
		tsort();
		cnt = matrix.size();
	}
	void transpose() {
		for (int i = 0, len = matrix.size(); i < len; i++) {
			swap(matrix[i].i, matrix[i].j);
		}
		tsort();
	}
	void show() {
		for (int i = 0, len = matrix.size(); i < len; i++) {
			matrix[i].show();
		}
	}
}M;

int main()
{

	int n, m, c;
	cin >> n >> m >> c;
	int ti, tj, tdata;
	for (int i = 0; i < c; i++) {
		cin >> ti >> tj >> tdata;
		M.insert(ti, tj, tdata);
	}
	M.adjust();
	M.show();
	M.transpose();
	M.show();
	return 0;
}