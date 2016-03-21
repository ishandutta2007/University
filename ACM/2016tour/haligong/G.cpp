#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
	int index, score, ab;
	Node(){}
	Node(int i, int s, int a):index(i),score(s),ab(a){}
	bool operator < (Node a) const
	{
		if(score == a.score) return index < a.index;
		else return score > a.score;
	}
	void show()
	{
		cout << index << " " << score << " " << ab << endl;
	}
};

Node vn[200020], tmp1[200020], tmp2[200020];
int n, r, q;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &r, &q);
		for (int i = 1; i <= n * 2; i++) {
			vn[i].index = i;
			scanf("%d", &vn[i].score);
		}
		for (int i = 1; i <= n * 2; i++)
			scanf("%d", &vn[i].ab);

		sort(vn + 1, vn + 2 * n + 1);

		while(r--)
		{
			for (int i = 1; i <= n; i++)
			{
				if(vn[i*2-1].ab > vn[i*2].ab) {
					tmp1[i] = vn[i*2-1];
					tmp2[i] = vn[i*2];
				} else {
					tmp1[i] = vn[i*2];
					tmp2[i] = vn[i*2-1];
				}
				tmp1[i].score++;
			}
			int p1 = 1, p2 = 1, p = 0;
			while(p1 <= n && p2 <= n)
			{
				if(tmp1[p1] < tmp2[p2])
					vn[++p] = tmp1[p1++];
				else
					vn[++p] = tmp2[p2++];
			}

			while(p1 <= n)
				vn[++p] = tmp1[p1++];
			while(p2 <= n)
				vn[++p] = tmp2[p2++];
		}

		printf("%d\n", vn[q].index);

	}


	return 0;
}