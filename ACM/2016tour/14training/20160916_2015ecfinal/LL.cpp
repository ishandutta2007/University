#include <bits/stdc++.h>
#define maxn 2200
using namespace std;
int a[maxn][maxn];
struct tii
{
	int x, y, v;
};
typedef long long LL;
vector<tii> q;
int n,m;

bool flag;
char bf[20];
inline int read() {
    scanf("%s", bf);  
    if (bf[0] == '?') return -1;
    int tmp = 0;
    for (int i = 0, len = strlen(bf); i < len; i++)
      tmp = tmp*10 + (bf[i]-'0');
    return tmp;
}

int judge(int x, int y)
{
	int ss=q.size();
	for (int i=0;i<ss;i++){
		LL xx=q[i].x-q[0].x+x, yy=q[i].y-q[0].y+y;
		if (xx <= 0 || yy <= 0 || xx*yy!=q[i].v) return 0;
	}
	return 1;
}

int main()
{
	int Case;
  Case = read();
	for (int o=1;o<=Case;o++)
	{
    n = read();
    m = read();
		int x; q.clear();
		flag=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				x=read();
				if (x>0) q.push_back((tii){i, j, x});
			}
		if (q.size()==0) {
			flag=1;
		}
		// else if (q.size()==1){
		// 	flag=0;
		// 	for (int i=1;i*i<=q[0].v;i++)
		// 		if (q[0].v%i==0)
		// 		{
		// 			int j=q[0].v/i;
		// 			if (i>=q[0].x && j>=q[0].y) {
		// 				flag=1; break;
		// 			}
		// 			if (i==j) continue;
		// 			if (i>=q[0].y && j>=q[0].x) {
		// 				flag=1; break;
		// 			}
		// 		}
		// }
		else{
			flag=0;
			for (int i=1;i*i<=q[0].v;i++) if (q[0].v%i == 0)
      {
        int j=q[0].v/i;
        if (i>=q[0].x && j>=q[0].y && judge(i, j)){
          flag=1;
          break;
        }
        if (j>=q[0].x && i>=q[0].y && judge(j, i)){
          flag=1;
          break;
        }
			}
		}
		printf("Case #%d: %s\n", o, flag?"Yes":"No");
	}
	return 0;
}
// 2 2
// 998001 ?
// ? 1000000
