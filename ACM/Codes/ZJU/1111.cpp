#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Hand{
public:
	int rank[20], cnt_rank, level;
	vector<int>card[16];
	void clear()
	{
		memset(rank, 0, sizeof(rank));
		for(int i = 0; i < 16; i++)
			card[i].clear();
		cnt_rank = level = 0;
	}
};

typedef struct Hand hand;

char ss[10][4];
map<char, int>suit, pt;


void init(hand& A)
{
	A.clear();
	int id, color;
	for(int i = 0; i < 5; i++)
	{
		id = pt[ss[i][0]];
		color = suit[ss[i][1]];
		A.card[id].push_back(color);
	}
	for(int i = 0; i < 16; i++)if(A.card[i].size() > 1)
	{
		sort(A.card[i].begin(), A.card[i].end());
	}
}

int issstrait(hand A)
{
	for(int i = 2; i + 4 <= 14; i++)
	{
		if(A.card[i].size() == 1 && A.card[i+1].size() == 1 && A.card[i+2].size() == 1 && A.card[i+3].size() == 1 && A.card[i+4].size() == 1)
			return i + 4;
	}
	return -1;
}

int samecolor(hand A)
{
	int color = -1;

	for(int i = 2; i <= 14; i ++)if(A.card[i].size() > 0)
	{
		if(A.card[i].size() > 1)
			return -1;

		if(color == -1)
			color = A.card[i][0];

		else
		{
			if(color != A.card[i][0])
				return -1;
		}

	}
	return color;
}

bool rank1(hand& A)
{
	int high = issstrait(A), color = samecolor(A);

	if(high > 0 && color > 0)
	{
		A.level = 1;
		A.cnt_rank = 1;
		A.rank[1] = high;
		return true;
	}
	return false;
}

bool rank2(hand& A)
{
	for(int i = 2; i <= 14; i++)if(A.card[i].size() == 4)
	{
		A.level = 2;
		A.cnt_rank = 1;
		A.rank[1] = i;
		return true;
	}
	return false;
}

bool rank3(hand& A)
{
	bool tre = false, dou = false;
	int high = 0;

	for(int i = 2; i <= 14; i++)
	{
		if(A.card[i].size() == 2)
		{
			dou = true;
		}
		else if(A.card[i].size() == 3)
		{
			tre = true;
			high = i;
		}
	}

	if(tre && dou)
	{
		A.level = 3;
		A.cnt_rank = 1;
		A.rank[1] = high;
		return true;
	}
	return false;
}

bool rank4(hand& A)
{
	int color = samecolor(A);
	if(color < 2) return false;


	A.level = 4;
	A.cnt_rank = 0;
	for(int i = 2; i <= 14; i++)if(A.card[i].size())
	{
		A.rank[++A.cnt_rank] = i;
	}
	return true;
}

bool rank5(hand& A)
{
	int high = issstrait(A);

	if(high < 2) return false;

	A.level = 5;
	A.cnt_rank = 1;
	A.rank[1] = high;
	return true;
}

bool rank6(hand& A)
{
	for(int i = 2; i <= 14; i++)
	{
		if(A.card[i].size() == 3)
		{
			A.level = 6;
			A.cnt_rank = 1;
			A.rank[1] = i;
			return true;
		}
	}

	return false;
}

bool rank7(hand& A)
{
	vector<int>v;
	v.clear();
	int rest;

	for(int i = 2; i <= 14; i++)
	{
		int n = A.card[i].size();
		if(n == 2) v.push_back(2);
		else if(n == 1) rest = i;
	}

	if(v.size() == 2)
	{
		A.level = 7;
		A.cnt_rank = 3;
		A.rank[1] = max(v[0], v[1]);
		A.rank[2] = min(v[0], v[1]);
		A.rank[3] = rest;
		return true;
	}
	return false;
}

bool rank8(hand& A)
{
	bool dou = false;
	int id = 0;
	for(int i = 2; i <= 14; i++)
	{
		if(A.card[i].size() == 2)
		{
			dou = true;
			id = i;
			break;
		}
	}

	if(!dou) return false;

	A.level = 8;
	A.cnt_rank = 1;
	A.rank[1] = id;

	for(int i = 14; i >=2 ; i--)
	{
		if(A.card[i].size() == 1)
		{
			A.rank[++A.cnt_rank] = i;
		}
	}
	return true;
}

bool rank9(hand& A)
{
	A.level = 9;
	A.cnt_rank = 0;
	for(int i = 14; i >= 2; i--)if(A.card[i].size() == 1)
	{
		A.rank[++A.cnt_rank] = i;
	}
	return true;
}




void getrank(hand& A)
{
	if(rank1(A)) return;
	if(rank2(A)) return;
	if(rank3(A)) return;
	if(rank4(A)) return;
	if(rank5(A)) return;
	if(rank6(A)) return;
	if(rank7(A)) return;
	if(rank8(A)) return;
	if(rank9(A)) return;
}


void showrank(hand A)
{
	cout << A.level << endl;

	for(int i = 1; i <= A.cnt_rank; i++)
		cout << A.rank[i] << " " ;

	cout << endl;

}



int main()
{
	
	for(int i = 2; i < 10; i++)
		pt[i+'0'] = i;
	pt['T'] = 10;
	pt['J'] = 11;
	pt['Q'] = 12;
	pt['K'] = 13;
	pt['A'] = 14;
	suit['C'] = 1;
	suit['D'] = 2;
	suit['H'] = 3;
	suit['S'] = 4;


	hand black, white;
	while(scanf("%s", ss[0]) != EOF)
	{
		for(int i = 1; i < 5; i++)
			scanf("%s", ss[i]);
		init(black);
		for(int i = 0; i < 5; i++)
			scanf("%s", ss[i]);
		init(white);


		getrank(black);
		getrank(white);


		// showrank(black);
		// showrank(white);

		if(black.level < white.level)
		{
			printf("Black wins.\n");
			continue;
		}
		else if(black.level > white.level)
		{
			printf("White wins.\n");
			continue;
		}
		else
		{
			int  tie = 0;
			int n = black.cnt_rank;
			for(int i = 1; i <= n; i++)
			{
				if(black.rank[i] == white.rank[i]) continue;

				if(black.rank[i] > white.rank[i])
					tie = 1;
				else
					tie = -1;
				break;
			}

			if(tie == 1)
			{
				printf("Black wins.\n");
			}
			else if(tie == -1)
			{
				printf("White wins.\n");
			}
			else
			{
				printf("Tie.\n");
			}
			continue;
		}
	}

	return 0;
}