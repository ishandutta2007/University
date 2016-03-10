#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 5e6 + 60;
const int M = 6e5+ 600;
const int oo = 0x7fffffff;

char A[16], B[16];
int x, y, tot, fa[N], du[N];
struct Node {
    Node * Next[27];
    int ID;
    Node(){
        for(int i = 0; i < 26; i++) Next[i] = NULL;
        ID = -1;
    }
}*Root;

int Trie(char s[])      //通过字典树将string映射为int
{
    int len = strlen(s);
    Node* now = Root;
    for(int i = 0; i < len; i++){
        if(now->Next[s[i] - 'a'] == NULL)
            now->Next[s[i] - 'a'] = new Node();
        now = now->Next[s[i] - 'a'];
    }
    if(now->ID == -1) now->ID = ++tot;
    if(fa[tot] == 0) fa[tot] = tot;
    return now->ID;
}
int father(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = father(fa[x]);
}


int main()
{
  // freopen("test.in", "r", stdin);

    tot = 0; Root = new Node();
    while(scanf(" %s %s", A, B)!= EOF){
        x = Trie(A);
        y = Trie(B);
//        cout << x << " " << A <<endl;
//        cout << y << " " << B <<endl;
        int fx = father(x);
        int fy = father(y);

        if(fx != fy) fa[fx] = fy;
        du[x]++; du[y]++;
    }
    int TopFa = father(1);
    for(int i = 2; i <= tot; i++){  //判断图是否连通
        int fx = father(i);
        if(fx != TopFa){
            printf("Impossible\n");
            return 0;
        }
    }

    int cnt = 0;
    for(int i = 1; i <= tot; i++)
        if(du[i] & 1) cnt++;

    if(cnt == 2 || cnt == 0)
        printf("Possible\n");
    else
        printf("Impossible\n");
}
