#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;
typedef long long LL;
const int N = 11;
LL f[N+1][1<<N], d;
int n, m; int i; int s1;

void dfs(int j, int s2){

    if (j == m) {
        f[i+1][s2] += d;
    }
    else{
        dfs(j+1, s2 ^ (1 << j)); // 竖放，或者不放
        if (j+1<m &&!(s1 &(3 << j)))dfs(j+2, s2); // 横着放
    }
}


int main(){

    while (cin >> n >> m && n){

        memset(f, 0, sizeof(f)); f[0][0] = 1;

        for (i=0;i<n;++i){
            for (int s=0;s<1<<m;++s) if (f[i][s]){
                d=f[i][s]; s1 = s;
                dfs(0,s1);
            }
        }

        cout << f[n][0] << endl;
        //cout << f[n][ (1<<m) - 1] << endl;
        //cout << f[n-1][ (1<<m) - 1] << endl;
    }

}
