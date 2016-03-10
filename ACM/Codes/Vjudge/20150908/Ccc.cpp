#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;
typedef long long LL;
const int N = 11;
LL f[2][1<<N], d;
int n, m;

int main(){

    while (cin >> n >> m && n){

        int p = 0, q = 1;
        memset(f[p], 0, sizeof(f[p]));
        f[p][0] = 1;

        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                swap(p, q); memset(f[p], 0, sizeof(f[p]));
                for (int s=0;s<1<<m;++s){
                    LL u = f[q][s];
                    f[p][s^(1<<j)] += u; // 竖着放，不放
                    if (j && s&(1<<(j-1)) && !(s&(1<<j)))
                    {
                        f[p][s] += u;
                        f[p][s^(3<<(j-1))] += u;
                        f[p][s^(1<<(j-1))] += u; // 横着放
                    }
                    if (j && s&(1<<(j-1)) && !(s&(1<<j)))
                    {
                        f[p][s^(1<<(j))] += u;
                    }
                    if (j && s&(1<<(j)) && !(s&(1<<(j+1))))
                    {
                        f[p][s^(1<<(j+1))] += u;
                    }
                }
            }
        }

        cout << f[p][0] << endl;

    }

}
