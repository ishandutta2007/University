#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>


using namespace std;

vector<int>v;
int a[8020];
int ans[8020];

int main(){


    int n;
    while(scanf("%d", &n) != EOF){
        v.clear();
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i <= n; i++) v.push_back(i);
        for(int i = 2; i <= n; i++) scanf("%d", &a[i]);
        for(int i = n; i >= 1; i--){
            ans[i] = v[a[i]];
            v.erase(v.begin() + a[i]);
        }
        for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);

    }





    return 0;
}
