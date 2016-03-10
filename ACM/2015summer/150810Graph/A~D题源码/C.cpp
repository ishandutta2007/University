#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 2e5 + 60;
const int M = 6e5+ 600;
const int oo = 0x7fffffff;

vector <int> a[300 * 300];
int n, du[N];
string ans;
char s[6];

void dfs(int now)
{
    while(!a[now].empty()){
        int next = a[now][0];
        a[now][0] = a[now].back(); a[now].pop_back();
        dfs(next);
    }
    ans += now % 256;
}

int main()
{
   //freopen("test.in", "r", stdin);
    ans = "";
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf(" %s", s);
        int st = s[0] * 256 + s[1];
        int ed = s[1] * 256 + s[2];
        a[st].push_back(ed);
        du[ed]++; du[st]--;
    }
    int st = -1, cnt = 0;
    for(int i = 0; i < 256 * 256; i++)
        if(du[i] < 0){
            cnt++; st = i;
    }
    if(cnt > 1 || du[st] < -1){
        printf("NO\n");
        return 0;
    }
    if(st == -1)
        for(int i = 0; i < 256 * 256; i++)  //找一个搜索起点
        if(a[i].size() > 0) {
            st = i; break;
        }
    dfs(st);
    ans += st / 256;
//    cout << ans << endl;
    if(ans.length() == n + 2){
        printf("YES\n");
        int len = ans.length();
        for(int i = len - 1; i >= 0; i--)
            printf("%c", ans[i]);
        cout << endl;
    }
    else
        printf("NO\n");
}
