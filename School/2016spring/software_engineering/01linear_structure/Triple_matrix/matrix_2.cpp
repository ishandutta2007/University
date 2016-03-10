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

	void tsort() {
		vector<Triple> MM[1000];
		for (int i = 0; i < cnt; i++)
			MM[matrix[i].i].push_back(matrix[i]);
		matrix.clear();
		Triple tmp[1000], zero = Triple(0,0,0);
		for (int i = 1; i <= n; i++) if(MM[i].size() > 0)
		{

			for (int j = 1; j <= m; j++)
				tmp[j] = zero;

			int len = MM[i].size();
			for(int j = 0; j < len; j++)
			{
				tmp[MM[i][j].j] = MM[i][j];
			}
			for (int j = 1; j <= m; j++)if(tmp[j].data != 0)
				matrix.push_back(tmp[j]);
		}



	}

	void init()
	{
		scanf("%d%d%d", &n, &m, &cnt);
		int x, y, z;
		for(int i = 0; i < cnt; i++) {
			scanf("%d%d%d", &x, &y, &z);
			matrix.push_back(Triple(x, y, z));
		}


	}




	void setnm(int n, int m) {
		this->n = n;
		this->m = m;
	}
	void insert(int i, int j, int data) {
		matrix.push_back(Triple(i, j, data));
		cnt++;
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

	// int n, m, c;
	// cin >> n >> m >> c;
	// int ti, tj, tdata;
	// for (int i = 0; i < c; i++) {
	// 	cin >> ti >> tj >> tdata;
	// 	M.insert(ti, tj, tdata);
	// }
	// M.adjust();
	// M.show();
	// M.transpose();
	// M.show();


	M.init();
	M.tsort();
	M.show();


	return 0;
}